#include "iostream"
#include "vector"

using namespace std;

namespace lc79 {

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    if (board.empty() || board[0].empty()) {
      return false;
    }
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (dfs(board, word, visited, i, j, 0)) {
          return true;
        }
      }
    }

    return false;
  }

private:
  bool dfs(const vector<vector<char>> &board, const string &word,
           vector<vector<bool>> &visited, int row, int col, int index) {
    if (index == word.size()) {
      return true;
    }
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
        visited[row][col] || board[row][col] != word[index]) {
      return false;
    }

    visited[row][col] = true;
    bool found = dfs(board, word, visited, row + 1, col, index + 1) ||
                 dfs(board, word, visited, row - 1, col, index + 1) ||
                 dfs(board, word, visited, row, col + 1, index + 1) ||
                 dfs(board, word, visited, row, col - 1, index + 1);
    visited[row][col] = false;
    return found;
  }
};
} // namespace lc79

int main() {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "ABCCED";
  cout << lc79::Solution().exist(board, word) << endl;
}