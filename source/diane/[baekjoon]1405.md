# Baekjoon 미친 로봇 문제

- 미친 로봇
    - https://www.acmicpc.net/problem/1405

### 문제 이해하기
통제할 수 없는 로봇이 끝이 없는 평면 위에서 있다.
이 로봇은 동서남북 네 방향 중에 한 방향을 선택하고, 그 방향으로 한 칸 이동하는 일을 N번 반복할 것이다.
이 로봇이 N번 이동한 경로에서 모든 위치를 딱 한 번만 지나갔다면 (이동한 위치를 다시 이동한 적이 없다면) 그 경로는 단순하다고 한다.
이 로봇이 랜덤으로 N번 이동했을 때, 그 경로가 단순할 확률을 구하여라.

#### 입력
- int N : 로봇이 움직인 횟수
- int P1 P2 P3 P4 : 로봇이 동서남북으로 이동할 확률

#### 출력
- double P : 로봇의 이동경로가 단순할 확률 (오차범위 10^(-9))

### 문제 접근 방법
로봇이 N번 이동하는 모든 경우를 살펴볼 것이다.
그를 위해 아래와 같은 상태 공간 트리를 그린다.

(0번 이동)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;초기위치  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\  
(1번 이동)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;동
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;서&nbsp;&nbsp;&nbsp;...  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/
&nbsp;|&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;\  
(2번 이동) 동 서 남 북&nbsp;&nbsp;&nbsp;&nbsp;...

이 상태 공간 트리를 dfs로 탐험하면서, 각 노드에서 문제의 조건을 만족하는지 확인하고, 만족하지 않으면 그 부모노드로 돌아가 탐색을 계속 한다.
문제의 조건은 지금까지의 경로가 단순한지이고, 지금까지의 이동 경로 중 동일한 위치에 여러 번 방문했다면 이를 만족하지 못한다.
만약 깊이 N까지 탐색했고, 탐색하는 동안 문제의 조건에 걸리지 않았다면, 이 경로는 단순하다.
이 경우 로봇이 이 경로로 이동할 확률을 계산한다.
이런 모든 경로로 이동할 확률, 즉 각 경로로 이동할 확률의 합이 로봇의 경로가 단순할 확률이다.

### 구현 배경 지식
- backtracking
- 확률

### 문제를 해결한 코드
~~~java
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    private static int Number;
    private static Position position;
    private static Set<Position> visited;
    private static double[] Direction;
    private static int[] Path;

    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        Number = sc.nextInt();
        Path = new int[Number];
        Direction = new double[4];
        for (int i=0; i<4; i++) {
            int temp = sc.nextInt();
            Direction[i] = (double) temp/100;
        }

        position = new Position();
        visited = new HashSet<>();
        visited.add(position);
        double simple = backtracking(0);

        System.out.println(simple);
    }

    private static double backtracking(int depth) throws Exception {
        if (depth == Number) {
            return calculate();
        }

        double result = 0;
        for (int i=0; i<4; i++) {
            position.move(i);
            Path[depth] = i;
            if (isSimple()) {
                visited.add(position);
                result += backtracking(depth+1);
                visited.remove(position);
            }
            position.back(i);
        }
        return result;
    }

    private static boolean isSimple() {
        return !visited.contains(position);
    }

    private static double calculate() {
        double result = 1;
        for (int d : Path) {
            result = result*Direction[d];
        }
        return result;
    }
}

class Position extends Object {
    public int x;
    public int y;

    Position() {
        x=0; y=0;
    }

    Position(int x, int y) {
        this.x = x; this.y = y;
    }

    public void move(int direction) throws Exception {
        if (direction == 0) {
            x++;
        } else if (direction == 1) {
            x--;
        } else if (direction == 2) {
            y--;
        } else if (direction == 3) {
            y++;
        } else {
            throw new Exception("Invalid direction " + direction);
        }
    }

    public void back(int direction) throws Exception {
        if (direction == 0) {
            x--;
        } else if (direction == 1) {
            x++;
        } else if (direction == 2) {
            y++;
        } else if (direction == 3) {
            y--;
        } else {
            throw new Exception("Invalid direction " + direction);
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass()!=o.getClass()) return false;
        Position p = (Position) o;
        return (x==p.x)&&(y==p.y);
    }

    @Override
    public int hashCode() {
        return x*100+y;
    }
}
~~~