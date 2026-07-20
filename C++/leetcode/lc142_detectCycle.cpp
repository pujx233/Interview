#include <LinkedListUtils.h>
#include <iostream>
#include <vector>

using namespace std;

namespace lc142 {
class Solution {
public:
  // 返回链表的环入口节点，无环时返回 nullptr
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    // 第一阶段：判断是否有环
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        // 第二阶段：寻找环入口
        ListNode *entry = head;

        while (entry != slow) {
          entry = entry->next;
          slow = slow->next;
        }

        return entry;
      }
    }

    return nullptr;
  }
};

} // namespace lc142

int main() {
  lc142::Solution solution;
  vector<int> nums{3, 2, 0, -4};
  int pos = 1;
  ListNode *list = LinkedListUtils::createLinkedListWithCycle(nums, pos);
  ListNode *cycleEntry = solution.detectCycle(list);

  if (cycleEntry != nullptr) {
    cout << cycleEntry->val << endl;
  } else {
    cout << "nullptr" << endl;
  }
}
