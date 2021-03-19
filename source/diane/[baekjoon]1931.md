# Baekjoon 회의실 배정

- 회의실 배정
    - https://www.acmicpc.net/problem/1931


### 문제 이해하기
N개의 회의가 있는데, 회의실은 하나이다. 각 회의에 대해 시작시간과 끝나는 시간이 주어지고,
회의가 겹치지 않게 회의실을 사용할 때 할 수 있는 회의의 최대 개수를 찾아라.
회의는 중단되지 않으며, 회의가 끝남과 동시에 다른 회의가 시작될 수 있다.


#### 입력
- int N : 회의의 개수
- int Start End : N번 반복되며, 각 회의의 시작시간과 끝시간


#### 출력
- int : 할 수 있는 회의의 최대 개수


### 문제 접근 방법
회의실에서 어떤 회의가 진행된다면, 그 회의가 빨리 끝날수록 그 회의실에서 더 많은 회의를 할 가능성이 증가한다.
따라서 지금 회의실에서 할 수 있는 회의 중 가장 빨리 끝나는 회의를 해야 한다.


### 구현 배경 지식
- Greedy Algorithm


### 문제를 해결한 코드
~~~java
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Meeting> meetings = new ArrayList<>();

        int count = sc.nextInt();
        for (int i=0; i<count; i++) {
            int start = sc.nextInt();
            int end = sc.nextInt();
            meetings.add(new Meeting(start, end));
        }

        Collections.sort(meetings);
        int time = 0;
        int number = 0;
        for (Meeting meeting : meetings) {
            if (meeting.start >= time) {
                number++;
                time = meeting.end;
            }
        }

        System.out.println(number);
    }
}

class Meeting implements Comparable<Meeting> {
    public int start;
    public int end;

    public Meeting(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public int compareTo(Meeting m) {
        if (end == m.end)
            return start - m.start;
        return end - m.end;
    }

    @Override
    public String toString() {
        return "Meeting{" + start + "~" + end + '}';
    }
}
~~~