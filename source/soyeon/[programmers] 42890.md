# 프로그래머스 문제

- 후보키
    - https://programmers.co.kr/learn/courses/30/lessons/42890
    
### 문제 이해하기

### 문제 접근 방법

### 구현 배경 지식

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

### 해결하지 못한 이유

### 문제를 해결한 코드
```java
```

### 문제를 해결한 방법


