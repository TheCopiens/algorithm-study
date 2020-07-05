프로그래머스 스택/큐 문제
=========================

-	타워
	-	https://programmers.co.kr/learn/courses/30/lessons/42588

### 풀이 방법

#### 문제 접근 방법

-	수신하는 탑은 언제나 송신하는 탑의 왼쪽에 위치하며 수신된 신호는 다시 송신되지 않는다
	-	배열에 두개의 포인터 (두개의 for문) 를 이용해 구현 가능 하나 LIFO의 Stack 구조를 활용하여 문제를 풀 수 있다.
-	스택에 들어가는 Tower 클래스를 만들어 탑의 index와 height를 저장  

#### 접근 방법을 적용한 코드

```java
import java.util.Stack;

class Solution {
    class Tower {
        int index;
        int height;

        public Tower(int index, int height) {
            this.index = index;
            this.height = height;
        }
    }

    public int[] solution(int[] heights) {

        Stack<Tower> st = new Stack<>();
        int[] answer = new int[heights.length];

        for (int i = 0; i < heights.length; i++) {

            Tower tower = new Tower(i + 1, heights[i]);
            int receiverIndex = 0;

            while (!st.isEmpty()) {
                Tower left = st.peek();

                if (left.height > tower.height) {
                    receiverIndex = left.index;
                    break;
                }

                st.pop();
            }

            st.push(tower);
            answer[i] = receiverIndex;
        }

        return answer;
    }
}
```
