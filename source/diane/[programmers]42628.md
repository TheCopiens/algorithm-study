# Programmers 이중우선순위큐 문제

- 이중우선순위큐
    - https://programmers.co.kr/learn/courses/30/lessons/42628

### 문제 이해하기
이중우선순위큐는 연산의 목록을 받는다. 
그 연산은 세 가지 종류로, 큐에 숫자를 추가하거나, 큐에서 최댓값 또는 최솟값을 제거한다.
이중우선순위큐가 이 연산을 모두 실행한 후의 큐의 최댓값과 최솟값을, 큐가 비어있다면 0,0을 반환한다.
모든 연산은 숫자 하나만을 대상으로 하고, 만약 큐가 비어있는데 값을 삭제해야한다면, 그 연산은 무시한다.

#### 입력
- String[] operations : 연산의 목록
    - 각 연산은 첫 글자로 알파벳 I 또는 D가 오고, 띄어쓰기 후 I라면 모든 숫자, D라면 1 또는 -1이 온다.
    - 연산의 의미
        - I 숫자 : 큐에 이 숫자를 추가
        - D 1 : 큐에서 최댓값 삭제
        - D -1 : 큐에서 최솟값 삭제

#### 출력
- int[] : 크기 2의 숫자 배열로, 첫 원소는 이 큐의 최댓값, 마지막 원소는 이 큐의 최소값.
    - 만약 큐가 비어있다면, [0,0]을 반환.

### 문제 접근 방법
"이중우선순위큐"이지만, FIFO과는 관계가 없다.
또한 원소들의 순서는 전혀 관계없고, 그때그때 최솟값과 최댓값만 알면 되기 때문에,
자료구조로 minHeap과 maxHeap을 동시에 사용했다.

모든 연산에 대해 순서대로 아래 행동을 반복한다.
- I 숫자 : minHeap과 maxHeap에 이 숫자를 추가한다.
- D 1  : maxHeap에서 최댓값을 제거하고, minHeap에서 동일한 값을 제거한다.
- D -1 : minHeap에서 최솟값을 제거하고, maxHeap에서 동일한 값을 제거한다.
모든 연산을 수행했다면, maxHeap에서 최댓값을, minHeap에서 최솟값을 찾아 반환한다.
만약 힙의 크기가 0이라면, 최댓값과 최솟값으로 0을 반환한다.

### 구현 배경 지식
MinHeap, MaxHeap

### 문제를 해결한 코드
~~~java
import java.util.Collections;
import java.util.PriorityQueue;

public class Solution {
    PriorityQueue<Integer> minHeap;
    PriorityQueue<Integer> maxHeap;

    public Solution() {
        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
    }

    public int[] solution(String[] operations) throws Exception {
        int[] answer = new int[2];

        for (String operation : operations) {
            String[] commands = operation.split(" ");
            if (commands[0].equals("I")) {
                int number = Integer.parseInt(commands[1]);
                minHeap.add(number);
                maxHeap.add(number);
            } else if (commands[0].equals("D")) {
                if (minHeap.size() < 1) continue;
                if (commands[1].equals("1")) {
                    int number = maxHeap.poll();
                    minHeap.remove(number);
                } else if (commands[1].equals("-1")) {
                    int number = minHeap.poll();
                    maxHeap.remove(number);
                } else {
                    throw new Exception("Invalid operation : "+operation);
                }
            } else {
                throw new Exception("Invalid operation : "+operation);
            }
        }
        if (maxHeap.size() != 0) {
            answer[0] = maxHeap.peek();
            answer[1] = minHeap.peek();
        }

        return answer;
    }
}
~~~