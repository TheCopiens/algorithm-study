# [프로그래머스 / 자바] 2XN 타일링

https://programmers.co.kr/learn/courses/30/lessons/12900#



## 접근 방식 

- dp[i]=dp[i-1]+dp[i-2]



## 소스 구현

```java
class Solution {
  public int solution(int n) {
      int answer = 0;
      int[] dp = new int[n+1];
      dp[0]=1;
      dp[1] = 1;
      for(int i=2; i<=n; i++){
          dp[i]= (dp[i-1]+dp[i-2])%1000000007;
         
      }
      
      return dp[n];
  }
}
```



## 테스트 

### 정확성 테스트

```tex
테스트 1 〉	통과 (0.96ms, 53MB)
테스트 2 〉	통과 (0.90ms, 50.2MB)
테스트 3 〉	통과 (0.92ms, 50.2MB)
테스트 4 〉	통과 (1.13ms, 50.3MB)
테스트 5 〉	통과 (0.85ms, 52.3MB)
테스트 6 〉	통과 (1.08ms, 53MB)
테스트 7 〉	통과 (0.90ms, 50.6MB)
테스트 8 〉	통과 (3.26ms, 50.1MB)
테스트 9 〉	통과 (1.01ms, 52.5MB)
테스트 10 〉	통과 (1.16ms, 50.6MB)
테스트 11 〉	통과 (0.92ms, 50.2MB)
테스트 12 〉	통과 (0.89ms, 52.2MB)
테스트 13 〉	통과 (1.01ms, 52.7MB)
테스트 14 〉	통과 (1.00ms, 51MB)
```

### 효율성 테스트

```tex
테스트 1 〉	통과 (1.37ms, 49.9MB)
테스트 2 〉	통과 (1.67ms, 51.9MB)
테스트 3 〉	통과 (1.30ms, 50MB)
테스트 4 〉	통과 (1.34ms, 52.1MB)
테스트 5 〉	통과 (2.04ms, 52MB)
테스트 6 〉	통과 (2.77ms, 53MB)
```

