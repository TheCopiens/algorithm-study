# 프로그래머스

- 등굣길
    - https://programmers.co.kr/learn/courses/30/lessons/42898
    
### 문제 이해하기
오른쪽과 아래쪽으로만 움직여 집에서 학교까지 갈 수 있는 최단경로의 개수를 1,000,000,007로 나눈 나머지를 구하는 문제이다.

### 문제 접근 방법
위나 왼쪽에서 올 수 있는 경로의 가짓수를 더해준다.

### 구현 배경 지식
dp??

### 접근 방법을 적용한 코드
```java
import java.util.*;
class Solution {
	public long solution(int m, int n, int[][] puddles) {
		long mat[][] = new long[n + 1][m + 1];
		for (int i = 1; i < mat.length; i++) {
			Arrays.fill(mat[i], -100);
			mat[i][0] = 0;
		}

		for (int i = 0; i < puddles.length; i++) {
			mat[puddles[i][1]][puddles[i][0]] = -1;
		}

		mat[1][1] = 1;

		findAll(n, m, mat);
		//printMat(mat);

		return mat[n][m];
	}

	public long findAll(int row, int col, long[][] mat) {
		if (mat[row][col] != -100) {
			return mat[row][col];
		}
		long left = findAll(row, col - 1, mat);
		long upper = findAll(row - 1, col, mat);

		if (left == -1 && upper == -1) {
			mat[row][col] = 0;
			return mat[row][col];
		}
		if (left == -1) {
			mat[row][col] = upper;
			return mat[row][col];
		}
		if (upper == -1) {
			mat[row][col] = left;
			return mat[row][col];
		}

		mat[row][col] = (left + upper) % 1000000007;
		return mat[row][col];
	}

	public static void printMat(long[][] mat) {
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[i].length; j++) {
				System.out.print(mat[i][j] + " ");
			}
			System.out.println();
		}
	}
}
```
