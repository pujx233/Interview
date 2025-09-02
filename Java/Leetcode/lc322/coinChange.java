package lc322;

import java.util.Arrays;

class Solution {
  public int coinChange(int[] coins, int amount) {
    int[] dp = new int[amount + 1];
    Arrays.fill(dp, amount + 1);
    dp[0] = 0;
    for (int i = 1 ; i < amount + 1; i ++) {
      for (int coin : coins) {
        if (i >= coin) {
          dp[i] = Math.min(dp[i], dp[i - coin] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];

  }
}

public class coinChange {

  public static void main(String[] args) {
    Solution solution = new Solution();
    int[] coins = new int[] {1, 2, 5};
    int amount = 11;
    System.out.println(solution.coinChange(coins, amount));
  }
}
