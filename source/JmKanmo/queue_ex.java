import java.util.Scanner;

/*
배열기반 원형큐 구현 
백준 10845 
writer: JmKanmo
Date: 2020.01.30
 */

class ArrayQueue<T> {
    private int front;
    private int rear;
    private Object[] arr;
    private int q_size;

    ArrayQueue(int size) {
        arr = new Object[size];
        q_size = size;
    }

    private void init() {
        front = -1;
        rear = -1;
    }

    int size() {
        return Math.abs(rear - front);
    }

    int empty() {
        if (front == rear) {
            init();
            return 1;
        }
        return 0;
    }

    void push(T value) {
        if (rear + 1 >= q_size)
            return;
        arr[++rear] = value;
    }

    T front() {
        if (empty() == 1)
            return null;
        else
            return (T) arr[front + 1];
    }

    T back() {
        if (empty() == 1)
            return null;
        else
            return (T) arr[rear];
    }

    T pop() {
        if (empty() == 1)
            return null;
        else
            return (T) arr[++front];
    }
}

public class queue_ex {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int N = Integer.parseInt(scn.nextLine());
        ArrayQueue<Integer> q = new ArrayQueue(N + 1);

        for (int i = 0; i < N; i++) {
            String input = scn.nextLine();
            String[] splited = input.split(" ");

            if (splited.length == 1) {
                switch (splited[0]) {
                case "size":
                    System.out.println(q.size());
                    break;

                case "empty":
                    System.out.println(q.empty());
                    break;

                case "front":
                    Integer front = q.front() == null ? -1 : q.front();
                    System.out.println(front);
                    break;

                case "back":
                    Integer back = q.back() == null ? -1 : q.back();
                    System.out.println(back);
                    break;

                case "pop":
                    Integer pop = q.pop();
                    if (pop == null) {
                        System.out.println(-1);
                    } else {
                        System.out.println(pop);
                    }
                    break;
                }
            } else if (splited.length > 1) {
                q.push(Integer.parseInt(splited[1]));
            }
        }
    }
}