package lc32;

class Solution {
  public int longestValidParentheses(String s) {
    if (s == null || s.length() < 2) {
      return 0;
    }
    int maxLength = 0;
    int[] dp = new int[s.length()];

    for (int i = 1; i < s.length(); i++) {
      if (s.charAt(i) == ')') {
        if (s.charAt(i - 1) == '(') {
          dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        } else if (i - dp[i - 1] > 0 && s.charAt(i - dp[i - 1] - 1) == '(') {
          dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0);
        }
      }
      maxLength = Math.max(maxLength, dp[i]);
    }
    return maxLength;
  }
}

public class longestValidParentheses {
  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.print(s.longestValidParentheses(")()())"));
  }
}
