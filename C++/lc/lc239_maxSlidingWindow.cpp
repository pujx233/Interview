#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

namespace lc239 {

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty()) return {};
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < nums.size(); ++i) {
      // 1. 入队前的清理：维护单调递减
      // 当新元素 nums[i] 比队尾元素大时，队尾元素就不可能是最大值了
      while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }

      // 2. 当前元素索引入队
      dq.push_back(i);

      // 3. 队首的清理：移除已经滑出窗口的元素
      if (dq.front() <= i - k) {
        dq.pop_front();
      }

      // 4. 记录结果：当窗口形成后，队首就是当前窗口最大值
      if (i >= k - 1) {
        result.push_back(nums[dq.front()]);
      }
    }

    return result;
  }
};

}