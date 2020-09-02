# 프로그래머스 문제

- 다트 게임
    - https://programmers.co.kr/learn/courses/30/lessons/17682
    
### 문제 이해하기

- Single(S), Double(D), Triple(T) 영역이 존재하고 각 영역 당첨 시 점수에서 1제곱, 2제곱, 3제곱
- 스타상(*): 해당 점수와 바로 전에 얻은 점수를 각 2배로
- 아차상(#): 해당 점수는 마이너스

### 문제 접근 방법
점수를 스택에 넣으면서 해당 점수와 이전 점수를 계산한다.

### 구현 배경 지식
스택

### 접근 방법을 적용한 코드
```java
import java.util.*;
class Solution {
	private static final int SINGLE = 1;
	private static final int DOUBLE = 2;
	private static final int TRIPLE = 3;

	public int solution(String dartResult) {
		Stack<Integer> scores = new Stack<Integer>();
		StringTokenizer st = new StringTokenizer(dartResult, "SDT*#", true);
		String token = st.nextToken();
		scores.add(Integer.valueOf(token));

		while (st.hasMoreTokens()) {
			token = st.nextToken();

			if (token.equals("S")) {
				int score = scores.pop();
				scores.add((int) Math.pow(score, SINGLE));
			} else if (token.equals("D")) {
				int score = scores.pop();
				scores.add((int) Math.pow(score, DOUBLE));
			} else if (token.equals("T")) {
				int score = scores.pop();
				scores.add((int) Math.pow(score, TRIPLE));
			} else if (token.equals("*")) {
				int scoreLast = scores.pop();
				int scoreFirst = 0;
				if (!scores.isEmpty()) {
					scoreFirst = scores.pop();
				}

				if (scoreFirst != 0) {
					scores.add(scoreFirst * 2);
				}
				scores.add(scoreLast * 2);
			} else if (token.equals("#")) {
				int score = scores.pop();
				scores.add(score * -1);
			} else {
				scores.add(Integer.valueOf(token));
			}
		}

		return calcScores(scores);
	}

	public int calcScores(Stack<Integer> scores) {
		int answer = 0;
		while (!scores.isEmpty()) {
			answer += scores.pop();
		}
		return answer;
	}
}
```
