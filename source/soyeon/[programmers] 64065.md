# 프로그래머스 스택/큐 문제
- 튜플
    - https://programmers.co.kr/learn/courses/30/lessons/64065

## 풀이 방법
### 문제 이해하기
{{a1}, {a1, a2}, {a1, a2, a3}, {a1, a2, a3, a4}, ... {a1, a2, a3, a4, ..., an}} 이런식으로 튜플을 표현할 수 있다.

### 문제 접근 방법
원소가 중복되지 않으므로 a1의 수가 가장 많이 포함 되었고 an이 가장 적게 포함되었다.
이를 이용해서 (원소, 원소의 갯수)로 해시맵에 담아서 원소의 갯수 순으로 내림차순 정렬을 한 순서로 키를 리턴하면 될 것이다.

### 구현 배경 지식
HashMap value 기준 정렬

### 접근 방법을 적용한 코드
```java
import java.util.*;
class Solution {
	public int[] solution(String s) {
		HashMap<Integer, Integer> hashmap = new HashMap<Integer, Integer>();

		StringTokenizer st = new StringTokenizer(s, "{},", false);
		Integer input = 0;
		while (st.hasMoreTokens()) {
			input = Integer.valueOf(st.nextToken());
			
			hashmap.put(input, hashmap.getOrDefault(input, 0) + 1);
		}

		// hashmap 의 value 기준 정렬
		List<Integer> keySetList = new ArrayList<>(hashmap.keySet());
		Collections.sort(keySetList, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				return hashmap.get(o2).compareTo(hashmap.get(o1));
			}
			
		});
		
		int index = 0;
		int answer[] = new int[keySetList.size()];
		for (Integer key : keySetList) {
			answer[index++] = key;
		}
		return answer;
	}
}
```
