package lc226;

import java.util.LinkedList;
import java.util.Queue;
// 标准二叉树节点定义
class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;
  TreeNode(int val) { this.val = val; }
  TreeNode(int val, TreeNode left, TreeNode right) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

// 将数组转换为二叉树的工具类
class TreeUtil {
  /**
   * 根据一个数组构建二叉树（层序遍历表示法）
   * @param arr 数组，其中 null 表示空节点
   * @return 树的根节点
   */
  public static TreeNode buildTree(Integer[] arr) {
    if (arr == null || arr.length == 0 || arr[0] == null) {
      return null;
    }

    TreeNode root = new TreeNode(arr[0]);
    Queue<TreeNode> queue = new LinkedList<>();
    queue.offer(root);
    int i = 1;

    while (!queue.isEmpty() && i < arr.length) {
      TreeNode current = queue.poll();

      // 处理左子节点
      if (arr[i] != null) {
        current.left = new TreeNode(arr[i]);
        queue.offer(current.left);
      }
      i++;

      if (i < arr.length) {
        // 处理右子节点
        if (arr[i] != null) {
          current.right = new TreeNode(arr[i]);
          queue.offer(current.right);
        }
        i++;
      }
    }
    return root;
  }
}

class Solution {
  public TreeNode invertTree(TreeNode root) {
    if (root == null) {
      return null;
    }

    TreeNode invertedLeft = invertTree(root.left);
    TreeNode invertedRight = invertTree(root.right);

    root.left = invertedRight;
    root.right = invertedLeft;

    return root;
  }
}

public class invertTree {
}
