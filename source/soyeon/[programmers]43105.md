# 프로그래머스 문제
- 정수 삼각형
    - https://programmers.co.kr/learn/courses/30/lessons/43105

## 풀이 방법
### 문제 이해하기
- 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾는 문제이다.
- 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능하다

### 문제 접근 방법
- A[i][j]: i행 j 열의 삼각형까지 경로의 최댓값

### 구현 배경 지식
- greedy(?)

### 접근 방법을 적용한 코드
```java
class Solution {
	public int solution(int[][] A) {
		int n=A.length;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0)
					A[i][j] += A[i - 1][j];
				else if (j == i)
					A[i][j] += A[i - 1][j - 1];
				else
					A[i][j] += Math.max(A[i - 1][j], A[i - 1][j - 1]);
			}
		}
		int max = A[n - 1][0];
		for (int i = 1; i < n; i++) {
			if (max < A[n - 1][i])
				max = A[n - 1][i];
		}
		return max;
	}
}
```
