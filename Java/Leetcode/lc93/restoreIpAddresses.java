package lc93;

import java.util.ArrayList;
import java.util.List;

class Solution {
  public List<String> restoreIpAddresses(String s) {
    List<String> result = new ArrayList<>();

    if (s == null || s.length() < 4 || s.length() > 12) {
      return result;
    }


    List<String> path = new ArrayList<>();
    dfs(s, 0, path, result);

    return result;
  }

  private void dfs(String s, int start, List<String> path,  List<String> result) {
    if (path.size() == 4) {
      if (start == s.length()) {
        result.add(String.join(".", path));
      }

      return;
    }

    for (int i = 1; i <= 3 && i + start <= s.length(); i++) {
      String segment = s.substring(start, start + i);
      if (segment.length() > 1 && segment.startsWith("0")) {
        continue;
      }
      if (Integer.parseInt(segment) > 255) {
        continue;
      }
      path.add(segment);
      dfs(s, start + i, path, result);
      path.remove(path.size() - 1);
    }

  }
}

public class restoreIpAddresses {

  public static void main(String[] args) {
    Solution s = new Solution();
    s.restoreIpAddresses("");
    System.out.print(s.restoreIpAddresses("101023"));


  }

}
