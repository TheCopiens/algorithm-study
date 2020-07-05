프로그래머스 스택/큐 문제
=========================

-	주식가격
	-	https://programmers.co.kr/learn/courses/30/lessons/42584

### 풀이 방법

#### 문제 접근 방법

-	타워 스택 문제와 마찬가지로 두개의 for 문 만으로도 구현 가능하나 Stack 구조를 활용해 구현
-	주식 가격 배열의 index를 차례로 스택에 쌓으며 다음 index에 가격이 하락 되는지 확인
	-	하락 시 다음 index - 하락 전 index
	-	유지 또는 상승됬을 시 배열 끝까지의 유지/상승 되는 시간 그대로

#### 접근 방법을 적용한 코드

```java
import java.util.Stack;

class Solution {
    public int[] solution(int[] prices) {

        Stack<Integer> st = new Stack<>();
        int[] answer = new int[prices.length];

        for (int i = 0; i < prices.length; i++) {
            while (!st.empty() && prices[i] < prices[st.peek()]) {
                int index = st.pop();
                answer[index] = i - index;
                }
            st.push(i);
        }
        while (!st.empty()) {
            int index = st.pop();
            answer[index] = (prices.length - 1) - index;
        }

    return answer;
    }
}
```
