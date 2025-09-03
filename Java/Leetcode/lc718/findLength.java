package lc718;

class Solution {
  public int findLength(int[] nums1, int[] nums2) {
    int m = nums1.length;
    int n = nums2.length;
    int[][] dp = new int[m + 1][n + 1];

    int maxLength = 0;

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }

        if (dp[i][j] > maxLength) {
          maxLength = dp[i][j];
        }
      }
    }
    return maxLength;
  }
}

public class findLength {
  public static void main(String[] args) {
    int[] nums1 = new int[] {1,2,3,2,1};
    int[] nums2 = new int[] {3,2,1,4,7};
    Solution solution = new Solution();
    System.out.println(solution.findLength(nums1, nums2));
  }
}

