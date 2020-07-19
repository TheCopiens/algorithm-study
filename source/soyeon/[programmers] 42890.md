# 프로그래머스 문제

- 후보키
    - https://programmers.co.kr/learn/courses/30/lessons/42890
    
### 문제 이해하기
후보 키가 될 수 있는 키 쌍을 구하는 문제이다.

### 문제 접근 방법
hashSet에 모든 쌍을 구한 뒤, 해당 키 쌍이 후보 키가 될 수 있는지 각각 확인한다.
후보 키가 될 수 있다면 이미 구한 후보 키 set에 포함되는지 확인한다.

### 구현 배경 지식
완전탐색

### 접근 방법을 적용한 코드

정확성: 67.9 / 100.0

```java
import java.util.*;
class Solution {
	public static int ans = 0;
	public static ArrayList<HashSet<Integer>> candidateKeys;

	public int solution(String[][] relation) {

		candidateKeys = new ArrayList<HashSet<Integer>>();
		HashSet<Integer> keySet = new HashSet<Integer>();
		for (int i = 0; i < relation[0].length; i++) {
			keySet.add(i);
			createCandidateKey(1, new HashSet<Integer>(keySet), relation);
			keySet.remove(i);
		}

		return candidateKeys.size();
	}

	public void createCandidateKey(int index, HashSet<Integer> keySet, String[][] relation) {

		if (index == relation[0].length) {
			// System.out.println(keySet);
			if (checkCandidateKey(keySet, relation)) {
				for (int i = 0; i < candidateKeys.size(); i++) {
					HashSet<Integer> savedSet=candidateKeys.get(i);
					if(savedSet.size()>keySet.size() && containsAll(savedSet, keySet)) {
						candidateKeys.remove(savedSet);
						candidateKeys.add(keySet);
						return;
					}
					if(savedSet.size()<=keySet.size() && containsAll(keySet, savedSet)) {
						return;
					}
				}
				//System.out.println(keySet);
				candidateKeys.add(keySet);
			}
			return;
		}

		createCandidateKey(index + 1, new HashSet<Integer>(keySet), relation);
		for (int i = index; i < relation[0].length; i++) {
			keySet.add(i);
			createCandidateKey(index + 1, new HashSet<Integer>(keySet), relation);
			keySet.remove(i);
		}

	}

	public static boolean containsAll(HashSet<Integer> big, HashSet<Integer> small) {
		Iterator it = small.iterator();
		
		boolean isContainsAll=true;
		while (it.hasNext()) {
			if (!big.contains(it.next())) {
				isContainsAll=false;
			}
		}
		return isContainsAll;
	}

	public boolean checkCandidateKey(HashSet<Integer> keySet, String[][] relation) {
		HashSet<String> set = new HashSet<String>();
		for (int i = 0; i < relation.length; i++) {
			StringBuilder sb = new StringBuilder("");
			Iterator it = keySet.iterator();
			while (it.hasNext()) {
				int key = (int) it.next();
				sb.append(relation[i][key] + " ");
			}
			String newString = sb.toString();
			if (set.contains(newString)) {
				return false;
			}

			set.add(newString);
		}
		return true;
	}
}
```

### 틀린 이유
맨 첫 요소를 선택하지 않는 경우를 빼먹었다

### 문제를 해결한 코드

```java
class Solution {
	public static int ans = 0;
	public static ArrayList<HashSet<Integer>> candidateKeys;

	public int solution(String[][] relation) {

		candidateKeys = new ArrayList<HashSet<Integer>>();
		HashSet<Integer> keySet = new HashSet<Integer>();
		createCandidateKey(1, new HashSet<Integer>(keySet), relation); // 이 부분 추가
		
		for (int i = 0; i < relation[0].length; i++) {
			keySet.add(i);
			createCandidateKey(1, new HashSet<Integer>(keySet), relation);
			keySet.remove(i);
		}

		return candidateKeys.size();
	}

	public void createCandidateKey(int index, HashSet<Integer> keySet, String[][] relation) {

		if (index == relation[0].length) {
			if (checkCandidateKey(keySet, relation)) {
				for (int i = 0; i < candidateKeys.size(); i++) {
					HashSet<Integer> savedSet=candidateKeys.get(i);
					if(savedSet.size()>keySet.size() && containsAll(savedSet, keySet)) {
						// keySet이 더 작은 후보 키인 경우
						candidateKeys.remove(savedSet);
						candidateKeys.add(keySet);
						return;
					}
					if(savedSet.size()<=keySet.size() && containsAll(keySet, savedSet)) {
						// 중복 또는 이미 더 작은 후보 키를 찾은 경우
						return;
					}
				}
				
				// 기존 후보 키와 겹치는 것이 없는 경우
				candidateKeys.add(keySet);
			}
			return;
		}

		createCandidateKey(index + 1, new HashSet<Integer>(keySet), relation);
		for (int i = index; i < relation[0].length; i++) {
			keySet.add(i);
			createCandidateKey(index + 1, new HashSet<Integer>(keySet), relation);
			keySet.remove(i);
		}

	}

	public static boolean containsAll(HashSet<Integer> big, HashSet<Integer> small) {
		Iterator it = small.iterator();
		
		boolean isContainsAll=true;
		while (it.hasNext()) {
			if (!big.contains(it.next())) {
				isContainsAll=false;
			}
		}
		return isContainsAll;
	}

	public boolean checkCandidateKey(HashSet<Integer> keySet, String[][] relation) {
		HashSet<String> set = new HashSet<String>();
		for (int i = 0; i < relation.length; i++) {
			StringBuilder sb = new StringBuilder("");
			Iterator<Integer> it = keySet.iterator();
			while (it.hasNext()) {
				int key = it.next();
				sb.append(relation[i][key] + " ");
			}
			String newString = sb.toString();
			if (set.contains(newString)) {
				return false;
			}

			set.add(newString);
		}
		return true;
	}
}
```

