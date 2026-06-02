#pragma once
#include "algorithm"
#include "iostream"
#include "vector"

using namespace std;

namespace lc279 {
class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, n);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j * j <= i; j++) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }

    return dp[n];
  }
};
} // namespace lc270

int main() {
  int n = 13;
  lc279::Solution s;
  cout << "result" << s.numSquares(n) << endl;
}