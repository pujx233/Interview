#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <stdexcept>
#include <future>

class ThreadPool {
public:
    // 构造函数：启动指定数量的工作线程
    ThreadPool(size_t threads);
    // 析构函数：停止所有线程并等待它们完成
    ~ThreadPool();

    // 提交任务到任务队列，并返回一个 std::future 以获取结果
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) 
        -> std::future<typename std::result_of<F(Args...)>::type>;

private:
    // 工作线程的容器
    std::vector<std::thread> workers;
    // 任务队列
    std::queue<std::function<void()>> tasks;
    
    // 同步原语
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

// 构造函数实现
inline ThreadPool::ThreadPool(size_t threads) : stop(false) {
    for(size_t i = 0; i < threads; ++i) {
        // 创建线程，并将其放入 workers 容器中
        workers.emplace_back([this] {
            // 无限循环，等待并执行任务
            for(;;) {
                std::function<void()> task;
                {
                    // 使用 unique_lock 来管理互斥锁
                    std::unique_lock<std::mutex> lock(this->queue_mutex);
                    
                    // 等待条件：stop 为 true 或 tasks 不为空
                    this->condition.wait(lock, [this]{ return this->stop || !this->tasks.empty(); });
                    
                    // 如果线程池停止且任务队列为空，则退出线程
                    if(this->stop && this->tasks.empty()) {
                        return;
                    }
                    
                    // 获取任务
                    task = std::move(this->tasks.front());
                    this->tasks.pop();
                } // lock 在这里被释放
                
                // 执行任务
                task();
            }
        });
    }
}

// 任务提交函数实现
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) 
    -> std::future<typename std::result_of<F(Args...)>::type> {
    
    using return_type = typename std::result_of<F(Args...)>::type;

    // 创建一个 packaged_task，用于包装任务函数
    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );
        
    // 获取 future，以便将来获取任务结果
    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);

        // 如果线程池已停止，则不允许添加新任务
        if(stop) {
            throw std::runtime_error("enqueue on stopped ThreadPool");
        }

        // 将任务（的 lambda 包装）放入队列
        tasks.emplace([task](){ (*task)(); });
    }
    // 唤醒一个等待的线程
    condition.notify_one();
    return res;
}

// 析构函数实现
inline ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    // 唤醒所有线程
    condition.notify_all();
    // 等待所有线程执行完毕
    for(std::thread &worker: workers) {
        worker.join();
    }
}


// --- main 函数：测试示例 ---
int main() {
    // 创建一个包含4个线程的线程池
    ThreadPool pool(4);

    // 提交多个任务，并保存它们的 future
    std::vector<std::future<int>> results;

    for(int i = 0; i < 8; ++i) {
        results.emplace_back(
            pool.enqueue([i] {
                std::cout << "hello from task " << i << " by thread " << std::this_thread::get_id() << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "goodbye from task " << i << std::endl;
                return i * i;
            })
        );
    }

    // 获取并输出每个任务的结果
    for(auto && result : results) {
        std::cout << "Result: " << result.get() << std::endl;
    }
    
    return 0;
}