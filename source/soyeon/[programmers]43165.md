# 프로그래머스 문제
- 타겟 넘버
    - https://programmers.co.kr/learn/courses/30/lessons/43165

## 풀이 방법
### 문제 이해하기
- 숫자를 더하거나 빼서 최종 결과가 targetSum과 같은 경우의 수를 구하는 문제

### 문제 접근 방법
- 재귀함수

### 구현 배경 지식
- 브루트포스

### 접근 방법을 적용한 코드
```java
class Solution {
	public static int answer=0;
    public int solution(int[] numbers, int target) {
    	findAll(numbers, target, 1, numbers[0]);
    	findAll(numbers, target, 1, numbers[0]*(-1));
        return answer;
    }
    public void findAll(int[] numbers, int target, int nowIndex, int sum) {
    	if(nowIndex==numbers.length) {
    		if(target==sum) {
    			answer++;
    		}
    		return;
    	}
    	findAll(numbers, target, nowIndex+1, sum+numbers[nowIndex]);
    	findAll(numbers, target, nowIndex+1, sum-numbers[nowIndex]);
    }
}
```
