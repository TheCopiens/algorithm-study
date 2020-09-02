# 프로그래머스 문제

- 비밀지도
    - https://programmers.co.kr/learn/courses/30/lessons/17681
    
### 문제 이해하기

### 문제 접근 방법
각 수를 이진수로 바꾼다

### 구현 배경 지식
Integer.toBinaryString 사용

### 접근 방법을 적용한 코드
```java
class Solution {
	public String[] solution(int n, int[] arr1, int[] arr2) {
		String[] answer = new String[n];

		for (int i = 0; i < n; i++) {
			StringBuilder sb = new StringBuilder();
			String map1 = Integer.toBinaryString(arr1[i]);
			String map2 = Integer.toBinaryString(arr2[i]);
			int length1 = map1.length();
			int length2 = map2.length();

			if (map1.length() < n) {
				for (int j = 0; j < n - length1; j++) {
					map1 = "0" + map1;
				}
			}
			if (map2.length() < n) {
				for (int j = 0; j < n - length2; j++) {
					map2 = "0" + map2;
				}
			}

			for (int j = 0; j < n; j++) {
				if (map1.charAt(j) == '1' || map2.charAt(j) == '1') {
					sb.append('#');
				} else {
					sb.append(' ');
				}
			}
			answer[i] = sb.toString();

		}

		return answer;
	}
}
```
