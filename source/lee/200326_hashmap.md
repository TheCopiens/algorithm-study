# Ransom Note
https://www.hackerrank.com/challenges/ctci-ransom-note/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

## 문제 접근 방법
Map에 key=magazine[i], value=단어 개수를 저장함
1. magazine의 단어를 map에 저장
2. note에 나온 단어가 map에 있는지 확인
3. 하나라도 없으면 `No`출력, 전부 있으면 `Yes`출력

## 코드 구현
```java
class Solution {
    static void checkMagazine(String[] magazine, String[] note) {
         Map<String, Integer> map = new HashMap<>();
        for (String word: magazine) {
            if (map.containsKey(word)) map.replace(word, map.get(word)+1);
            else map.put(word,1);
        }

        for (String word: note) {
            if (!map.containsKey(word)) {
                System.out.println("No");
                return;
            } else {
                if (map.get(word)==1) map.remove(word);
                else map.replace(word, map.get(word)-1);
            }
        }

        System.out.println("Yes");
    }
}
```

### Time complexity
O(n+m) n=note.length, m=magazine.length

### Space complexity
O(n+m) n=note.length, m=magazine.length
