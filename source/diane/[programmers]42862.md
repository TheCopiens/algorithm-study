# Programmers 체육복 문제

- 체육복
    - https://programmers.co.kr/learn/courses/30/lessons/42862

### 문제 이해하기
학생들은 기본으로 체육복을 하나씩 가지고 있다. 그런데 점심시간에 도둑이 들어, 일부 학생이 체육복을 도난 당했다.
따라서 여벌 체육복을 가진 학생들이 체육복이 없는 학생에게 체육복을 빌려주려고 한다.
여벌 체육복이 없는 학생은 자신의 체육복을 입어야 하기 때문에, 체육복을 빌려줄 수 없으며, 여벌의 체육복이 있었더라도 자신의 체육복을 도난 당했다면 자신의 여벌 체육복을 빌려줄 수 없다.
학생들은 모두 체격이 다르기 때문에, 체격 순으로 매겨진 번호로 자신의 바로 앞번호나 바로 뒷번호의 학생의 체육복만 입을 수 있다.
가능한 많은 학생들이 체육복을 입게 한다면, 총 몇 명의 학생이 체육복을 입을 수 있는지를 구하여라.

#### 입력
- int n : 전체 학생의 수 (번호는 1번부터 n번까지, 중복되지 않는다.)
- int[] lost : 체육복을 도난당한 학생들의 번호가 담긴 배열 (중복 없음)
- int[] reserve : 여벌의 체육복이 있는 학생들의 번호가 담긴 배열 (중복 없음)

#### 출력
- int : 체육복을 입을 수 있는 가장 많은 학생 수

### 문제 접근 방법
체육복이 없는 학생의 번호를 작은 순부터 탐색하면서,
여벌의 체육복을 가진 학생이 앞번호에 있으면 그 학생에게, 없으면 그 뒷학생에게 체육복을 빌린다고 가정한다.
만약 양쪽 번호 모두 여벌의 체육복이 없으면 체육복이 없는 학생은 체육복을 빌리지 못한다.

여벌의 체육복이 있더라도, 자신의 체육복을 도난당한 학생은 체육복을 빌려줄 수 없기 떄문에,
이 경우는 사전에 제거한다.

### 구현 배경 지식
Greedy Algorithm

### 문제를 해결한 코드
~~~java
import java.util.ArrayList;

public class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n - lost.length;
        ArrayList<Integer> more = new ArrayList<>();
        ArrayList<Integer> no = new ArrayList<>();

        for (int i : reserve) more.add(i);
        for (int i : lost) {
            if (more.contains(i)) {
                more.remove((Integer)i);
                answer++;
            } else {
                no.add(i);
            }
        }
        for (int i : no) {
            if (more.contains(i-1)) {
                more.remove((Integer)(i-1));
                answer++;
            } else if (more.contains(i+1)) {
                more.remove((Integer)(i+1));
                answer++;
            }
        }

        return answer;
    }
}
~~~
