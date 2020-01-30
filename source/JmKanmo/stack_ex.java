
// 배열기반스택
class ArrayStack<T> {
    private int top;
    private Object[] stack;
    private int size;

    ArrayStack(int size) {
        this.top = -1;
        this.stack = new Object[size];
        this.size = size;
    }

    boolean isEmpty() {
        return this.top < 0 ? true : false;
    }

    T peek() {
        return isEmpty() ? null : (T) this.stack[top];
    }

    void push(T value) {
        if (++top >= size)
            return;
        stack[top] = value;
    }

    T pop() {
        if (isEmpty())
            return null;
        else {
            T ret = (T) stack[top--];
            return ret;
        }
    }
}

// 연결리스트기반 스택노드
class StackNode<T> {
    T value;
    StackNode<T> next;

    StackNode(T value) {
        this.value = value;
        this.next = null;
    }
}

// 연결리스트기반 스택
class LinkedStack<T> {
    private StackNode<T> list = null;

    boolean isEmpty() {
        return list == null ? true : false;
    }

    void push(T value) {
        StackNode<T> node = new StackNode<T>(value);
        node.next = list;
        list = node;
    }

    T pop() {
        if (isEmpty())
            return null;
        else {
            StackNode ret = list;
            list = list.next;
            return (T) ret.value;
        }
    }

    T peek() {
        if (isEmpty())
            return null;
        else
            return list.value;
    }
}

public class stack_ex {
    public static void main(String[] args) {
        LinkedStack<String> stack = new LinkedStack<>();
        stack.push("hello");
        stack.push("junmo");
        stack.push("peach");
        stack.push("shit");

        while (stack.isEmpty() != true) {
            System.out.println(stack.pop());
        }
    }
}
