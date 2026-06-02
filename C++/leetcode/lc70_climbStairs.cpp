#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

namespace lc70 {

class Solution {
public:
  int climbStairs(int n) { 
    if (n <= 2) {
      return n;
    }

    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int step = 3; step <= n; step++) {
      dp[step] = dp[step - 1] + dp[step - 2];
    }

    return dp[n];
  }
};
} // namespace lc70

int main() {
  int n = 3;
  lc70::Solution s;
  cout << "nums: " << s.climbStairs(n) << endl;
}