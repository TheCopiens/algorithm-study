# 프로그래머스 연습문제
- 시저 암호
    - https://programmers.co.kr/learn/courses/30/lessons/12926

### 비슷한 문제
- [수박수?](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/200206_string2.md#%EC%88%98%EB%B0%95%EC%88%98)
- [모의고사](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/200128_%EC%99%84%EC%A0%84%ED%83%90%EC%83%89.md#%EB%AA%A8%EC%9D%98%EA%B3%A0%EC%82%AC)

### 접근 방법을 적용한 코드
```java
import java.util.*;
class Solution {
  public String solution(String s, int n) {
      String answer = "";
      String alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      String alphabet_lower = "abcdefghijklmnopqrstuvwxyz";
      String[] apb_up = alphabet_upper.split("");
      String[] apb_low = alphabet_lower.split("");
      String[] str = s.split("");
      StringBuffer sb = new StringBuffer();
      
      for(int i=0 ; i<str.length ; i++){
          String e = " ";
          for(int j=0 ; j<apb_up.length ; j++){
              if(str[i].equals(apb_up[j]))
                  e = apb_up[(j+n)%26];
              if(str[i].equals(apb_low[j]))
                 e = apb_low[(j+n)%26];
          }
          sb.append(e);
      }
      return sb.toString();
  }
}
```