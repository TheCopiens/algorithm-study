# 프로그래머스 연습 문제
- 시저 암호
    - https://programmers.co.kr/learn/courses/30/lessons/12926

## 문제 접근 방법
1. 0~25까지 대소문자에 1:1 대응하도록 배열을 만듦   
2. 현재 알파벳 cur과 1:1 대응하는 숫자는 소문자의 경우 'a', 대문자의 경우 'A'를 빼면 얻을 수 있음   
3. 현재 알파벳에 n만큼 더한 숫자가 26이상일 경우 다시 처음부터 돌아가야하기 때문에 % 연산 사용

## 코드 구현
```java
import java.util.*;

public class Solution {
    char[] lowerLetter = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char[] upperLetter = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    public String solution(String s, int n) {
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char cur = s.charAt(i);

            if (cur == ' ') {
                answer.append(' ');
                continue;
            }
            int idx;
            if (Character.isLowerCase(cur)) {
                idx = (cur - 'a' + n) % 26;
                answer.append(lowerLetter[idx]);
            } else {
                idx = (cur - 'A' + n) % 26;
                answer.append(upperLetter[idx]);
            }
        }
        return answer.toString();
    }
}

```
