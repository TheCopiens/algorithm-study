# 프로그래머스 스택/큐 문제
- 영어 끝말잇기
    - https://programmers.co.kr/learn/courses/30/lessons/12981

## 풀이 방법
### 문제 이해하기
- 이전 단어의 끝 char == 다음 단어의 첫 char인지 확인
- 이전에 나왔던 단어인지 확인

### 문제 접근 방법

### 구현 배경 지식

### 접근 방법을 적용한 코드
```java
class Solution {
	public int[] solution(int n, String[] words) {
		int[] answer = new int[2];

		HashSet<String> set = new HashSet<String>();

		String before = words[0];
		set.add(words[0]);

		for (int i = 1; i < words.length; i++) {
			if (set.contains(words[i])) {
				return setAnswer(i, n);
			}

			if (before.charAt(before.length() - 1) != words[i].charAt(0)) {
				return setAnswer(i, n);
			}

			set.add(words[i]);
			before = words[i];
		}

		return answer;
	}

	public int[] setAnswer(int index, int n) {
		int answer[] = new int[2];
		answer[0] = (index + 1) % n;

		if (answer[0] == 0) {
			answer[0] = n;
		} else {
			answer[1] = 1;
		}

		answer[1] += (index + 1) / n;
		return answer;
	}
}
```
