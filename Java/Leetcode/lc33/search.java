package lc33;

class Solution {
  public int search(int[] nums, int target) {
    int left = 0, right = nums.length;
    int pivot = nums[nums.length - 1];
    while (left < right) {
      int mid = (right - left) / 2 + left;

      if (nums[mid] > pivot) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    int pivotIdx = right;


    left = 0;
    right =  nums.length - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      int realMid = (mid + pivotIdx) %  nums.length;;

      if (nums[realMid] == target) {
        return realMid;
      }

      if (nums[realMid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
}

public class search {
  public static void main(String[] args) {
    Solution s = new Solution();
    s.search(new int[]{4,5,6,7,0,1,2}, 3);
  }
}
