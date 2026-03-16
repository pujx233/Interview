#pragma once
#include <LinkedListUtils.h>
#include <vector>

using namespace std;

namespace lc211 {
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode * prev = nullptr;
    auto cur = head;
    while (cur != nullptr) {
      auto temp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = temp;
    }
    return prev;
  }
};
}

int main() {
  lc211::Solution solution;
  vector<int> nums {1, 2, 3,4, 5};
  ListNode * list_node = LinkedListUtils::createLinkedList(nums);
  LinkedListUtils::printLinkedList(solution.reverseList(list_node));
}
