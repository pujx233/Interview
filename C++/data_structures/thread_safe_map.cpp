#include <unordered_map>
#include <string>
#include <mutex>
#include <cstdint>
#include <iostream> // main 函数需要
namespace interview {
class thread_safe_map {
private:
  std::unordered_map<int32_t, std::string> map;
  mutable std::mutex mtx;

public:
  thread_safe_map() {}

  void insert(int32_t key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mtx);
    map[key] = value;
  }

  /**
   * @brief C++11 风格的 get 方法
   * @param key 要查找的键
   * @param value [out] 如果找到，值会被存放在这个变量里
   * @return 如果键存在则返回 true, 否则返回 false
   */
  bool get(int32_t key, std::string& value) const { // 注意第二个参数是 string 的引用
    std::lock_guard<std::mutex> lock(mtx);
    auto it = map.find(key);
    if (it == map.end()) {
      return false; // 未找到，返回 false
    } else {
      value = it->second; // 找到了，把值赋给输出参数
      return true;        // 返回 true
    }
  }
};

}

// --- 如何使用 C++11 风格的 get 方法 ---
int main() {
  interview::thread_safe_map safe_map;
  safe_map.insert(1, "Hello");
  safe_map.insert(2, ""); // 插入一个值为空字符串的键

  std::string result_value; // 准备一个变量来接收结果

  // Case 1: 键存在
  if (safe_map.get(1, result_value)) {
    std::cout << "键 1 存在，值为: " << result_value << std::endl;
  }

  // Case 2: 键存在，但值为空字符串
  if (safe_map.get(2, result_value)) {
    std::cout << "键 2 存在，值为: \"" << result_value << "\"" << std::endl;
  } else {
    std::cout << "键 2 未找到。" << std::endl;
  }

  // Case 3: 键不存在
  if (safe_map.get(3, result_value)) {
    std::cout << "键 3 存在，值为: " << result_value << std::endl;
  } else {
    std::cout << "键 3 未找到。" << std::endl;
  }

  return 0;
}