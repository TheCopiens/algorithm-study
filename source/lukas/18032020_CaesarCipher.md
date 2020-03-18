프로그래머스 문제
=================

-	시저암호
	-	https://programmers.co.kr/learn/courses/30/lessons/12926

### 풀이 방법

#### 문제 접근 방법

-	Caesar Cipher

#### 접근 방법을 적용한 코드

```java
class Solution {
  public String solution(String s, int n) {
      String answer = "";
      for (char ch : s.toCharArray()) {
          if (Character.isLetter(ch)) {
              if (Character.isUpperCase(ch)) {
                  answer += (char) ((ch + n - 'A') % 26 + 'A');
              } else {
                  answer += (char) ((ch + n - 'a') % 26 + 'a');
              }
          }
          else {
              answer += " ";
          }
      }
      return answer;
  }
}

```

```haskell
import Data.Char

caesar :: Int -> Char -> Char
caesar k c | isAsciiUpper c  = chr ((ord c + k - ord 'A')`mod` 26 + ord 'A')
           | isAsciiLower c = chr ((ord c + k - ord 'a')`mod` 26 + ord 'a')
           | otherwise = c


garble :: String -> String
garble xs = [caesar 2 x | x <- xs]

ungarble :: String -> String
ungarble xs = [caesar (-2) x | x <- xs]
-- caeasar 24
```
