# 프로그래머스 서머코딩/윈터코딩(~2018) 문제
- 숫자 게임
    - https://programmers.co.kr/learn/courses/30/lessons/12987

## 풀이 방법
### 문제 이해하기
- 입력값: A와 B의 숫자 배열
- 출력값: B가 최대로 이길때 점수 최대값
### 문제 접근 방법
- 구하고자 하는 값은 순서와 관계가 없다.
- 따라서 비교를 쉽게 하도록 오름차순 정렬한다.
- A의 가장 작은 값부터 B가 이기는 갯수를 카운트 한다.

### 접근 방법을 적용한 코드
```java
import java.util.Arrays;
class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        int i=0,j=0;
        Arrays.sort(A); 
        Arrays.sort(B);

        while(i<A.length && j<B.length){
            if(A[i]<B[j]){
                answer++;
                j++;
                i++;
            }else {
                j++;
            }
        } 
        return answer;
    }
}
```
