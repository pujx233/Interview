#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace lc39 {

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    backtrack(result, path, candidates, target, 0);

    return result;
  }

  void backtrack(vector<vector<int>>& result, vector<int>& path, vector<int>& candidates,
    int target, int startIndex) {
    if (target == 0) {
      result.push_back(path);
      return;
    }
    for (int i = startIndex; i < candidates.size(); ++i) {
      if (target - candidates[i] < 0) {
        break;
      }
      path.push_back(candidates[i]);
      backtrack(result, path, candidates, target - candidates[i], i);
      path.pop_back();
    }
  }
};
}

void printResult(const std::vector<std::vector<int>>& result) {
  std::cout << "[" << std::endl;
  for (const auto& combination : result) {
    std::cout << "  [";
    for (size_t i = 0; i < combination.size(); ++i) {
      std::cout << combination[i] << (i == combination.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
  }
  std::cout << "]" << std::endl;
}

int main() {
  lc39::Solution solution;
  std::vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  printResult(solution.combinationSum(candidates, target));
}