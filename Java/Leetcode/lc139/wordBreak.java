package lc139;

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
  public boolean wordBreak(String s, List<String> wordDict) {
    Set<String> wordSet = new HashSet<>(wordDict);
    int n = s.length();
    boolean[] dp = new boolean[n + 1];
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] && wordSet.contains(s.substring(j, i))) {
          dp[i] = true;
          break;
        }
      }
    }
    
    return dp[n];
  }
}

public class wordBreak {
  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.print(s.wordBreak("leetcode",  Arrays.asList("leet", "code")));
  }
}
