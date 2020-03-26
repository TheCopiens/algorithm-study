프로그래머스 스택/큐 문제
=========================

-	쇠막대
	-	https://programmers.co.kr/learn/courses/30/lessons/42585

### 풀이 방법

#### 문제 접근 방법

-	왼쪽 괄호를 세어가며 오른쪽 괄호가 나올 때 마다 계산
	-	increment 만으로도 가능하나 Stack으로도 구현 할 수 있음
-	레이저일 경우 그 전 왼쪽 괄호의 수 만큼 (=쇠 막대기 수 만큼)의 값을 잘린 조각 들의 수에 포함
-	쇠 막대기일 경우 한 쇠막대기의 총 잘린 조각 = 레이저의 수 + 1 이므로 +1 씩 추가

#### 접근 방법을 적용한 코드

```java
import java.util.Stack;

class Solution {
     public static int solution(String arrangement) {
        int splitted = 0;

        Stack<Character> st = new Stack<>();

        for(int i = 0; i < arrangement.length(); i++) {
            char c = arrangement.charAt(i);
            if(c == '(') {
                st.push(c);
            }else {
                if(arrangement.charAt(i-1) == '(') { // if a laser
                st.pop();
                splitted += st.size(); // applys a laser-splitting to every pipe

                } else { // if the pipe's right-end
                st.pop();
                splitted += 1; // num of the splitted = num of lasers to the pipe + 1
                }
            }
        }
        return splitted;
    }
}
```
