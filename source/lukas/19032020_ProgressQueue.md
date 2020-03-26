프로그래머스 스택/큐 문제
=========================

-	기능개발
	-	https://programmers.co.kr/learn/courses/30/lessons/42586

### 풀이 방법

#### 문제 접근 방법

-	기능 개선 작업이 완료 될때 배열된 작업들 순서대로 하나 혹은 그 전에 작업이 끝난 기능들을 함께 배포 해야함
	-	작업들이 끝나는 배포까지의 작업 날짜 수들을 각각 계산해 Queue에 순서대로 넣기
-	Queue에 있는 작업 날짜 수들을 차례로 비교해 하나 또는 함께 배포할 수 있는 기능들을 카운트해 ArrayList에 차례로 넣기

#### 접근 방법을 적용한 코드

```java
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Solution {

    public int computeDays(int progress, int speed) {
        int days = 0;
        while(progress < 100) {
            progress += speed;
            days++;
        }
        return days;
    }

    public int[] solution(int[] progresses, int[] speeds) {
        Queue<Integer> daysToFinish = new LinkedList<>();
        for(int i = 0; i < progresses.length; i++) {
            daysToFinish.add(computeDays(progresses[i], speeds[i]));
        }

        int progressToFinish = daysToFinish.poll();
        int count = 1;

        ArrayList<Integer> list = new ArrayList<>();

        while(!daysToFinish.isEmpty()) {
            if(progressToFinish >= daysToFinish.peek()) {
                daysToFinish.poll();
                count++;
            }else {
                list.add(count);
                count = 1;
                progressToFinish = daysToFinish.poll();
            }
        }
        list.add(count);

        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}
```
