package lc42;

class Solution {
  public int trap(int[] height) {
    if (height == null || height.length <= 2) {
      return 0;
    }
    int n = height.length;

    // 1. 找到全局最高柱子的索引
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
      if (height[i] > height[maxIndex]) {
        maxIndex = i;
      }
    }

    int totalWater = 0;

    // 2. 处理左半部分 [0 -> maxIndex]
    int maxLeft = 0;
    for (int i = 0; i < maxIndex; i++) {
      if (height[i] > maxLeft) {
        maxLeft = height[i];
      } else {
        totalWater += maxLeft - height[i];
      }
    }

    // 3. 处理右半部分 [n-1 -> maxIndex]
    int maxRight = 0;
    for (int i = n - 1; i > maxIndex; i--) {
      if (height[i] > maxRight) {
        maxRight = height[i];
      } else {
        totalWater += maxRight - height[i];
      }
    }

    return totalWater;
  }

}

public class trap {
  public static void main(String[] args) {
    Solution solution = new Solution();

    System.out.print(solution.trap(new int[] {0,1,0,2,1,0,1,3,2,1,2,1}));
  }
}
