package lc41;

class Solution {
  public int firstMissingPositive(int[] nums) {
    int n = nums.length;

    // 步骤一：原地交换，将数字 k 放到下标 k-1 的位置
    for (int i = 0; i < n; i++) {
      // 当 nums[i] 在 [1, n] 范围内，且没有在正确的位置上时，进行交换
      // nums[i] != nums[nums[i] - 1] 是为了防止死循环
      // 例如当 nums = [1, 1, 2] 时，第二个 1 如果没有这个判断就会和自己无限交换
      while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      }
    }

    // 步骤二：遍历查找第一个不在正确位置上的数
    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    // 步骤三：如果 [1, n] 都存在，那么缺失的就是 n + 1
    return n + 1;
  }

  private void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}

public class firstMissingPositive {

  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.print(s.firstMissingPositive(new int[]{-3,5,3}));
  }
}
