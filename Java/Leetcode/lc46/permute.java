package lc46;

import java.util.ArrayList;
import java.util.List;

class Solution {
  List<List<Integer>> ans = new ArrayList<>();
  public List<List<Integer>> permute(int[] nums) {
    List<Integer> res = new ArrayList<>();
    backtrack(nums, res);
    return ans;
  }

  void backtrack(int[] nums, List<Integer> res) {
    if (res.size() == nums.length) {
      ans.add(new ArrayList<>(res));
      return;
    }

    for (int num : nums) {
      if (res.contains(num)) {
        continue;
      }
      res.add(num);
      backtrack(nums, res);
      res.remove(res.size() - 1);
    }
  }
}

public class permute {
}
