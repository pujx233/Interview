package lc560;

import java.util.HashMap;
import java.util.Map;

class Solution {
  public int subarraySum(int[] nums, int k) {
    Map<Integer, Integer> prefixSumCount = new HashMap<>();
    prefixSumCount.put(0, 1);
    int cnt = 0;
    int currentSum = 0;
    for (int num : nums) {
      currentSum += num;
      int reserve = currentSum - k;
      if (prefixSumCount.containsKey(reserve)) {
        cnt += prefixSumCount.get(reserve);
      }

      prefixSumCount.put(currentSum, prefixSumCount.getOrDefault(currentSum, 0) + 1);
    }
    return cnt;
  }
}

public class subarraySum {

}
