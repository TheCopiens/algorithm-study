# 프로그래머스 문제

- N으로 표현
    - https://programmers.co.kr/learn/courses/30/lessons/42895
    
### 문제 이해하기
N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하는 문제이다

### 문제 접근 방법
최솟값이 8보다 크면 -1을 return 조건이 있으므로 모든 경우를 해본다.

### 구현 배경 지식
dfs

### 문제를 해결한 코드
```java
class Solution {
	public static int answer = 9;

	public int solution(int N, int number) {
		dfs(0, 0, N, number);
		return answer > 8 ? -1 : answer;
	}

	public void dfs(int cnt, int number, int N, int target) {
		if (cnt > 8) {
			return;
		}

		if (number == target) {
			answer = Math.min(answer, cnt);
			return;
		}

		for (int i = 1; i <= 8 - cnt; i++) {
			dfs(cnt + i, number + getNum(i, N), N, target);
			dfs(cnt + i, number - getNum(i, N), N, target);
			dfs(cnt + i, number / getNum(i, N), N, target);
			dfs(cnt + i, number * getNum(i, N), N, target);
		}
	}

	public int getNum(int digit, int N) {
		int result = 0;
		for (int i = 0; i < digit; i++) {
			result += Math.pow(10, i) * N;
		}
		return result;
	}
}
```

### 문제를 해결한 방법
* [참고](https://zin0-0.tistory.com/82)

