# 라면공장
    - https://programmers.co.kr/learn/courses/30/lessons/42629

## 문제 접근 방법
문제 설명은 이해했는데 공통적인 접근 방법을 전혀 떠올리지 못했다. 다른사람 코드 보고 공부함
1. 오늘(`elapsedDate=0`) 부터 k일까지 재고를 하나씩 소진해감.
2. 갖고 있는 재고가 0이 된다면, `dates[fromDateIdx]`부터 `elapsedDate`까지 들어온 공급을 `stocksPq`에 후보군으로써 넣어놓음
3. `pq.poll()`을 하게 되면 자동으로 공급된 재고 중 최댓값이 반환된다. 이 값을 stock에 더하고 다시 하루씩 재고를 소진한다.

## 코드 구현
```java
import java.util.*;

class Solution {
  public int solution(int stock, int[] dates, int[] supplies, int k) {
      int answer = 0;
      PriorityQueue<Integer> stocksPq = new PriorityQueue<>(Collections.reverseOrder());
      int fromDateIdx = 0;
      //k 전날 까지 버텨야 함.
      for (int elapsedDate = 1; elapsedDate < k; elapsedDate++) {
          //　매일 그 날 재고를 쓴다.
          stock--;

          //가지고 있는 stock이 그날 떨어진다면, elapsedDate전에 들어온 공급을 stocksPq에 후보군으로써 넣어놓음
          if (stock == 0) {
              while (fromDateIdx < dates.length && dates[fromDateIdx] <= elapsedDate) {
                  stocksPq.offer(supplies[fromDateIdx]);
                  fromDateIdx++;
              }

              answer++;
              // pq에서 최댓값 하나(가장 긴 날을 버틸 수 있는 재고량)만 현재 재고에 더함.
              stock += stocksPq.poll();
          }
      }
      return answer;
  }
}

```

### Time complexity
O(n\*k) n=dates.length

### Space complexity
O(n) n=dates.length
