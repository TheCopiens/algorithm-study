# Baekjoon 연산자 끼워넣기

- 연산자 끼워넣기
    - hhttps://www.acmicpc.net/problem/14888

### 문제 이해하기
N개의 수로 이루어진 수열이 주어지고, 이 N개의 수 사이에 끼워넣을 (N-1)개의 연산자가 주어진다.
연산자는 덧셈(+), 뺄셈(-), 곱셈(x), 나눗셈(/)으로만 이루어져 있다.
수열의 순서를 바꾸지 않으면서, 수 사이에 이 연산자를 끼워넣어 여러 개의 수식을 만들 수 있다.
이렇게 만들 수 있는 수식의 계산 결과가 최대인 것과 최소인 것을 구하여라.
(단, 수식의 결과값이나 중간 과정값은 항상 -10억보다 크거나 같고, 10억보다 작거나 같다.)

#### 입력
- int N : 수열의 길이 (수의 개수, 2<=N<=11)
- int A1, A2, ... , AN : 수열의 숫자 (1<=A<=100)
- int op1, op2, op3, op4 : 사용할 수 있는 덧셈, 뺄셈, 곱셈, 나눗셈의 개수

#### 출력
- int : 최대인 수식의 결과 값
- int : 최소인 수식의 결과 값

### 문제 접근 방법
모든 경우를 dfs로 탐색하면서, 만들어진 수식의 값이 지금까지의 결과 중 최대이거나 최소인 경우 그 값을 저장한다.


### 구현 배경 지식
- Backtracking
- Depth-First Searching

### 문제를 해결한 코드
~~~java
import java.util.Scanner;

public class Main {

    private static int[] numbers;
    private static int[] operations;
    private static int MIN;
    private static int MAX;

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();

        numbers = new int[size];
        for (int i=0; i<size; i++) {
            numbers[i] = sc.nextInt();
        }

        operations = new int[4];
        for (int i=0; i<4; i++) {
            operations[i] = sc.nextInt();
        }

        MIN = Integer.MAX_VALUE;
        MAX = Integer.MIN_VALUE;
        try {
            putOperation(1, numbers[0]);
        } catch (Exception e) {
            e.printStackTrace();
        }

        System.out.println(MAX);
        System.out.println(MIN);
    }

    private static void putOperation(int idx, int number) throws Exception {
        if (idx == numbers.length) {
            if (number > MAX) {
                MAX = number;
            }
            if (number < MIN) {
                MIN = number;
            }
            return;
        }

        for (int op = 0; op<4; op++) {
            if (operations[op] > 0) {
                operations[op]--;
                int newNumber = calculate(op, numbers[idx], number);
                putOperation(idx+1, newNumber);
                operations[op]++;
            }
        }
    }

    private static int calculate(int op, int num, int number) throws Exception {
        if (op == 0) {
            return number+num;
        } else if (op == 1) {
            return number-num;
        } else if (op == 2) {
            return number*num;
        } else if (op == 3) {
            return number/num;
        }
        throw new Exception("Invaild operation.");
    }
}
~~~