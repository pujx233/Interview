#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace lc240 {


class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return false;
    }

    int row = matrix.size();
    int col = matrix[0].size();
    int m = 0;
    int n = col - 1;

    while (m < row && n >= 0) {
      if (matrix[m][n] == target) {
        return true;
      } else if (matrix[m][n] > target) {
        n--;
      } else {
        m++;
      }
    }
    return false;
  }
};

}

int main() {
  lc240::Solution solution;
  vector<vector<int>> matrix = {
    {1,  4,  7, 11, 15},
    {2,  5,  8, 12, 19},
    {3,  6,  9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
  };
  solution.searchMatrix(matrix, 4);

}