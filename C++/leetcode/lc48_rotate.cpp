#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

namespace lc48 {

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return;
    }
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = i; j < matrix[0].size(); ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    for (int i = 0; i < matrix.size(); ++i) {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};

}

int main() {
  lc48::Solution solution;
  std::vector<std::vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  solution.rotate(matrix);
}