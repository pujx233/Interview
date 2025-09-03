package lc83;

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
  public ListNode deleteDuplicates(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }
    ListNode current = head;
    while (current != null && current.next != null) {
      if (current.val == current.next.val) {
        current.next = current.next.next;
      } else {
        current = current.next;
      }
    }

    return head;
  }
}

public class deleteDuplicates {
  public static void main(String[] args) {
    Solution s = new Solution();
    int[] arr = new int[] {1, 1, 1};
    ListNode head = LinkedListUtils.createFromArray(arr);
    s.deleteDuplicates(head);
  }
}
