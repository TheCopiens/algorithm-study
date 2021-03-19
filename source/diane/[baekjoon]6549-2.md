# Baekjoon 히스토그램에서 가장 큰 직사각형

- 히스토그램에서 가장 큰 직사각형
    - https://www.acmicpc.net/problem/6549

### 문제 이해하기
히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형으로, 이 직사각형은 모두 같은 너비를 가지고 있지만 높이는 서로 다르다.
이 때 이 히스토그램에서 그릴 수 있는 직사각형 중 가장 넓이가 큰 직사각형의 넓이를 구하여라.

#### 입력
- int N A1 A2 ... AN : 직사각형의 수와 높이 (여러 벌)
    - N : 직사각형의 갯수
    - A1 ... AN : 직사각형의 높이
- 0 : 입력의 끝

#### 출력
- int : 히스토그램에서 가장 넓이가 큰 직사각형의 넓이 (입력의 수 만큼)

### 문제 접근 방법
먼저 주어진 히스토그램으로 segment tree를 만든다.
이 때 각 노드는 히스토그램에서 그 노드의 구간만을 보았을 때, 그 너비로 만들 수 있는 가장 큰 직사각형의 정보를 담을 것이다.
따라서, 그 너비(number)와 가장 큰 직사각형의 높이(height), 그리고 이 높이를 가지는 직사각형의 인덱스(index) 정보를 가진다.
두 노드의 부모 노드는, 이 두 노드가 가진 구간에서 그 너비로 만들 수 있는 가장 큰 직사각형의 정보를 담아야 하기 때문에,
너비는 자식 노드 둘의 너비의 합이고, 높이는 두 자식 노드가 가진 높이 중에 작은 것, 인덱스는 더 작은 높이를 가진 자식 노드가 가졌던 인덱스를 가진다.

segment tree가 다 만들어지면, 이를 이용해서 전체 히스토그램에서의 가장 큰 직사각형을 찾을 것이다.
가장 간단한 방법은 완전 탐색이지만, 이는 O(N^2)의 시간 복잡도를 가지므로 주어진 시간 안에 찾지 못할 수도 있다.
따라서 Divide and Conquer 방식을 사용한다.
먼저 전체 너비로 만들 수 있는 가장 큰 직사각형의 넓이를 구한다.
이 직사각형의 높이는 이 너비에 있는 각 직사각형의 높이 중 가장 작은 것이다.
이 가장 작은 직사각형을 중심으로 그 왼쪽 구간과 오른쪽 구간으로 나누어 그 넓이를 구하고,
또 이 때 가장 작은 직사각형을 찾아 구간을 나누어 넓이를 구하는 과정을 반복한다.
가장 작은 높이가 포함되어 있다면, 현재 구한 너비가 가장 큰 너비이기 때문에, 이 높이의 직사각형을 제하고 양 옆으로 구간을 나누는 것이다.
이렇게 구한 직사각형의 넓이 중 가장 큰 것이, 전체 히스토그램에서 그릴 수 있는 가장 넓이가 큰 직사각형이다.


### 구현 배경 지식
- Segment Tree + Divide and Conquer

### 문제를 해결한 코드
~~~java
import java.util.Scanner;

public class Main {
    private static long[] array;
    private static Node[] segTree;

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String testCase = null;

        while (true) {
            testCase = sc.nextLine();
            if (testCase.equals("0")) break;

            array = convert(testCase);
            System.out.println(solution());
        }

    }

    private static long solution() {
        segTree = makeSegTree();
        init(1,0,array.length-1);

/* 완전 탐색으로 접근하여 시간 초과가 난 풀이
        int maxArea = Integer.MIN_VALUE;
        for (int i=array.length-1; i>0; i--) {
            for (int j=0; j<array.length-i; j++) {
                Node temp = findArea(1,0, array.length-1, j, j+i);
                int area = temp.area;
                if (area > maxArea) maxArea = area;
            }
        }
*/
        return getBiggerArea(0, array.length-1);
    }

    private static Node[] makeSegTree() {
        double height = Math.ceil(Math.log(array.length)/Math.log(2.0));
        int treeSize = (int) Math.pow(2.0, height+1);
        return new Node[treeSize];
    }

    private static Node init(int node, int start, int end) {
        if (start == end) return segTree[node] = new Node(array[start], 1, start);
        int mid = (start+end)/2;
        Node n1 = init(node*2, start, mid);
        Node n2 = init(node*2+1, mid+1, end);
        long height = n1.height;
        int index = n1.index;
        if (n1.height > n2.height) {
            height = n2.height; index = n2.index;
        }
        return segTree[node] = new Node(height, n1.number+n2.number, index);
    }

    private static long getBiggerArea(int start, int end) {
        Node node = findArea(1,0, array.length-1, start, end);
        long area = node.area;
        if (node.index == -1) return area;
        if (start < node.index) {
            long temp = getBiggerArea(start, node.index-1);
            if (temp > area) area = temp;
        }
        if (end > node.index) {
            long temp = getBiggerArea(node.index+1, end);
            if (temp > area) area = temp;
        }
        return area;
    }

    private static Node findArea(int node, int start, int end, int left, int right) {
        if (left > end || right < start) return new Node(0,0, -1);
        if (left <= start && end <= right) {
            return segTree[node]==null? new Node(0,0, -1):segTree[node];
        }
        int mid = (start+end)/2;
        Node n1 = findArea(node*2, start, mid, left, right);
        Node n2 = findArea(node*2+1, mid+1, end, left, right);
        long height = n1.height;
        int index = n1.index;
        if (n1.height == 0) {
            if (n2.height == 0) {
                height = 0;
                if (n1.index == -1) index = n2.index;
                else if (n2.index == -1) index = n1.index;
                else index = (n1.index>n2.index)?n2.index:n1.index;
            } else if (n1.index == -1){
                height = n2.height; index = n2.index;
            } else {
                height = n1.height; index = n1.index;
            }
        } else if (n2.index == -1) {
            height = n1.height; index = n1.index;
        } else if (n2.height == 0) {
            height = n2.height; index = n2.index;
        } else if (n1.height > n2.height){
            height = n2.height; index = n2.index;
        }
        return new Node(height, n1.number+n2.number, index);
    }

    private static long[] convert(String array) {
        String[] temp = array.split(" ");
        long[] result = new long[temp.length-1];
        for (int i=1; i<temp.length; i++)
            result[i-1] = Long.parseLong(temp[i]);
        return result;
    }

    private static void printSegTree() {
        System.out.println("-------------------");
        for (int i=1; i<segTree.length; i++) {
            Node node = segTree[i];
            if (node == null) continue;
            System.out.println(i+" "+node.toString());
        }
        System.out.println("-------------------");
    }
}

class Node {
    public int number;
    public long height;
    public long area;
    public int index;

    Node(long h, int n, int i) {
        number = n;
        height = h;
        area = n*h;
        index = i;
    }

    @Override
    public String toString() {
        return "{" + number + "," + height + " : " + area +"} "+index;
    }
}
~~~