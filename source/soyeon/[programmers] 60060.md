# 프로그래머스 문제
- 가사 검색
    - https://www.welcomekakao.com/learn/courses/30/lessons/60060?language=java

## 풀이 방법
### 문제 이해하기
각 query 가 매치되는 word의 수를 배열 형태로 리턴하는 문제이다.

### 문제 접근 방법
ArrayList의 배열

### 구현 배경 지식

### 접근 방법을 적용한 코드
```java
/* 정확성: 25.0
 * 효율성: 30.0
 * 합계: 55.0 / 100.0 */
import java.util.*;
class Solution {
	public static char WILD_CARD = '?';

	public int[] solution(String[] words, String[] queries) {

		int queryLength = queries.length;
		int[] answer = new int[queryLength];

		ArrayList<String> wordLists[] = new ArrayList[10001];
		for (int i = 0; i < words.length; i++) {
			int wordLength = words[i].length();
			if (wordLists[wordLength] == null) {
				wordLists[wordLength] = new ArrayList<String>();
			}
			wordLists[wordLength].add(words[i]);
		}

		for (int i = 0; i < queryLength; i++) {
			answer[i] = matchedQuery(queries[i], wordLists);
		}

		return answer;
	}

	public int matchedQuery(String query, ArrayList<String> wordLists[]) {
		int answer = 0;
		ArrayList<String> sameLengthWords = wordLists[query.length()];

		if (sameLengthWords == null) {
			return 0;
		}
    
		for (String word : sameLengthWords) {
			if (isMatched(query, word)) {
				answer++;
			}
		}
		return answer;
	}

	public boolean isMatched(String query, String word) {
		if (query.length() != word.length()) {
			return false;
		}

		for (int i = 0; i < query.length(); i++) {
			if (query.charAt(i) != word.charAt(i)) {
				if (query.charAt(i) != WILD_CARD && word.charAt(i) != WILD_CARD) {
					return false;
				}
			}
		}
		return true;
	}
}
```

### 해결하지 못한 이유
시간 초과

### 문제를 해결한 코드
```java
import java.util.*;

public class Main {
	public static void main(String[] args) {
		String words[] = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
		String queries[] = { "fro??", "????o", "fr???", "fro???", "pro?" };
		Solution solution = new Solution();
		int[] answer = solution.solution(words, queries);
		for (int i = 0; i < answer.length; i++) {
			System.out.print(answer[i] + " ");
		}
	}
}

class Solution {

	public int[] solution(String[] words, String[] queries) {

		Trie[] tries = new Trie[100001];
		for (String word : words) {
			int wordLength = word.length();
			if (tries[wordLength] == null) {
				tries[wordLength] = new Trie();
			}

			tries[wordLength].insert(word);
		}

		int[] answer = new int[queries.length];
		for (int i = 0; i < queries.length; i++) {
			int len = queries[i].length();
			if (tries[len] == null) {
				answer[i] = 0;
			} else {
				answer[i] = tries[len].getCount(queries[i]);
			}
		}
		return answer;
	}
}

class Trie {
	public static char WILD_CARD = '?';

	private Node frontRootNode;
	private Node backRootNode;

	Trie() {
		frontRootNode = new Node();
		backRootNode = new Node();
	}

	public void insert(String word) {
		insertFront(word);
		insertBack(word);
	}

	private void insertFront(String word) {
		Node node = frontRootNode;
		for (int i = 0; i < word.length(); i++) {
			node.count++;
			// word.charAt(i) 가 children에 없는 경우 새로운 Node를 만든다.
			node = node.children.computeIfAbsent(word.charAt(i), c -> new Node());
		}
	}

	private void insertBack(String word) {
		Node node = backRootNode;
		for (int i = word.length() - 1; i >= 0; i--) {
			node.count++;
			node = node.children.computeIfAbsent(word.charAt(i), c -> new Node());
		}
	}

	public int getCount(String query) {
		if (query.charAt(0) == WILD_CARD) {
			return getCountFromBack(query);
		}

		return getCountFromFront(query);
	}

	private int getCountFromFront(String query) {
		Node node = frontRootNode;

		for (int i = 0; i < query.length(); i++) {
			if (query.charAt(i) == WILD_CARD) {
				break;
			}
			if (!node.children.containsKey(query.charAt(i))) {
				return 0;
			}
			node = node.children.get(query.charAt(i));
		}
		return node.count;
	}

	private int getCountFromBack(String query) {
		Node node = backRootNode;

		for (int i = query.length() - 1; i >= 0; i--) {
			if (query.charAt(i) == WILD_CARD) {
				break;
			}
			if (!node.children.containsKey(query.charAt(i))) {
				return 0;
			}
			node = node.children.get(query.charAt(i));
		}
		return node.count;
	}

}

class Node {
	Map<Character, Node> children;
	int count;

	Node() {
		this.children = new HashMap<>();
		this.count = 0;
	}
}
```

### 문제를 해결한 방법
trie

---
아래의 사이트를 참고해 작성된 글입니다.

* https://leveloper.tistory.com/99
* https://woovictory.github.io/2020/04/22/Java-Trie/
