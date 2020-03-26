프로그래머스 스택/큐 문제
=========================

-	다리를 지나는 트럭
	-	https://programmers.co.kr/learn/courses/30/lessons/42583

### 풀이 방법

#### 문제 접근 방법

-	트럭이 대기 하고있는 일차선과 다리를 각각 큐로 구현
-	일차선과 다리에 트럭이 더 이상 없을때 까지 순차적으로 반복
-	일차선, 다리에 들어가는 Truck 클래스를 만들어 무게와 다리에 머무는 시간을 저장 (경과 시간 1 부터 트럭이 다리에 들어감에 유의)

#### 접근 방법을 적용한 코드

```java
import java.util.LinkedList;
import java.util.Queue;

class Truck {
    int weight;
    int timeInBridge;

    public Truck(int weight) {
        this.weight = weight;
        this.timeInBridge = 1;
    }

    public void move() {
        this.timeInBridge++;
    }
}

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {

        Queue<Truck> waiting = new LinkedList<>();
        Queue<Truck> bridge = new LinkedList<>();
        int currentWeight = 0;
        int elapsedTime = 0;

        for (int w : truck_weights) {
            waiting.add(new Truck(w));
        }

        while (!waiting.isEmpty() || !bridge.isEmpty()) {
            elapsedTime++;

            if(bridge.isEmpty()) {
                Truck in = waiting.poll();
                bridge.add(in);
                currentWeight += in.weight;
                continue;
            }

            for (Truck t : bridge) {
                t.move();
            }

            if(bridge.peek().timeInBridge > bridge_length) {
                Truck out = bridge.poll();
                currentWeight -= out.weight;
            }

            if(!waiting.isEmpty() && waiting.peek().weight + currentWeight <= weight) {
                Truck following = waiting.poll();
                bridge.add(following);
                currentWeight += following.weight;
            }
        }
        return elapsedTime;
    }
}
```
