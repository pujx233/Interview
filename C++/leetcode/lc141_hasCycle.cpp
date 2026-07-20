#include <LinkedListUtils.h>
#include <iostream>
#include <vector>
using namespace std;
namespace lc141 {
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};

} // namespace lc141

int main() {
  lc141::Solution solution;
  vector<int> nums{3, 2, 0, -4};
  int pos = 1;
  ListNode *list = LinkedListUtils::createLinkedListWithCycle(nums, pos);
  cout << solution.hasCycle(list) << '\n';
}
