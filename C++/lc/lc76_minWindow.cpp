#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits> // 用于获取整型最大值

using namespace std;

namespace lc76 {
class Solution {
public:
  string minWindow(string s, string t) {
    return "";
  }
};
}

int main() {
  lc76::Solution solution;

  string s1 = "ADOBECODEBANC";
  string t1 = "ABC";
  string result1 = solution.minWindow(s1, t1);
  cout << "Result: " << result1 << endl;

  return 0;
}
