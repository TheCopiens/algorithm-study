# BAEKJOON 19237 어른 상어 문제

- 어른 상어
    - https://www.acmicpc.net/problem/19237

### 문제 이해하기
상어만이 있는 격자가 존재한다. 각 상어는 1부터 시작하는 자연수 번호를 가진다. 그 번호가 작을수록 상어가 더 강하다.
상어는 자신의 위치에 냄새를 뿌린 후, 자신의 방향 우선순위에 따라 1초마다 상하좌우 중 인접한 칸 중 하나로 이동하는 것을 반복한다.
상어의 냄새는 일정 시간이 지난 후에야 사라지고,
상어는 냄새가 없는 칸으로만 이동할 수 있다. 주변에 냄새가 없는 칸이 없다면, 자신의 냄새가 있는 칸으로 이동한다.
이동 후에 같은 칸에 상어가 여러 마리가 있다면, 가장 강한 상어가 다른 상어를 모두 몰아낸다.
이 때, 이 격자에 가장 강한 상어 하나만이 남기까지 걸리는 시간을 구하여라.

#### 입력
아래 입력은 모두 정수로 주어진다.
- 첫째 줄 : N M K
    - N : 격자의 크기 (격자는 NxN)
    - M : 격자에 있는 상어의 마릿수
    - K : 격자에 냄새가 남아있는 시간
- N개의 줄 : 각 N 개의 정수
    - 0은 빈칸. 0이 아닌 수 x는 x번 상어가 들어있는 칸.
- 다음 줄 : M 개의 정수
    - 각 상어의 방향 (1~4, 1:위, 2:아래, 3:왼쪽, 4:오른쪽)
- M*4개의 줄 : 각 4개의 정수
    - 각 상어의 현재 방향에 따른 다음 방향의 우선 순위

#### 출력
- int : 1번 상어만 격자에 남게 되기까지 걸리는 시간
    - 단, 1000초가 넘어도 다른 상어가 남아있으면, -1을 출력


### 문제 접근 방법
격자에 상어가 한 마리만 남을 때까지, 또는 1000초 동안 다음 방법을 반복한다.
1. 모든 상어를 다음 격자로 이동시킨다.
    1. 상어의 현재 방향에 따른 다음 방향 우선 순위를 구한다.
    2. 우선 순위에 따라 주변의 냄새가 존재하지 않는 격자로 이동하고, 그 방향을 저장한다.
    3. 만약 주변에 냄새가 없는 격자가 없다면, 자신의 냄새가 있는 격자로 우선 순위를 따라 이동한다.
2. 격자에 남은 냄새의 정보를 업데이트 한다.
    - 냄새의 지속시간을 하나 감소시키고, 지속시간이 0이 된 냄새는 없앤다.
3. 상어의 위치 정보를 격자에 업데이트하고, 동일한 위치에 상어가 있다면, 더 강한 상어만 남긴다.

### 구현 배경 지식
N/A

### 접근 방법을 작성한 코드
디버깅 전 코드가 없네요..

### 해결하지 못한 이유
- 단순 오류 : 갈 곳이 없어 자신의 냄새로 가야하는 로직에서 조건 오류 존재
- 냄새의 정보를 업데이트하는 시점과 상어의 이동 시점의 순서 차이
    : 상어가 먼저 이동하고, 냄새가 업데이트되어야 함

