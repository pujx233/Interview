#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace lc347 {

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> res;
    return res;
  }
};
} // namespace lc347

int main() {
  lc347::Solution solution;
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  solution.topKFrequent(nums, 2);
}
