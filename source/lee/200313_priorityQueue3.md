# 디스크 컨트롤러
    - https://programmers.co.kr/learn/courses/30/lessons/42627

## 문제 접근 방법
문제 설명은 이해했는데 공통적인 접근 방법을 전혀 떠올리지 못했다. 다른사람 코드 보고 공부함
1. input으로 들어오는 jobs가 요청 시간순이 아닐 수도 있기 때문에 요청 시간순으로 정렬해줌.
-> `하드디스크가 작업을 수행하고 있지 않을 때에는 먼저 요청이 들어온 작업부터 처리합니다.`조건 만족
2. 총 세 번의 while문이 등장한다. 첫 번째 while문은 전체 job을 전부 살펴보기 위함임. for루프로 쓰지 않은건 무조건 jobs의 순서대로 처리해야 하는 것이 아니고, 무조건 한 job만 처리해야 하는 것도 아니기 때문.
3. 두 번째 while문은 작업을 수행하고 있지 않을 때 그 시간에(`elaspedTime`) 들어온 job을 pq에 넣기 위함. 여러 작업이 동시에 들어올 수 있기 때문에 while문을 사용했고, `jobCount < jobs.length`는 `jobs[jobCount][0]`에서 out of bound exception을 발생시키지 않기 위해 사용
4. 두 번째 while문을 지나고 나서 처리할 job이 없으면 그대로 1ms 증가. pq에 job이 있으면 처리하고 처리 시간만큼 `elaspedTime` 증가.
5. 4번에서 job 처리하던 와중 새로 요청된 job이 있으면 pq에 넣음.
6. 2~5 반복

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
