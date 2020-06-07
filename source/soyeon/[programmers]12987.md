# 프로그래머스 문제
- 숫자 게임
    - https://programmers.co.kr/learn/courses/30/lessons/12987

## 풀이 방법
### 문제 이해하기
- B가 A를 이긴 횟수를 세는 문제이다.

### 문제 접근 방법
- 두 배열을 정렬하여 이긴 횟수를 센다.

### 구현 배경 지식

### 접근 방법을 적용한 코드
```java
class Solution {
    public int solution(int[] A, int[] B) {
        int index = 0;
        Arrays.parallelSort(A);
        Arrays.parallelSort(B);
        for(int i=0;i<A.length;i++) {
        	if(A[i]<B[i]) {
        		answer++;
        	} 
        }
        return answer;
    }
}
```

### 해결하지 못한 이유
- 어차피 B가 A를 이기지 못한다면 큰 숫자는 아껴뒀다가 나중에 사용해도 된다.
- 그래서 B가 A를 같은 index에서가 아닌 단순하게 이길 수 있는 횟수만 세도록 한다.

### 문제를 해결한 코드
```java
class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        int index = 0;
        Arrays.parallelSort(A);
        Arrays.parallelSort(B);
        for(int i=0;i<A.length;i++) {
        	if(A[index]<B[i]) {
        		index++;
        		answer++;
        	} 
        }
        return answer;
    }
}
```
