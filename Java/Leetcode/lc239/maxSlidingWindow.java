package lc239;

import java.util.Deque;
import java.util.LinkedList;

class Solution {
  public int[] maxSlidingWindow(int[] nums, int k) {
    if (nums == null || nums.length == 0 || k <= 0) {
      return new int[0];
    }
    int n = nums.length;
    int[] result = new int[n - k + 1];
    int resultIndex = 0;

    // Deque 中存储的是数组元素的索引
    Deque<Integer> deque = new LinkedList<>();

    for (int i = 0; i < n; i++) {
      // 步骤 A: 移除窗口之外的元素
      // 当队头元素的索引已经不在当前窗口内时，将其移除
      if (!deque.isEmpty() && deque.peekFirst() <= i - k) {
        deque.pollFirst();
      }

      // 步骤 B: 维护队列的单调递减性
      // 从队尾开始，移除所有小于等于当前元素的索引
      while (!deque.isEmpty() && nums[deque.peekLast()] <= nums[i]) {
        deque.pollLast();
      }

      // 步骤 C: 将当前元素的索引加入队尾
      deque.offerLast(i);

      // 步骤 D: 当窗口完全形成后，记录当前窗口的最大值
      // 队头元素就是当前窗口的最大值
      if (i >= k - 1) {
        result[resultIndex++] = nums[deque.peekFirst()];
      }
    }

    return result;
  }
}

public class maxSlidingWindow {
}
