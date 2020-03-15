# 더맵게
    - https://programmers.co.kr/learn/courses/30/lessons/42626

## 문제 접근 방법
1. pq를 만들어 스코빌지수의 모든 값을 넣음 -> pq의 첫 번째 원소=최소 스코빌지수
2. 문제 조건대로 최소 스코빌 지수, 두 번째로 작은 스코빌 지수로 새 스코빌 지수를 구한 후 다시 pq에 넣음.
3. pq의 헤드값이 K 이상이면 모든 음식의 스코빌 지수가 K이상이라는 뜻이므로 그동안의 섞은 카운트를 반환
4. while루프가 끝날때까지 반환하지 못했다는것은 모든 음식의 스코빌 지수를 새로 계산해도 K보다 작다는 의미이기 때문에 -1 반환


## 코드 구현
```java
import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> queue = new PriorityQueue<>(scoville.length);
        for (int i: scoville) queue.add(i);
        int count=0;
        while (queue.size()>1) {
            count++;
            int sco1 = queue.poll();
            int sco2 = queue.poll();
            int newSco = sco1 + 2*sco2;
            queue.add(newSco);
            if (queue.peek()>=K) return count;

        }


        return -1;
    }
}

```

### Time complexity
O(n) n=scoville.length

### Space complexity
O(n) n=scoville.length
