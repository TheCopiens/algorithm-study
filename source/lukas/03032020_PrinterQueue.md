프로그래머스 스택/큐 문제
=========================

-	프린터
	-	https://programmers.co.kr/learn/courses/30/lessons/42587

### 풀이 방법

#### 문제 접근 방법

-	문서를 대기 목록에 있는 순서 대로 인쇄 + 문서의 중요도가 높은 순서대로 인쇄
	-	PriorityQueue (FIFO Queue + priorities associated)
-	문서를 중요도 대로 정리 후(내림차순 PriorityQueue 큐) 대기 목록 큐의 문서를 하나씩 꺼가며 비교한다
-	꺼낸 문서보다 중요도가 높은 문서가 대기 목록에 존재하면 다시 대기 목록 큐에 삽입

#### 접근 방법을 적용한 코드

```java
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
  public int solution(int[] priorities, int location) {
    int answer = 0;

    Queue<Integer> q = new LinkedList<>();
    PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

    for(int i=0; i<priorities.length; i++){
      q.add(priorities[i]);
      pq.add(priorities[i]);
    }

    while(!q.isEmpty()){
      if(q.peek() == pq.peek()) {
        q.poll();
        pq.poll();
        answer++;

        if(location == 0){
          return answer;
        }
      } else {
        q.add(q.poll());
      }

      if(location > 0){
        location--;
      } else {
        location = q.size() - 1;
      }
    }

    return answer;
  }
}
```
