package lc124;

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
  int maxSum = Integer.MIN_VALUE;
  public int maxPathSum(TreeNode root) {
    maxGain(root);
    return maxSum;
  }

  private int maxGain(TreeNode node) {
    if (node == null) {
      return 0;
    }

    // 2. 递归计算左右子树的最大贡献值
    // 如果子树贡献为负，则舍弃，计为0
    int leftGain = Math.max(0, maxGain(node.left));
    int rightGain = Math.max(0, maxGain(node.right));

    // 3. 更新全局最大路径和
    // 以当前节点为“拱顶”的路径和为 node.val + leftGain + rightGain
    // 用它来更新 maxSum
    int currentPathSum = node.val + leftGain + rightGain;
    maxSum = Math.max(maxSum, currentPathSum);

    // 4. 返回对父节点有用的“单边”最大贡献
    // 只能是 节点值 + 左贡献 或 节点值 + 右贡献
    return node.val + Math.max(leftGain, rightGain);
  }
}

public class maxPathSum {
}
