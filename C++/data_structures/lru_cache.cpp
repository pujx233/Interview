#include <iostream>
#include <unordered_map>

// 双向链表的节点
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, Node*> cacheMap;
    Node* head; // 虚拟头节点
    Node* tail; // 虚拟尾节点

    // 辅助函数：将一个节点移动到链表头部（即虚拟头节点之后）
    void add_to_head(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // 辅助函数：从链表中移除一个节点
    void remove_node(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    // 构造函数
    LRUCache(int capacity) {
        this->capacity = capacity;
        // 创建虚拟头节点和尾节点
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        // 初始化链表，将头尾相连
        head->next = tail;
        tail->prev = head;
    }

    // 析构函数，释放所有动态分配的内存
    ~LRUCache() {
        Node* current = head->next;
        while (current != tail) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
        delete tail;
    }

    // 获取缓存中的值
    int get(int key) {
        // 1. 在哈希表中查找键
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1; // 未找到
        }

        // 2. 找到节点
        Node* node = cacheMap[key];

        // 3. 将该节点从当前位置移除
        remove_node(node);

        // 4. 将该节点重新添加到链表头部（表示最近使用）
        add_to_head(node);

        return node->value;
    }

    // 存入键值对
    void put(int key, int value) {
        // 1. 检查键是否已存在
        if (cacheMap.find(key) != cacheMap.end()) {
            // 键已存在：
            Node* node = cacheMap[key];
            node->value = value; // 更新值
            remove_node(node);    // 移除旧位置
            add_to_head(node);    // 添加到头部
        } else {
            // 键不存在：

            // 2. 检查缓存是否已满
            if (cacheMap.size() >= capacity) {
                // 容量已满，需要淘汰最近最少使用的元素
                Node* lru_node = tail->prev; // LRU 节点是虚拟尾节点的前一个
                cacheMap.erase(lru_node->key); // 从哈希表中移除
                remove_node(lru_node);         // 从链表中移除
                delete lru_node;               // 释放内存
            }

            // 3. 创建新节点并添加到缓存
            Node* newNode = new Node(key, value);
            cacheMap[key] = newNode;  // 更新哈希表
            add_to_head(newNode);     // 添加到链表头部
        }
    }
};

// 示例用法
int main() {
    LRUCache lruCache(2);

    lruCache.put(1, 1);
    lruCache.put(2, 2);
    std::cout << "get(1): " << lruCache.get(1) << std::endl; // 输出 1

    lruCache.put(3, 3);
    std::cout << "get(2): " << lruCache.get(2) << std::endl; // 输出 -1 (2被淘汰)

    lruCache.put(4, 4);
    std::cout << "get(1): " << lruCache.get(1) << std::endl; // 输出 -1 (1被淘汰)
    std::cout << "get(3): " << lruCache.get(3) << std::endl; // 输出 3
    std::cout << "get(4): " << lruCache.get(4) << std::endl; // 输出 4

    return 0;
}