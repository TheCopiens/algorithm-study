# Baekjoon 설탕 배달 문제

- 설탕 배달
    - https://www.acmicpc.net/problem/2839

### 문제 이해하기
설탕을 정확히 N킬로그램 배달해야 한다.
사용할 수 있는 봉지는 두 가지로, 3킬로그램 봉지와 5킬로그램 봉지가 있다.
필요한 봉지의 수를 가장 적게 사용하면서, 설탕을 배달할 때, 사용하는 봉지의 수를 구하여라.
만약 이 봉지로 정확히 N킬로그램을 만들 수 없다면 -1을 반환한다.

#### 입력
- int N : 배달하는 설탕의 무게 (킬로그램)
    - 3 이상 5000 이하

#### 출력
- int : 필요한 최소의 설탕 봉지 수

### 문제 접근 방법
N킬로그램의 설탕을 담는 최소 설탕 봉지를 S(N)이라고 하자.
S(N) = min(not -1)(S(N-3), S(N-5))+1
     = -1 (S(n-3)=S(N-5)=-1인 경우)

### 구현 배경 지식
Dynamic Programming (Memoization)

### 문제를 해결한 코드
~~~java
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static HashMap<Integer, Integer> cups;

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int sugar = sc.nextInt();

        cups = new HashMap<>();
        cups.put(3,1);
        cups.put(5,1);
        cups.put(1,-1);
        cups.put(2,-1);
        cups.put(4,-1);
        cups.put(6,2);

        System.out.println(calculate(sugar));
    }

    private static int calculate(int sugar) {
        if (cups.containsKey(sugar)) return cups.get(sugar);

        int cup = -1;
        int cup1 = calculate(sugar-5);
        int cup2 = calculate(sugar-3);

        if (cup1 != -1) {
            if (cup2 != -1) {
                cup = (cup1 > cup2? cup2:cup1)+1;
            } else {
                cup = cup1+1;
            }
        } else if (cup2 != -1) {
            cup = cup2+1;
        }

        cups.put(sugar, cup);

        return cup;
    }
}
~~~