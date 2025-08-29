package lc78;

import java.util.ArrayList;
import java.util.List;

class Solution {
  List<List<Integer>> ans;
  List<Integer> path;
  public List<List<Integer>> subsets(int[] nums) {
    ans = new ArrayList<>();
    path = new ArrayList<>();
    backTrack(nums, 0);
    return ans;
  }

  private void backTrack(int[] nums, int startIdx) {
    ans.add(new ArrayList<>(path));
    if (startIdx >= nums.length) {
      return;
    }

    for (int i = startIdx; i < nums.length; i++) {
      path.add(nums[i]);
      backTrack(nums, i + 1);
      path.remove(path.size() - 1);
    }
  }
}

public class subsets {

  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.print(s.subsets(new int[]{1,2,3}));
  }
}
