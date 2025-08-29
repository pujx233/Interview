package lc470;

import java.util.Random;

/**
 * LeetCode 470. 用 Rand7() 实现 Rand10()
 * * 这是一个已经提供的方法，我们不能修改它。
 * 它会等概率返回 1, 2, 3, 4, 5, 6, 7 中的一个。
 */
class SolBase {
  private Random rand = new Random();

  public int rand7() {
    return rand.nextInt(7) + 1;
  }
}

/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
  public int rand10() {
    int ans = 0;
    while (true) {
      int row = rand7() - 1;
      int col = rand7() - 1;
      ans = row * 7 + col;
      if (ans < 40) {

        return ans % 10 + 1;
      }
    }
  }
}

public class rand10 {
}