### 문제를 해결한 코드
Solution
~~~java
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class Solution {
    private int N; // 격자 수
    private int M; // 상어 수
    private int k; // 냄새 지속시간
    private HashMap<Position, State> tile;
    private HashMap<Integer, Shark> sharks;

    Solution(String file) {
        tile = new HashMap<>();
        sharks = new HashMap<>();
        if (file == null) {
            setData();
        } else {
            readFromFile(file);
        }
    }

    public int run() {
        int iter = 0;
        while (iter < 1000) {
            iter ++;
            ArrayList<Integer> ss = new ArrayList<>(sharks.keySet());
            ArrayList<Position> pp = new ArrayList<>(tile.keySet());
            Collections.sort(ss);
            for (int s : ss) {
                nextPosition(s);
            }
            for (Position p : pp) {
                State state = tile.get(p);
                if (state.next()) {
                    tile.put(p, state);
                } else {
                    tile.remove(p);
                }
            }
            for (int s : ss) {
                Position p = sharks.get(s).position;
                if (tile.get(p) == null) {
                    tile.put(new Position(p.x,p.y), new State(s,k));
                } else if (tile.get(p).shark == s) {
                    tile.put(new Position(p.x,p.y), new State(s,k));
                } else {
                    sharks.remove(s);
                }
            }
            if (sharks.size() < 2) return iter;
        }

        return -1;
    }

    private Position nextPosition(int s) {
        Shark shark = sharks.get(s);
        Position p = shark.position;
        ArrayList<Integer> next = shark.next.get(shark.direction-1);
        boolean flag = false;
        for (int d : next) {
            shark.direction = d;
            if (d == 1 && p.y>0) {
                if (tile.get(new Position(p.x, p.y-1))!= null) continue;
                p.y--;
                flag = true; break;
            } else if (d==2 && p.y<N-1) {
                if (tile.get(new Position(p.x, p.y+1))!= null) continue;
                p.y++;
                flag = true; break;
            } else if (d==3 && p.x>0) {
                if (tile.get(new Position(p.x-1, p.y))!= null) continue;
                p.x--;
                flag = true; break;
            } else if (d==4 && p.x<N-1) {
                if (tile.get(new Position(p.x+1, p.y))!= null) continue;
                p.x++;
                flag = true; break;
            }
        }
        if (!flag) {
            for (int d : next) {
                shark.direction = d;
                if (d == 1 && p.y > 0) {
                    if (tile.get(new Position(p.x, p.y-1)).shark != s) continue;
                    p.y--;
                    flag = true; break;
                } else if (d == 2 && p.y < N - 1) {
                    if (tile.get(new Position(p.x, p.y+1)).shark != s) continue;
                    p.y++;
                    flag = true; break;
                } else if (d == 3 && p.x > 0) {
                    if (tile.get(new Position(p.x-1, p.y)).shark != s) continue;
                    p.x--;
                    flag = true; break;
                } else if (d == 4 && p.x < N - 1) {
                    if (tile.get(new Position(p.x+1, p.y)).shark != s) continue;
                    p.x++;
                    flag = true; break;
                }
            }
        }
        if (!flag) System.out.println("ERROR");
        shark.position = p;
        sharks.put(s, shark);
        return new Position(p.x,p.y);
    }

    private void readFromFile(String filename) {
        File file = new File(filename);

        try {
            FileReader reader = new FileReader(file);
            BufferedReader breader = new BufferedReader(reader);

            String line = breader.readLine();
            String[] temp = line.split(" ");
            N = Integer.parseInt(temp[0]);
            M = Integer.parseInt(temp[1]);
            k = Integer.parseInt(temp[2]);

            for (int i=0; i<N; i++) {
                line = breader.readLine();
                temp = line.split(" ");
                for (int j=0; j<N; j++) {
                    if (!temp[j].equals("0")) {
                        int num = Integer.parseInt(temp[j]);
                        tile.put(new Position(j,i), new State(num,k));
                        sharks.put(num, new Shark(num, new Position(j,i)));
                    }
                }
            }

            line = breader.readLine();
            temp = line.split(" ");
            for (int i = 1; i<=M; i++) {
                Shark s = sharks.get(i);
                s.direction = Integer.parseInt(temp[i-1]);
                sharks.put(i, s);
            }

            for (int i=1; i<=M; i++) {
                Shark s = sharks.get(i);
                for (int d=1; d<5; d++) {
                    line = breader.readLine();
                    temp = line.split(" ");

                    ArrayList<Integer> dir = new ArrayList<>();
                    for (String t : temp) {
                        dir.add(Integer.parseInt(t));
                    }
                    s.next.add(dir);
                }
                sharks.put(i, s);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void printTiles() {
        int[][] tiles = new int[N][N];
        tile.forEach((Position p, State s) -> {
            tiles[p.y][p.x] = s.shark*10+s.smell;
        });
        sharks.forEach((Integer n, Shark s) -> {
            tiles[s.position.y][s.position.x] = s.num*10+s.direction;
        });
        System.out.println("-----------------------------------------------");
        for (int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                String number = String.format("%02d", tiles[i][j]);
                System.out.print(number+" ");
            }
            System.out.println();
        }
        System.out.println("-----------------------------------------------");
    }
}
~~~

Data Structure
```java
import java.util.ArrayList;

public class Shark {
    public int num;
    public Position position;
    public int direction;
    ArrayList<ArrayList<Integer>> next;

    Shark(int i, Position p) {
        num = i;
        position = p;
        next = new ArrayList<>();
    }
}

public class Position extends Object {
    public int x;
    public int y;

    Position(int x, int y) {
        this.x = x;
        this.y = y;
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

public class State {
    int shark;
    int smell;

    State(int shark, int smell) {
        this.shark = shark;
        this.smell = smell;
    }

    public boolean next() {
        this.smell--;
        if (smell > 0) {
            return true;
        }
        return false;
    }

    public String toString() {
        return shark+" "+smell;
    }
}
```


### 그 외 참고사항
HashMap에서 Key를 찾을 때에,
HashMap에 있는 key와 주어진 key를 비교할 때,
hashcode()를 불러 먼저 비교하고, equals() 함수를 불러 true이면 같다고 판단한다.
