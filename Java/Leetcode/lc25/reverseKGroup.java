package lc25;

/**
 * LeetCode 提供的单链表节点定义
 */
class ListNode {
  int val;
  ListNode next;
  ListNode() {}
  ListNode(int val) { this.val = val; }
  ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

/**
 * 链表辅助工具类，用于测试
 */
class LinkedListUtils {
  /**
   * 从一个数组创建链表
   * @param arr 输入的整数数组
   * @return 链表的头节点
   */
  public static ListNode createFromArray(int[] arr) {
    if (arr == null || arr.length == 0) {
      return null;
    }
    ListNode dummy = new ListNode(-1); // 虚拟头节点，简化操作
    ListNode current = dummy;
    for (int value : arr) {
      current.next = new ListNode(value);
      current = current.next;
    }
    return dummy.next;
  }

  /**
   * 打印链表的所有节点值
   * @param head 链表的头节点
   */
  public static void printList(ListNode head) {
    if (head == null) {
      System.out.println("null");
      return;
    }
    ListNode current = head;
    while (current != null) {
      System.out.print(current.val + " -> ");
      current = current.next;
    }
    System.out.println("null");
  }
}

class Solution {
  /**
   * K 个一组翻转链表
   * 在这里实现你的算法
   */
  public ListNode reverseKGroup(ListNode head, int k) {
    // 处理特殊情况
    if (head == null || k <= 1) {
      return head;
    }

    ListNode dummy = new ListNode(0);
    dummy.next = head;

    // pre 是待反转分组的前一个节点
    ListNode pre = dummy;

    while (true) {
      // 1. 检查剩余节点是否足够 k 个
      ListNode tail = pre;
      for (int i = 0; i < k && tail != null; i++) {
        tail = tail.next;
      }
      // 如果 tail 为 null，说明不足 k 个，结束循环
      if (tail == null) {
        break;
      }

      // 2. 准备进行头插法反转
      // curr 指向本组的第一个节点，它在反转后会成为本组的尾节点
      ListNode curr = pre.next;

      // 3. 执行 k-1 次头插操作
      for (int i = 0; i < k - 1; i++) {
        // a. 记下要移动的节点
        ListNode node_to_move = curr.next;

        // b. curr 跳过 node_to_move
        curr.next = node_to_move.next;

        // c. node_to_move 指向 pre 的下一个节点 (即当前分组的头)
        node_to_move.next = pre.next;

        // d. pre 指向 node_to_move，完成插入
        pre.next = node_to_move;
      }

      // 4. 移动 pre 到下一分组的前一个位置
      // 此时 curr 正是本组的最后一个节点（即原分组的第一个节点）
      pre = curr;
    }

    return dummy.next;
  }

  public static void main(String[] args) {
    Solution solution = new Solution();

    int[] arr1 = {1, 2, 3, 4, 5};
    int k1 = 2;
    ListNode head1 = LinkedListUtils.createFromArray(arr1);
    System.out.print("Original List 1: ");
    LinkedListUtils.printList(head1);
    ListNode result1 = solution.reverseKGroup(head1, k1);
    System.out.print("Reversed List 1 (k=" + k1 + "): ");
    LinkedListUtils.printList(result1); // 预期输出: 2 -> 1 -> 4 -> 3 -> 5 -> null

    System.out.println("----------------------------------------");

  }
}
