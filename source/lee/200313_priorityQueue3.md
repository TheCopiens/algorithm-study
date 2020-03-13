# 라면공장
    - https://programmers.co.kr/learn/courses/30/lessons/42629

## 문제 접근 방법

### 문제점
문제 설명은 이해했는데 공통적인 접근 방법을 전혀 떠올리지 못했다. 다른사람 코드 보고 공부함

## 코드 구현
```java
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    class Job implements Comparable<Job> {
        int requestedTime;
        int processTime;

        public Job(int requestedTime, int processTime) {
            this.requestedTime = requestedTime;
            this.processTime = processTime;
        }

        @Override
        public int compareTo(Job o) {
            return this.processTime - o.processTime;
        }
    }

    public int solution(int[][] jobs) {
        // sort by requested time
        Arrays.sort(jobs, (job1, job2) -> job1[0] - job2[0]);

        PriorityQueue<Job> scheduler = new PriorityQueue<>();
        int totalProcessTime = 0;
        int jobCount = 0;
        int elaspedTime = 0;

        while (jobCount < jobs.length || !scheduler.isEmpty()) {

            // idle일때 요청받음. 동시에 여러 요청이 올 수 있기 때문에 if가 아닌 while
            while (jobCount < jobs.length && elaspedTime == jobs[jobCount][0]) {
                scheduler.add(new Job(jobs[jobCount][0], jobs[jobCount][1]));
                jobCount++;
            }

            if (!scheduler.isEmpty()) {
                Job current = scheduler.poll();
                int jobWaitingTime = elaspedTime - current.requestedTime;
                totalProcessTime += jobWaitingTime + current.processTime;
                elaspedTime += current.processTime;

                while (jobCount < jobs.length && elaspedTime >= jobs[jobCount][0]) {
                    scheduler.add(new Job(jobs[jobCount][0], jobs[jobCount][1]));
                    jobCount++;
                }
            } else
                elaspedTime++;


        }

        return totalProcessTime / jobCount;
    }
}

```

### Time complexity

### Space complexity
