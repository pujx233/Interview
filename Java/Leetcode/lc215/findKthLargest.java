package lc215;

class Solution {
  /**
   * 快速选择算法的入口函数
   * @param nums 数组
   * @param k    第 k 大
   * @return 第 k 大的元素
   */
  public int findKthLargest(int[] nums, int k) {
    if (nums == null || nums.length == 0 || k <= 0 || k > nums.length) {
      throw new IllegalArgumentException("输入参数无效");
    }
    // 第 k 大的元素，在升序排序后的数组中，索引为 nums.length - k
    int targetIndex = nums.length - k;
    return quickSelect(nums, 0, nums.length - 1, targetIndex);
  }

  /**
   * 快速选择的核心逻辑
   * @param arr          数组
   * @param low          当前处理区间的左边界
   * @param high         当前处理区间的右边界
   * @param targetIndex  我们最终要找的元素的目标索引
   * @return 目标索引上的元素
   */
  private int quickSelect(int[] arr, int low, int high, int targetIndex) {
    while (low < high) {
      int pivot = partition(arr, low, high);
      if (pivot == targetIndex) {
        return arr[pivot];
      } else if (pivot > targetIndex) {
        high = pivot - 1;
      } else {
        low = pivot + 1;
      }
    }
    return -1;
  }

  /**
   * 分区函数（Lomuto 分区方案）
   * 选择 arr[high] 作为基准值
   */
  private int partition(int[] arr, int low, int high) {
    // 1. 固定选择区间的最后一个元素作为基准值
    int pivot = arr[high];

    // 2. i 指向下一个“小于pivot”的元素应该存放的位置
    int i = low;

    // 3. 遍历区间（不包括最后的 pivot），将小于 pivot 的元素都移动到左边
    for (int j = low; j < high; j++) {
      if (arr[j] < pivot) {
        swap(arr, i, j);
        i++;
      }
    }

    // 4. 遍历结束后，i 指向的位置就是 pivot 应该在的最终位置
    // 将 pivot (arr[high]) 与 arr[i] 交换
    swap(arr, i, high);

    // 5. 返回 pivot 的最终索引
    return i;
  }

  /**
   * 交换数组中的两个元素
   */
  private void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

public class findKthLargest {
  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.print(s.findKthLargest(new int[]{3, 2, 1, 5, 6, 4}, 2));
  }
}
