# Programmers 자물쇠와 열쇠 문제

- 자물쇠와 열쇠
    - https://programmers.co.kr/learn/courses/30/lessons/60059

### 문제 이해하기
NxN 크기의 자물쇠와 MxM 크기의 열쇠가 있다.
자물쇠의 모든 홈에 열쇠의 돌기가 들어가고, 자물쇠의 돌기와 열쇠의 돌기가 만나지 않는 경우, 그 열쇠로 자물쇠를 열 수 있다.
이 때 열쇠는 회전하고 이동할 수 있다.
하나의 열쇠와 하나의 자물쇠가 주어질 때, 이 열쇠로 자물쇠를 열 수 있는지 여부를 반환하라.
M은 항상 N 이하이고, M과 N은 3 이상 20 이하인 자연수이다.

#### 입력
- int[][] key : 열쇠의 모양, 0은 홈 부분, 1은 돌기 부분.
- int[][] lock : 자물쇠의 모양, 0은 홈 부분, 1은 돌기 부분.

#### 출력
- boolean : 주어진 열쇠로 자물쇠를 열 수 있는지 여부

### 문제 접근 방법
열쇠로 자물쇠를 열 수 있는 조건은 아래와 같다.
1. 자물쇠의 모든 홈에 열쇠의 돌기가 있을 것
2. 자물쇠의 돌기와 열쇠의 돌기가 만나지 않을 것

자물쇠의 홈 부분이 없는 경우는 이미 자물쇠가 열린 상태이므로 true를 반환하고, 열쇠의 돌기의 수가 자물쇠의 홈의 수보다 작은 경우는 무슨 수를 써도 열쇠로 자물쇠를 열 수 없으므로 false를 반환한다.

자물쇠의 홈 중에 하나를 선택하여, 열쇠의 모든 돌기를 차례대로 그 홈에 맞추어보고, 그 때 자물쇠의 모든 홈을 열쇠의 돌기로 채울 수 있는지 확인한다 (1번 조건).
만약 이 조건을 만족한다면, 이제 열쇠의 모든 돌기에 대해서 자물쇠의 홈에 들어가지 않고 자물쇠의 돌기와 만나는 부분이 없는지 확인한다(2번 조건).
두 조건을 모두 만족하면, 열쇠로 자물쇠를 열 수 있으므로 true를 반환하고,
그렇지 않다면 열쇠를 90도씩 돌려가며 위의 과정을 반복하여 자물쇠를 열어본다.
열쇠를 90도씩 돌려가며 모든 방향에 대해 확인했는데도 자물쇠를 열 수 없다면 false를 반환한다.


### 문제를 해결한 코드
~~~java
import java.util.ArrayList;

public class Solution {
    private ArrayList<Pair> locks;
    private ArrayList<Pair> keys;

    public boolean solution(int[][] key, int[][] lock) {
        boolean answer = true;

        locks = makeList(lock, 0);
        keys = makeList(key, 1);

        if (locks.size() == 0) return true; // 이미 열려있는 경우
        if (locks.size() > keys.size()) return false; // 답에 영향이 없네

        // locks의 모든 것이 keys에 있어야 함
        int size = keys.size();
        for (int rotate=0; rotate<4; rotate++) {
            for (int i = 0; i < size; i++) {
                answer = true;
                int xdiff = keys.get(i).x-locks.get(0).x;
                int ydiff = keys.get(i).y-locks.get(0).y;
                for (Pair l : locks) {
                    Pair temp = new Pair(l.x+xdiff, l.y+ydiff);
                    if (!keys.contains(temp)) {
                        answer = false;
                        break;
                    }
                }
                if (answer && NotExistConflict(lock.length, xdiff, ydiff)) {
                    return true;
                }
            }
            keys = rotateRight(keys, key.length);
        }

        return answer;
    }

    private boolean NotExistConflict(int n, int xdiff, int ydiff) {
        if (locks.size() == keys.size()) return true;
        // key의 튀어나온 부분과 lock의 튀어나온 부분이 충돌하는 경우
        for (Pair key : keys) {
            Pair temp = new Pair(key.x-xdiff, key.y-ydiff);
            if (!locks.contains(temp)) {
                if (temp.x >=0 && temp.x < n && temp.y >=0 && temp.y < n)
                    return false;
            }
        }
        return true;
    }

    private ArrayList<Pair> makeList(int[][] rawData, int flag) {
        ArrayList<Pair> result = new ArrayList<>();
        int length = rawData.length;
        for (int i=0; i<length; i++) {
            int[] temp = rawData[i];
            for (int j=0; j<length; j++) {
                if (temp[j] == flag) result.add(new Pair(i,j));
            }
        }
        return result;
    }

    private ArrayList<Pair> rotateRight(ArrayList<Pair> list, int length) {
        ArrayList<Pair> result = new ArrayList<>();
        for (Pair pair : list) {
            result.add(new Pair(pair.y, length-pair.x));
        }
        return result;
    }

}

class Pair extends Object {
    public int x;
    public int y;

    public Pair(int x, int y) {
        this.x = x; this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass()!=o.getClass()) return false;
        Pair p = (Pair) o;
        return (x==p.x)&&(y==p.y);
    }

    @Override
    public int hashCode() {
        return x*100+y;
    }
}
~~~

