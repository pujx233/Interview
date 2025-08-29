package lc128;

import java.util.HashSet;
import java.util.Set;

class Solution {
  public int longestConsecutive(int[] nums) {
    // 1. 使用 HashSet 存储所有数字，以便 O(1) 查找
    Set<Integer> numSet = new HashSet<>();
    for (int num : nums) {
      numSet.add(num);
    }

    int longestStreak = 0;

    // 2. 遍历集合中的每一个数字
    for (int num : numSet) {
      // 3. 关键：只对序列的起点进行处理
      // 如果 num-1 存在，说明 num 不是起点，直接跳过
      if (!numSet.contains(num - 1)) {

        // 4. 从起点开始，计算当前序列的长度
        int currentNum = num;
        int currentStreak = 1;

        // 循环查找下一个连续的数是否存在
        while (numSet.contains(currentNum + 1)) {
          currentNum += 1;
          currentStreak += 1;
        }

        // 5. 更新最大长度
        longestStreak = Math.max(longestStreak, currentStreak);
      }
    }

    return longestStreak;
  }
}

public class longestConsecutive {
}

