# Baekjoon 영역 구하기 문제

- 영역 구하기
    - https://www.acmicpc.net/problem/2583

### 문제 이해하기
MxN 크기의 모눈종이가 있다. 
이 모눈종이에 눈금을 맞추어 k개의 직사각형을 그리면,
모눈종이가 이 직사각형의 내부를 제외한 나머지 부분으로 나뉘게 된다.
이 때 만들어진 나머지 영역이 몇 개이고, 그 넓이는 각각 얼마인지 구하라.

#### 입력
- int M, N, K : 모눈종이의 세로 길이, 가로 길이, 그려진 직사각형의 개수
    - 모두 100 이하의 자연수
- int 4개 * k : k개의 직사각형의 왼쪽 아래 꼭지점의 좌표와 오른쪽 위 꼭지점의 좌표

#### 출력
- int : 분리된 영역의 개수
- int 여러 개 : 각 영역의 넓이 (띄어쓰기로 구분)

### 문제 접근 방법
모눈종이의 각 칸은 아래 두가지로 구분한다.
- visited = true : 직사각형의 내부로, 문제에서 필요 없는 부분이다.
    또한, 이미 검사한 나머지 부분으로, 이미 검사했으니 다시 검사할 필요가 없는 부분도 이렇게 나타낸다.
- visited = false : 직사각형에 의해 생긴 나머지 부분으로, 앞으로 검사해야 할 부분이다.

문제를 해결하기 위해 사용한 방법은 아래와 같다.
1. 모눈종이에서 아직 검사하지 않은 나머지 부분을 찾는다.
2. 찾은 나머지 부분이 포함된 나머지 영역을 찾고, 그 넓이를 구한다.
   - 검사하지 않은 나머지 부분과 연결된 검사하지 않은 나머지 부분을 찾는다.
   - 새로 찾은 검사하지 않은 나머지 부분에 대하여 이를 반복한다.
   - 더 이상 연결된 검사하지 않은 나머지 부분이 없다면, 이 부분이 포함된 영역은 모두 찾은 것이기 때문에 넓이를 기록하고 종료한다.
3. 1-2번을 더 이상 검사하지 않은 나머지 부분이 없을 때까지 반복한다.


### 구현 배경 지식
BFS

### 문제를 해결한 코드
~~~java
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int k = sc.nextInt();
        boolean[][] matrix = new boolean[n][m];
        ArrayList<Integer> width = new ArrayList<>();

        for (int c=0; c<k; c++) {
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();

            for (int i=x1; i<x2; i++) {
                for (int j=y1; j<y2; j++) {
                    matrix[i][j] = true;
                }
            }
        }

        // 먼저 빈 칸을 찾는다
        // bfs를 해서 연결된 모든 것을 찾는다
        // 반복, 어떻게 끝난 것을 알지?
        ArrayList<Integer[]> queue = new ArrayList<>();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (matrix[i][j]) continue;

                queue.add(new Integer[] {i,j});
                int count = 0;
                while (!queue.isEmpty()) {
                    int[] position = Arrays.stream(queue.remove(0)).mapToInt(x -> x).toArray();
                    int x = position[0];
                    int y = position[1];
                    if (matrix[x][y]) continue;

                    matrix[x][y] = true;
                    count++;

                    if (x-1>=0 && !matrix[x-1][y]) queue.add(new Integer[] {x-1,y});
                    if (x+1<n && !matrix[x+1][y]) queue.add(new Integer[] {x+1,y});
                    if (y-1>=0 && !matrix[x][y-1]) queue.add(new Integer[] {x,y-1});
                    if (y+1<m && !matrix[x][y+1]) queue.add(new Integer[] {x,y+1});
                }

                width.add(count);
            }
        }

        Collections.sort(width);
        System.out.println(width.size());
        for (int wid : width) {
            System.out.print(wid);
            System.out.print(" ");
        }
    }

    private static void printMatrix(boolean[][] m) {
        int x = m.length;
        int y = m[0].length;

        for (int i=0; i<x; i++) {
            for (int j=0; j<y; j++) {
                if (m[i][j]) System.out.print("X");
                else System.out.print("O");
            }
            System.out.println();
        }
        System.out.println();
    }

}
~~~