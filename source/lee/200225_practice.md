# 프로그래머스 스택/큐 문제
- 시저 암호
    - https://programmers.co.kr/learn/courses/30/lessons/12926

## 풀이 방법
TBD

### 문제 접근 방법
TBD

### 코드 구현
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
