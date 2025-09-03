package lc300;

import java.util.Arrays;

class Solution {
  public int lengthOfLIS(int[] nums) {
    if (nums == null || nums.length == 0) {
      return 0;
    }

    int n = nums.length;
    int[] dp = new int[n];
    // 初始化 dp 数组，每个元素自身构成长度为 1 的子序列
    Arrays.fill(dp, 1);

    int maxLen = 1;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        // 如果 nums[i] 可以接在 nums[j] 后面
        if (nums[i] > nums[j]) {
          // 更新 dp[i]
          dp[i] = Math.max(dp[i], dp[j] + 1);
        }
      }
      // 更新全局最大长度
      maxLen = Math.max(maxLen, dp[i]);
    }

    return maxLen;
  }
}

public class lengthOfLIS {
}
