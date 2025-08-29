package lc739;

import java.util.Arrays;
import java.util.Stack;

class Solution {
  public int[] dailyTemperatures(int[] temperatures) {
    int n = temperatures.length;
    int[] answer = new int[n];
    Stack<Integer> stack = new Stack<>();
    for (int i = 0; i < n; i++) {
      while (!stack.isEmpty() && temperatures[stack.peek()] < temperatures[i]) {
        int idx = stack.pop();
        answer[idx] = i - idx;
      }
      stack.push(i);
    }

    return answer;
  }
}

public class dailyTemperatures {

  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.print(Arrays.toString(s.dailyTemperatures(new int[]{73, 74, 75, 71, 69, 72, 76, 73})));
  }
}
