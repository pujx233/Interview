#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

namespace lc75 {

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int p0 = 0;
    int curr = 0;
    int p2 = nums.size() - 1;

    while (curr <= p2) {
      if (nums[curr] == 0) {
        std::swap(nums[curr], nums[p0]);
        p0++;
        curr++;
      } else if (nums[curr] == 2) {
        std::swap(nums[curr], nums[p2]);
        p2--;
        // 注意：curr 不增加，因为换过来的元素需要再次判断
      } else { // nums[curr] == 1
        curr++;
      }
    }
  }
};

}

int main() {
  vector<int> nums = {2,0,2,1,1,0};
  lc75::Solution s;
  s.sortColors(nums);
}