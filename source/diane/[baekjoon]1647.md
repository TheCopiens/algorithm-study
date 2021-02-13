# Baekjoon 도시 분할 계획 문제

- 도시 분할 계획
    - https://www.acmicpc.net/problem/1647

### 문제 이해하기
N개의 집과 이 집들 사이를 잇는 M개의 길이 있는 마을이 있다.
이 길은 양쪽 방향 모두로 다닐 수 있고, 길을 유지하는데 드는 유지비가 있다.
이 마을을 두 개의 분리하려고 한다.
각 마을에 있는 집들은 모두 연결되어야 하는데, 유지비가 최소가 되게끔만 길을 남기려고 한다.
두 마을은 서로 다른 마을과는 연결되지 않는다.
이 때 이 마을들의 길 유지비의 최솟값을 구하라.

#### 입력
- int N, M : 집의 개수, 길의 개수
    - N : integer, such that 2 <= N <= 100,000
    - M : integer, such that 1 <= M <= 1,000,000
- int 3개 * M : 길이 연결하는 집의 번호 두 개, 그 길의 유지비
    - 길의 유지비 C : integer, such that 1 <= C <= 1,000

#### 출력
- int : 남은 길의 유지비의 합의 최솟값

### 문제 접근 방법
길의 유지비를 최소로 하도록 마을을 둘로 나누는 것은,
기존 마을을 MST로 만든 다음 가장 유지비가 큰 길을 없애서 나누면 원하는 조건대로 만들 수 있다.

길의 갯수가 주어지고, Prim 알고리즘으로 풀기에는 각 집을 지나는 길을 찾는데 비용이 들어,
이보다는 Kruskal로 푸는 것이 유리하다고 판단했다.

먼저 모든 길을 유지비의 오름차순으로 정렬한다.
유지비가 적은 길부터 차례대로, 길의 양쪽 집이 이미 연결되어 있는지 확인하고, 연결되어 있지 않으면 이 길을 선택한다.
선택한 길이 N-1개라는 것은 MST를 만들었다는 것이기 때문에, 
이 때는 마지막으로 찾은 길을 포함하지 않고 (마을을 둘로 만들어야 하니까) 지금까지 선택한 길의 유지비의 합을 출력한다.

길의 양쪽 집이 이미 연결되어 있는지를 확인할 때는,
union-find 알고리즘을 사용하였다.


### 구현 배경 지식
- MST (Kruskal Algorithm)
- Union-Find

### 문제를 해결한 코드
~~~java
import java.util.*;

public class Main {
    private static int N;
    private static int M;
    private static int[] disjointSet;

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt(); // vertex
        M = sc.nextInt(); // edge

        ArrayList<Path> paths = new ArrayList<>();
        for (int i=0; i<M; i++) {
            int h1 = sc.nextInt();
            int h2 = sc.nextInt();
            int c = sc.nextInt();
            paths.add(new Path(h1, h2, c));
        }

        disjointSet = new int[N+1];
        for (int i=1; i<N+1; i++) disjointSet[i] = i;

        int cost = 0;
        int recent = 0;
        Collections.sort(paths);

//        while (!paths.isEmpty()) {
//            Path p = paths.remove(0);
        for (int i=0; i<paths.size(); i++) {
            Path p = paths.get(i);
            if (find(p.house1) != find(p.house2)) {
                recent++;
                if (recent == N-1) break;
                cost = cost + p.cost;
                union(p.house1, p.house2);
            }
        }

        System.out.println(cost);
    }

    private static int find(int x) {
        if (disjointSet[x] == x) return x;
        return disjointSet[x] = find(disjointSet[x]); // Path Compression
    }

    private static void union(int x, int y) {
        x = find(x);
        y = find(y);

        disjointSet[y] = x;
    }

}

class Path implements Comparable<Path> {
    public int house1;
    public int house2;
    public int cost;

    Path(int h1, int h2, int c) {
        house1 = h1;
        house2 = h2;
        cost = c;
    }

     @Override
     public int compareTo(Path b) {
         return this.cost - b.cost;
     }
}
~~~

### 새로 알게 된 내용
ArrayList의 remove 함수가 굉장히 시간적 cost가 큰 로직이라는 것을 새로 알게 되었다.
초기에는 길을 선택할 때, 유지비로 정렬한 다음 리스트의 가장 첫 원소를 가져오고 삭제하고 이를 반복했는데,
이 때는 시간 초과가 발생한다.
이 후 길의 리스트를 돌면서 get으로 길을 가져오도록 변경하자, 알고리즘은 동일하지만, 시간 초과 없이 성공했다.
이는 두 함수의 로직 차이에서 기인한다.
remove 함수는 그 원소를 제거한 후에 그 뒤의 원소를 모두 한 칸 씩 앞으로 새로 저장하기 때문에 눈에 띄게 오래 걸리는 것이다.
```java
    public E get(int index) {
        rangeCheck(index);

        return elementData(index);
    }

    public E remove(int index) {
        rangeCheck(index);

        modCount++;
        E oldValue = elementData(index);

        int numMoved = size - index - 1;
        if (numMoved > 0)
            System.arraycopy(elementData, index+1, elementData, index,
                             numMoved);
        elementData[--size] = null; // clear to let GC do its work

        return oldValue;
    }
```