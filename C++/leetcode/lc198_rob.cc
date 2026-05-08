#pragma once

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

namespace lc198 {

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return nums[0];
    }

    vector<int> dp (n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
  }
};
} // namespace lc198

int main() {
  lc198::Solution solution;

  vector<int> nums = {1, 2, 3, 1};
  int k = 3;

  int result = solution.rob(nums);
  cout << "Result" << result;
}
