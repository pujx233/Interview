package lc232;

import java.util.ArrayDeque;
import java.util.Deque;

class MyQueue {

  Deque<Integer> out, in;
  public MyQueue() {
    in = new ArrayDeque<>();
    out = new ArrayDeque<>();
  }

  public void push(int x) {
    while (!out.isEmpty()) in.addLast(out.pollLast());
    in.addLast(x);
  }

  public int pop() {
    while (!in.isEmpty()) out.addLast(in.pollLast());
    return out.pollLast();
  }

  public int peek() {
    while (!in.isEmpty()) out.addLast(in.pollLast());
    return out.peekLast();
  }

  public boolean empty() {
    return out.isEmpty() && in.isEmpty();
  }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
