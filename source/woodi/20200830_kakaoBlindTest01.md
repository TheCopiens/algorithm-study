# 카카오 블라인드 테스트 문제 : 가사검색
=========================
- https://www.welcomekakao.com/learn/courses/30/lessons/60060?language=java

### 풀이 방법
- 이진검색을 이용한 풀이(시간복잡도 : O(NM) --> O(M*logN)) (효율성 통과 못함) 

#### 문제 접근 방법
- 

### 구현 배경 지식
- 이진검색

#### 접근 방법을 적용한 코드

```java


class Solution {
  public static class Music{
		String genre;
		int musicNum;
		int play;
		public Music(String gen, int mn, int play) {
			this.genre= gen;
			this.musicNum =mn;
			this.play = play;
		}
	}
    static int count_by_array(String query, List words) {
		int cnt=0;
		for(Object w : words) {
			String word = (String)w;
			if(word.compareTo(query.replace("?", "a"))>0 && 
					word.compareTo(query.replace("?", "z"))<0) {
				cnt++;
			}
		}
		return cnt;
	}
    public static int[] sol2_binarySearch(String[] words, String[] queries) {
		int[] answer = new int[queries.length];
		// 1. 먼저 word의 '길이'에 대해서 각각 리스트(혹은 배열)을 만들어 단어를 담아주고, 오름차순 정렬 
		// 인덱스 : 가사의 길이 (가사 단어의 최대 길이 =10000)
		List[] arrange_words = new ArrayList[10001]; 
		List[] reversed_words = new ArrayList[10001];
		
		for(int i=0; i<10001; i++) {
			arrange_words[i] = new ArrayList();
			reversed_words[i] = new ArrayList();
		}
		for(String w : words) {
			arrange_words[w.length()].add(w);
			reversed_words[w.length()].add(new StringBuffer(w).reverse().toString());
		}
		// 2. 정렬
		for(int i=0; i<10001; i++) {
			Collections.sort(arrange_words[i]);
			Collections.sort(reversed_words[i]);
		}
		// 3. 이진탐색 수행한다. 
		for(int i=0; i<queries.length; i++) {
			int len = queries[i].length();
			if(queries[i].charAt(0)=='?') {
				String reverseq = new StringBuffer(queries[i]).reverse().toString();
				int cnt = count_by_array(reverseq, reversed_words[len]);
				answer[i]+=cnt;
			}else if(queries[i].charAt(queries[i].length()-1)=='?') {
				int cnt = count_by_array(queries[i], arrange_words[len]);
				answer[i]+=cnt;
			}
		}
		return answer;
		
	}
  }
}
```
