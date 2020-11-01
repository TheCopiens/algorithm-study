# 프로그래머스 문제

- 정수 삼각형
    - https://programmers.co.kr/learn/courses/30/lessons/43105
    
### 문제 이해하기
삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾는 문제

### 문제 접근 방법
위에서부터 내려오면서 큰 것을 저장하도록 한다.

### 구현 배경 지식
dp

### 접근 방법을 적용한 코드
```java
import java.util.*;
class Solution {
	public int solution(int[][] triangle) {
		int row = triangle.length;

		for (int i = 1; i < row; i++) {
			int col = triangle[i].length;
			for (int j = 0; j < col; j++) {
				if (j == 0) {
					triangle[i][j] += triangle[i - 1][j];
				} else if (j == col - 1) {
					triangle[i][j] += triangle[i - 1][j - 1];
				} else {
					triangle[i][j] += Math.max(triangle[i - 1][j - 1], triangle[i - 1][j]);
				}
			}
		}

		int max = 0;
		for (int i = 0; i < triangle[row - 1].length; i++) {
			max = Math.max(max, triangle[row - 1][i]);
		}
		return max;
	}
}
```
