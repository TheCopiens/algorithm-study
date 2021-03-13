# Baekjoon 구간 합 구하기

- 구간 합 구하기
    - https://www.acmicpc.net/problem/2042

### 문제 이해하기
N개의 숫자가 주어져 있다. 이 N개의 숫자를 가지고, 이 중 특정한 수의 값을 바꾸거나, 이 중 특정 구간의 수들의 합을 구하는 작업을 하려고 한다.
수의 값을 바꾸고, 구간의 합을 구하는 작업이 들어올 때, 이를 작업이 들어올 때마다 실행하며, 합을 구하면 그 값을 반환해라.

#### 입력
- int N M K : 주어진 숫자의 갯수, 수의 변경이 일어나는 횟수, 구간의 합을 구하는 횟수
- long NUM : N번 반복하면서 주어진 숫자를 입력
- int A B (long) C : (M+K)번 반복
    - A==1 : 수의 변경, B번째 수를 C의 값으로 바꾸어야 한다.
    - A==2 : 구간의 합, B번째 수부터 C번째 수까지의 합을 구하고 출력한다.

#### 출력
- int : K번 반복하면서, 구간의 합을 출력

### 문제 접근 방법
주어진 숫자 배열로 먼저 segment tree를 만든다.
이후로는 숫자의 값을 바꿀 때는 tree의 root부터 값의 변화량을 적용시키면서, 해당 index의 leaf의 값까지 변화시킨다.
구간의 합을 구할 때는 tree의 root부터 검색하면서, 원하는 구간에 해당하는 node의 값을 더하여 합을 구한다.


### 구현 배경 지식
- Segment Tree

주어진 숫자의 갯수가 N, 수의 변경이 M번, 구간 합을 K번 구한다고 가정하자.

| 작업 | 일반 | segment tree |
|-----|:----:|:------------:|
|값 변경하기|O(1)|O(logN)|
|구간 합 구하기|O(N)|O(logN)|
|모든 작업|O(NK)|O((M+K)logN)|

작업의 수(K)가 많을수록, 주어진 숫자의 갯수(N)이 많을수록, segment tree가 유리하다.


### 문제를 해결한 코드
~~~java
import java.util.Scanner;

public class Main {
    private static long[] array;
    private static long[] segTree;

    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int K = sc.nextInt();

        array = new long[N];
        for (int i=0; i<N; i++) {
            array[i] = sc.nextLong();
        }
        makeSegTree();

        for (int i=0; i<M+K; i++) {
            int flag = sc.nextInt();

            if (flag == 1) {
                int idx = sc.nextInt()-1;
                long value = sc.nextLong();

                long diff = value - array[idx];
                array[idx] = value;
                updateSegTree(idx, diff, 1, 0, array.length-1);

            } else if (flag == 2) {
                int start = sc.nextInt()-1;
                int end = sc.nextInt()-1;

                long result = sumSegTree(1, 0, array.length-1, start, end);
                System.out.println(result);

            } else {
                throw new Exception("Wrong flag!");
            }
        }

    }

    private static void makeSegTree() {
        double height = Math.ceil(Math.log(array.length)/Math.log(2.0));
        int treeSize = (int) Math.pow(2.0, height+1);
        segTree = new long[treeSize];
        initSegTree(1,0, array.length-1);
    }

    private static long initSegTree(int node, int start, int end) {
        if (start == end) return segTree[node] = array[start];
        int mid = (start+end)/2;
        return segTree[node] = initSegTree(node*2, start, mid)+initSegTree(node*2+1, mid+1, end);
    }

    private static void updateSegTree(int index, long diff, int node, int start, int end) {
        if (index < start || index > end) return;

        segTree[node] += diff;
        if (start == end) return;
        int mid = (start+end)/2;
        updateSegTree(index, diff, node*2, start, mid);
        updateSegTree(index, diff, node*2+1, mid+1, end);
    }

    private static long sumSegTree(int node, int start, int end, int left, int right) {
        if (left > end || right < start) return 0;
        if (left <= start && end  <= right) return segTree[node];
        int mid = (start+end)/2;
        return sumSegTree(node*2, start, mid, left, right) + sumSegTree(node*2+1, mid+1, end, left, right);
    }
}
~~~