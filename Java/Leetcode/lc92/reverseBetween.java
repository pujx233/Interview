package lc92;

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
  public ListNode reverseBetween(ListNode head, int left, int right) {
    ListNode dummy = new ListNode(-1, head);

    ListNode preLeft = dummy;
    for (int i = 0; i < left - 1; i++) {
      preLeft =  preLeft.next;
    }

    ListNode leftNode = preLeft.next;
    for (int i = 0; i < right - left; i++) {
      ListNode move = leftNode.next;
      leftNode.next = leftNode.next.next;
      move.next = preLeft.next;
      preLeft.next = move;
    }

    return dummy.next;
  }



  public static void main(String[] args) {
    Solution solution = new Solution();

    int[] arr1 = {1, 2, 3, 4, 5};
    ListNode head1 = LinkedListUtils.createFromArray(arr1);
    LinkedListUtils.printList(head1);
    ListNode result1 = solution.reverseBetween(head1, 3, 4);
    LinkedListUtils.printList(result1); // 预期输出: 2 -> 1 -> 4 -> 3 -> 5 -> null

    System.out.println("----------------------------------------");

  }
}