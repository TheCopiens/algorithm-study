# 더맵게
    - https://programmers.co.kr/learn/courses/30/lessons/42626

## 문제 접근 방법


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
            if (queue.peek()>K) return count;

        }


        return -1;
    }
}

```

### Time complexity

### Space complexity
