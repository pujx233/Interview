#include <iostream>
#include <vector>

// LeetCode 标准链表节点定义
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListUtils {
public:
  // 从 vector 创建链表
  static ListNode* createLinkedList(const std::vector<int>& vals) {
    if (vals.empty()) {
      return nullptr;
    }
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
      current->next = new ListNode(vals[i]);
      current = current->next;
    }
    return head;
  }

  // 打印链表
  static void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
      std::cout << current->val << " -> ";
      current = current->next;
    }
    std::cout << "nullptr" << std::endl;
  }

  // 销毁链表，释放内存
  static void destroyLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
      ListNode* temp = current;
      current = current->next;
      delete temp;
    }
  }
};
