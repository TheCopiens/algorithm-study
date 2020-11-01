# 프로그래머스 문제

- 단어 변환
    - https://programmers.co.kr/learn/courses/30/lessons/43163
    
### 문제 이해하기
두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 찾는 문제

### 문제 접근 방법
index에 해당하는 char을 바꿔주면서 단어 변환을 모든 경우의 수를 한 담에 최소 경우를 찾는다.

### 구현 배경 지식
dfs

### 접근 방법을 적용한 코드
```java
class Solution {
	public boolean isDiffOneChar(String str1, String str2) {
		int cnt = 0;
		for (int i = 0; i < str1.length() && cnt < 2; i++) {
			if (str1.charAt(i) != str2.charAt(i)) {
				cnt++;
			}
		}
		return cnt == 1;
	}

	public int dfs(String begin, String target, int index, String[] words, boolean[] visited, int cnt) {
		if (begin.equals(target)) {
			return cnt;
		}
		if (visited[index]) {
			return cnt;
		}
		visited[index] = true;
		int ans = 0;
		for (int i = 0; i < words.length; i++) {
			if (index != i && isDiffOneChar(begin, words[i]) && !visited[i]) {
				ans = dfs(words[i], target, i, words, visited, cnt + 1);
			}
		}
		return ans;
	}

	public int solution(String begin, String target, String[] words) {
		int answer = words.length + 1;
		for (int i = 0; i < words.length; i++) {
			boolean[] visited = new boolean[words.length];
			if (isDiffOneChar(begin, words[i])) {
				answer = Math.min(answer, dfs(words[i], target, i, words, visited, 1));
			}
		}
		if (answer == words.length + 1) {
			return 0;
		}
		return answer;
	}

}
```
