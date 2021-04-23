# Baekjoon 사다리 조작 문제

- 사다리 조작
    - https://www.acmicpc.net/problem/15684

### 문제 이해하기
사다리 게임이 있다. 이 사다리 게임은 N개의 세로선과 그 세로선들 사이를 잇는 M개의 가로선으로 이루어져 있다.
이 사다리 게임에서는 세로선에 총 H개의 가로선을 놓을 수 있는데, 먼저 그려진 가로선도 그 위치에 맞추어 그려져 있다.
사다리 게임에서 가로선은 인접한 두 세로선을 연결하고, 두 가로선이 연속하거나 접하는 일은 없다.
주어진 사다리 게임에 가로선을 추가하여 i번 세로선의 결과가 i가 나오도록 만들고 싶다.
최대 3개의 가로선을 추가하여 조건에 맞는 사다리 게임을 만들 때, 최소 몇 개의 가로선을 추가해야 하는지 구하여라.

#### 입력
- int N M H : 사다리 게임의 세로선, 가로선 갯수와 세로선에 가로선을 놓을 수 있는 위치의 갯수
- int a b (x M) : 사다리 게임의 M개의 가로선 위치
    - b번째 세로선과 (b+1)번째 세로선을 잇는, 세로로 a번 위치에 가로선이 존재

#### 출력
- int K : 조건을 만족하기 위해 추가해야 하는 가로선 갯수의 최솟값
    - 정답이 3보다 큰 경우, 또는 불가능한 경우에는 -1을 반환

### 문제 접근 방법
주어진 사다리 게임에 비어있는 모든 가로선 자리에 가로선을 최대 3개까지 그리면서 조건에 맞는지를 확인할 것이다.
이에 따라 아래와 같은 상태 공간 트리를 그릴 수 있다.

(가로선 0개)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;추가된가로선없음  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\  
(가로선 1개)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1번자리가로선&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2번자리가로선&nbsp;&nbsp;&nbsp;&nbsp;...  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\  
(가로선 2개)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2번자리가로선&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3번자리가로선&nbsp;&nbsp;&nbsp;...  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\  
(가로선 3개) 3번자리가로선 4번자리가로선&nbsp;&nbsp;&nbsp;...

이 상태 공간 트리를 dfs로 탐색하면서, 각 노드에서 문제의 요구 조건을 충족하는지 확인할 것이다. 
각 노드를 탐색할 때 그 노드가 문제의 기준을 만족하지 않는다면, 그 노드의 자식 노드는 탐색하지 않고, 그 노드의 부모 노드로 돌아가 다른 노드를 탐색할 것이다.
이 때 사용되는 기준 함수(bounding function)은 다음과 같다. 해당 노드의 상태에서 추가될 가로선이 (1) 이미 존재하지 않고 (2) 왼쪽이나 오른쪽의 가로선과 만나서는 안 된다.

가능성 있는 모든 상태를 탐색하면서, 그 중 조건을 만족하는 상태에서 그 depth를 반환한다. 
추가할 가로선이 어떤 가로선인지를 알고 싶은 것이 아니라, 몇 개의 가로선이 추가되어야 하는지를 알기 위해 그 깊이를 반환하고, 그 깊이 중 최소값을 반환한다.
만약 깊이가 3을 탐색했는데 조건을 만족하지 않는다면, 그 이상은 탐색하지 않고 -1을 반환한다.

### 구현 배경 지식
- backtracking
- dfs

### 문제를 해결한 코드
~~~java
import java.util.Scanner;

public class Main {
    private static int N, M, H;
    private static boolean[][] ladder;
    private static int Limit = 3;

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        H = sc.nextInt();
        ladder = new boolean[N][H];

        for (int i=0; i<M; i++) {
            int temp1 = sc.nextInt() - 1;
            int temp2 = sc.nextInt();
            ladder[temp2][temp1] = true;
        }

        int result = backtracking(0, 1);

        System.out.println(result);
    }

    private static int backtracking(int iter, int idx) {
        if (gameResult()) {
            if (Limit > iter) Limit = iter;
            return iter;
        }

        if (iter == Limit) {
            return -1;
        }

        int result = -1;
        for (int i=idx; i<N; i++) {
            for (int j=0; j<H; j++) {
                if (makeLadder(i, j)) {
                    ladder[i][j] = true;
                    int temp = backtracking(iter+1, i);
                    ladder[i][j] = false;
                    if (temp != -1 &&(result == -1 || result > temp)) result = temp;
                    if (result == iter+1) return result;
                }
            }
        }
        return result;
    }

    private static boolean makeLadder(int lad, int step) {
        if (ladder[lad][step]) return false;
        if (lad>0 && ladder[lad-1][step]) return false;
        if (lad<N-1 && ladder[lad+1][step]) return false;
        return true;
    }

    private static boolean gameResult() {
        for (int num = 0; num < N; num++) {
            int position = num;
            for (int step = 0; step < H; step++) {
                if (ladder[position][step]) {
                    position--;
                } else if (position<N-1 && ladder[position+1][step]) {
                    position++;
                }
            }
            if (position != num) return false;
        }
        return true;
    }

    private static void printLadder() {
        System.out.println("Ladder -------");
        for (int i=0; i<H; i++) {
            System.out.print(i+" : ");
            for (int j=1; j<N; j++) {
                if (ladder[j][i]) System.out.print("--");
                else System.out.print("00");
            }
            System.out.println();
        }
    }
}
~~~