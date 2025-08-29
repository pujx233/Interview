#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "TreeUtils.h"

using namespace std;

namespace lc240 {
class Solution {
public:
  int sumNumbers(TreeNode* root) {
    return dfs(root, 0);
  }

  int dfs(TreeNode* root, int sum) {
    if (root == nullptr) {
      return 0;
    }
    int new_sum = sum * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr) {
      return new_sum;
    }
    return dfs(root->left, new_sum) + dfs(root->right, new_sum);
  }
};
}

int main() {
  vector<int> tree_data = {4, 9, 0, 5, 1};
  TreeNode* root = TreeUtils::createTree(tree_data);
  lc240::Solution solution;
  std::cout << solution.sumNumbers(root) << std::endl;

}