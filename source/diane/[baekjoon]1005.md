# Baekjoon ACM Craft 문제

- ACM Craft
    - https://www.acmicpc.net/problem/1005

### 문제 이해하기
ACM Craft는 건물을 짓는 게임으로, 특정 건물을 지으면 승리할 수 있다.
건물은 짓는데 걸리는 건설 시간이 있고, 어떤 건물은 다른 특정 건물이 지어진 후에만 건설할 수 있다.
승리를 위한 건물을 가장 빨리 지을 때까지 걸리는 최소 시간을 알아내자.

#### 입력
- int T : 테스트케이스 개수
    - 이 아래 입력은 테스트케이스 개수만큼 반복됨
- int N, K : 건물의 개수 N, 건설 순서 규칙의 개수 K
- int D1, D2, ... , DN : 각 건물의 건설에 걸리는 시간
- int X, Y (*K) : 건설 순서 규칙으로, X 건물이 지어진 후에 Y 건물을 지을 수 있다는 뜻
    - 건설 순서 규칙이 K번 반복하여 주어짐
- int W : 승리하기 위해 지어야할 목표 건물

#### 출력
- int : 목표 건물을 건설 완료하기까지 드는 최소 시간

### 문제 접근 방법
현재 지을 수 있는 건물들을 찾아 지금 지을 수 있는 건물 목록에 추가한다.
건물은 이 목록에 추가된 순간부터 즉시 건설되기 시작한다고 가정한다.
이 목록에서 건설 시간이 가장 짧은 건물을 찾아, 이 건물을 목록에서 제거하고 그 건물이 다 지어진 후의 시간으로 이동한다.
지금 지을 수 있는 건물 목록의 건물들은 그 건설 시간만큼 이미 지어졌으므로, 이 건물들을 건설하는데 걸리는 시간에서 그만큼 빼준다.
이 시점에서 지금 지을 수 있는 건물 목록을 업데이트하고, 위 과정을 반복한다.
그러다가 목표 건물이 지금 지을 수 있는 건물 목록에 추가되는 순간, 그 건물을 건설 시간에 관계 없이 즉시 건설하고 총 시간을 반환한다.

### 구현 배경 지식
- Topological Sorting

### 문제를 해결한 코드
~~~java
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    // i번 건물이 지어진 후 지을 수 있는 건물 번호들
    static ArrayList<ArrayList<Integer>> nextBuilding;
    // i번 건물이 지어지기 전에 먼저 지어져야 할 건물들 수
    static int[] numOfSource;
    // i번 건물이 지어지는 데에 걸리는 시간
    static int[] runningTime;

    static int buildings;
    static int rules;
    static int target;

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();

        for (int t=0; t<testCase; t++) {
            getInput(sc);
            System.out.println(topologicalSort());
        }
    }

    private static int topologicalSort() {
        int time = 0;
        boolean flag = false;

        ArrayList<Integer> startBuilding = new ArrayList<>();
        while (true) {
            // 앞에 해야하는 것이 없는 것들 모으기
            // = 지금 지을 수 있는 건물
            for (int i=0; i<buildings; i++) {
                if (numOfSource[i] == 0) {
                    if (i == target) {
                        flag = true;
                        break;
                    }
                    startBuilding.add(i);
                    numOfSource[i]--;
                }
            }

            // 지금 목표 건물을 지을 수 있다면?
            // 바로 짓고 끝내자!
            if (flag) {
                time += runningTime[target];
                break;
            }

            // 지금 목표 건물을 지을 수 없다면,
            // 가장 먼저 지어지는 건물 찾고, 이를 기준으로 타임라인 업그레이드하기
            int minTime = Integer.MAX_VALUE;
            int minBuilding = -1;
            for (int building : startBuilding) {
                if (minTime > runningTime[building]) {
                    minTime = runningTime[building];
                    minBuilding = building;
                }
            }
            time += minTime;
            startBuilding.remove((Integer) minBuilding);
            for (int b : nextBuilding.get(minBuilding)) {
                numOfSource[b]--;
            }
            for (int b : startBuilding) {
                runningTime[b]-=minTime;
            }
        }

        return time;
    }

    private static void getInput(Scanner sc) {
        buildings = sc.nextInt();
        rules = sc.nextInt();

        nextBuilding = new ArrayList<>();
        numOfSource = new int[buildings];
        runningTime = new int[buildings];
        for (int i=0; i<buildings; i++) {
            nextBuilding.add(new ArrayList<>());
            numOfSource[i] = 0;
            runningTime[i] = sc.nextInt();
        }

        for (int i=0; i<rules; i++) {
            int temp1 = sc.nextInt()-1;
            int temp2 = sc.nextInt()-1;

            numOfSource[temp2]++;
            nextBuilding.get(temp1).add(temp2);
        }

        target = sc.nextInt()-1;
    }
}
~~~