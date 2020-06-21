# Implement Queue using Stacks

https://leetcode.com/problems/implement-queue-using-stacks/

## 문제 접근 방법

스택 두 개를 이용

- 스택1은 push만, 스택2는 pop과 peek할 때만 사용함

## 코드 구현

```java
import java.util.Stack;

class MyQueue {
    static Stack<Integer> s1;
    static Stack<Integer> s2;

    /** Initialize your data structure here. */
    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()){
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }

    /** Get the front element. */
    public int peek() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()){
                s2.push(s1.pop());
            }
        }
        return s2.peek();

    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return s1.isEmpty() && s2.isEmpty();
    }
}

```
