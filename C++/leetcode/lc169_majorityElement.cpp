#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace lc169 {
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    if (nums.empty()) {
      return -1;
    }

    int candidate = 0;
    int count = 0;

    for (int num : nums) {
      if (count == 0) {
        candidate = num;
      }

      if (num == candidate) {
        count++;
      } else {
        count--;
      }
    }

    return candidate;
  }
};
}

int main() {
  lc169::Solution s;
  vector<int> nums = {2,2,1,1,1,2,2};
  cout <<  s.majorityElement(nums) << endl;
}
