# Programmers 네트워크 문제

- 네트워크
    - https://programmers.co.kr/learn/courses/30/lessons/43162

### 문제 이해하기
컴퓨터가 직접적으로, 또는 다른 컴퓨터를 통해 다른 컴퓨터와 통신이 가능할 때 그 컴퓨터들이 동일한 네트워크에 있다고 말한다.
컴퓨터의 직접 연결 정보가 주어졌을 때, 이 컴퓨터의 네트워크가 모두 몇 개가 구성되는지 구한다.

### 문제 접근 방법
1. 각 컴퓨터에 대해서 같은 네트워크에 있는 컴퓨터를 그 컴퓨터의 네트워크에 추가한다.
2. 한 컴퓨터에 대해서 연결된 컴퓨터를 같은 네트워크에 추가하고, 네트워크에 추가된 모든 컴퓨터와 연결된 컴퓨터를 네트워크에 추가하는 것을 반복한다. 네트워크에 컴퓨터 추가가 끝나면, 아직 네트워크에 추가되지 않은 컴퓨터를 찾아 새로운 네트워크를 만들고 반복한다.

### 구현 배경 지식
DFS

### 문제를 해결한 코드
~~~java
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class Solution {
    private int size;
    private int[][] connections;
    private boolean[] flags;

    public int solution(int n, int[][] computers) {
        size = n;
        connections = computers;
        flags = new boolean[n];
        ArrayList<Set<Integer>> networks = new ArrayList<>();

        while (checkFlag()) {
            int start = getFirstRemainder();
            System.out.println(start);
            Set<Integer> network = dfs(start);
            networks.add(network);
        }
        return networks.size();
    }

    private boolean checkFlag() {
        boolean result = true;
        int idx = 0;
        while (result) {
            if (idx >= flags.length) break;
            result = result && flags[idx];
            idx++;
        }
        return !result;
    }

    private int getFirstRemainder() {
        for (int i=0; i<flags.length; i++) {
            if (!flags[i]) return i;
        }
        return -1;
    }

    private Set<Integer> dfs(int start) {
        Set<Integer> network = new HashSet<>();

        flags[start] = true;
        for (int i=0; i<size; i++) {
            if (connections[start][i] == 1) {
                network.add(i);
                if (!flags[i]) {
                    network.addAll(dfs(i));
                }
            }
        }

        return network;
    }
}
~~~

