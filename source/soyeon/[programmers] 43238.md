# 프로그래머스 문제

- 입국심사
    - https://programmers.co.kr/learn/courses/30/lessons/43238
    
### 문제 이해하기
* 입국심사를 기다리는 사람 수 n
* 각 심사관이 한 명을 심사하는데 걸리는 시간이 담긴 배열 times
* 모든 사람이 심사를 받는데 걸리는 시간의 최솟값을 return 하는 문제
* 주의: 최솟값을 구하는 문제이므로 심사대가 비지만 그곳에서 심사를 받지 않고 더 기다린 후에 다른 심사대에서 심사를 받는 경우가 있을 수 있다.

### 문제 접근 방법
* 어떤 시간이 주어졌을 때, 심사관들이 몇 명을 심사할 수 있는지 계산하여 n보다 크면 시간을 줄이고, n보다 작으면 시간을 늘린다

### 구현 배경 지식
이분탐색

### 문제를 해결한 코드
```java
import java.util.*;
class Solution {
    public long solution(int n, int[] times) {
         Arrays.sort(times);
        
         long min=1;
         long max=(long)times[times.length-1]*n;
         long mid=0;
         long sum;
         long answer = max;
        
         while(min<=max){
             sum=0;
             mid=(min+max)/2;
             
             for(int time:times){
                 sum+=mid/time;
             }
             
             if(sum>=n){
                 if(mid<answer){
                     answer=mid;
                 }
                 max=mid-1;                
             }
             else{
                 min=mid+1;
             }
         }
         return answer;
    }
}
```

### 문제를 해결한 방법
[참고](https://iamheesoo.github.io/blog/algo-prog43238)


