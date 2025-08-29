#pragma once
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "TreeUtils.h"
using namespace std;

namespace lc105 {
class Solution {
public:

  unordered_map<int, int> inorder_map;


  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty()) {
      return nullptr;
    }

    for (int i = 0; i < inorder.size(); ++i) {
      inorder_map[inorder[i]] = i;
    }
    return build(preorder, 0, preorder.size() - 1,
                      inorder, 0, inorder.size() - 1);
  }

  TreeNode* build(const std::vector<int>& preorder, int pre_left, int pre_right,
                  const std::vector<int>& inorder, int in_left, int in_right) {
    // 递归终止条件
    if (pre_left > pre_right || in_left > in_right) {
      return nullptr;
    }

    // 1. 创建根节点 (前序遍历的第一个元素)
    int root_val = preorder[pre_left];
    TreeNode* root = new TreeNode(root_val);

    // 2. 在中序遍历中找到根节点的位置
    int in_root_index = inorder_map[root_val];

    // 3. 计算左子树的节点数量
    int left_subtree_size = in_root_index - in_left;

    // 4. 递归构建左右子树
    // 构建左子树
    root->left = build(preorder, pre_left + 1, pre_left + left_subtree_size,
                       inorder, in_left, in_root_index - 1);

    // 构建右子树
    root->right = build(preorder, pre_left + left_subtree_size + 1, pre_right,
                        inorder, in_root_index + 1, in_right);

    return root;
  }
};
}

int main() {
  std::vector<int> preorder = {3, 9, 20, 15, 7};
  std::vector<int> inorder = {9, 3, 15, 20, 7};
  lc105::Solution sol;
  TreeNode* root = sol.buildTree(preorder, inorder);
  TreeUtils::printTree(root);
}