# 프로그래머스 문제
- 2 X N 타일링
    - https://programmers.co.kr/learn/courses/30/lessons/12900

## 풀이 방법
### 문제 이해하기
- 직사각형 모양의 타일을 채우는 방법의 가짓 수를 구하는 문제이다.

### 문제 접근 방법
- 이전 단계를 이용하여 다음 단계의 문제를 푼다.
- 경우의 수를 구할 때 1000000007로 나눈 나머지를 구한다.
- answer[i-2]에서 타일 2개를 배열하는 방법은 2가지이나 세로로 배열하는 방법은 answer[i-1]에 포함된다.

### 접근 방법을 적용한 코드
```java
class Solution {
    public int solution(int n) {
        int answer[] = new int[n+1];
        answer[1] = 1;
        answer[2] = 2;
        for(int i=3;i<=n;i++){
            answer[i]=(answer[i-2]+answer[i-1])%1000000007;
        }
        return answer[n];
    }
}
```
