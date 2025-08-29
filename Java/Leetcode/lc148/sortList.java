package lc148;

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
  public ListNode sortList(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }

    ListNode slow = head;
    ListNode fast = head;
    ListNode prev = null;

    while (fast != null && fast.next != null) {
      prev = slow;
      slow = slow.next;
      fast = fast.next.next;
    }

    if (prev != null) {
      prev.next = null;
    }

    ListNode leftHalf = head;
    ListNode rightHalf = slow;

    ListNode sortedLeft = sortList(leftHalf);
    ListNode sortedRight = sortList(rightHalf);

    ListNode dummyHead = new ListNode(0);
    ListNode tail = dummyHead;

    while (sortedLeft != null && sortedRight != null) {
      if (sortedLeft.val < sortedRight.val) {
        tail.next = sortedLeft;
        sortedLeft = sortedLeft.next;
      } else {
        tail.next = sortedRight;
        sortedRight = sortedRight.next;
      }
      tail = tail.next;
    }

    if (sortedLeft != null) {
      tail.next = sortedLeft;
    } else {
      tail.next = sortedRight;
    }
    return dummyHead.next;
  }
}

public class sortList {
  
  public static void main(String[] args) {

  }
}
