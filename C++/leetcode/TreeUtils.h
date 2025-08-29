#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>

// LeetCode 标准二叉树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class TreeUtils {
public:
    // 从 vector 创建二叉树（-1 代表 null）
    static TreeNode* createTree(const std::vector<int>& vals) {
        if (vals.empty() || vals[0] == -1) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(vals[0]);
        std::queue<TreeNode*> q;
        q.push(root);
        size_t i = 1;

        while (!q.empty() && i < vals.size()) {
            TreeNode* current = q.front();
            q.pop();

            // 处理左子节点
            if (i < vals.size() && vals[i] != -1) {
                current->left = new TreeNode(vals[i]);
                q.push(current->left);
            }
            i++;

            // 处理右子节点
            if (i < vals.size() && vals[i] != -1) {
                current->right = new TreeNode(vals[i]);
                q.push(current->right);
            }
            i++;
        }
        return root;
    }

    // 层序遍历打印二叉树
    static void printTree(TreeNode* root) {
        if (!root) {
            std::cout << "[]" << std::endl;
            return;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<std::string> result;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result.push_back(std::to_string(node->val));
                q.push(node->left);
                q.push(node->right);
            } else {
                result.push_back("null");
            }
        }
        
        // 移除末尾多余的 "null"
        while (!result.empty() && result.back() == "null") {
            result.pop_back();
        }

        std::cout << "[";
        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << result[i] << (i == result.size() - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }

    // 销毁二叉树，释放内存
    static void destroyTree(TreeNode* root) {
        if (!root) {
            return;
        }
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
};

