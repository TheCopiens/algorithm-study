# Baekjoon 트리 문제

- 트리
    - https://www.acmicpc.net/problem/4256

### 문제 이해하기
어떤 이진 트리가 주어진다. 이 이진 트리는 노드 n개로 이루어져있고, 각 노드는 1부터 n까지의 유일한 번호를 가지고 있다.
이 이진 트리를 전위 순회(preorder)한 결과와 중위 순회(inorder)한 결과가 주어졌을 때,
후위 순회(postorder)한 결과를 구하여라.

#### 입력
- int T : 테스트케이스 개수
    - 이 아래 입력은 테스트케이스 개수만큼 반복됨
- int n : 이진 트리의 노드 갯수
- int o1, o2, ... , on : 이진 트리를 전위 순회한 결과
- int o1, o2, ... , on : 이진 트리를 중위 순회한 결과

#### 출력
- int o1, o2, ... , on : 이진 트리를 후위 순회한 결과 (테스트케이스 개수 만큼)

### 문제 접근 방법
주어진 전위 순회 결과와 중위 순회 결과를 가지고 이진 트리를 복원한 다음 이 이진 트리를 후위 순회한 결과를 출력한다.

먼저, 전위 순회 결과와 중위 순회 결과로 이진 트리를 복원해야 한다.
전위 순회는 root 노드를 먼저 출력하고, 그 노드의 왼쪽 자식 노드로 가 전위 순회하고, 이후에 오른쪽 자식 노드로 가 전위 순회한다.
따라서 전위 순회 결과는 언제나 (root 노드) (그 노드의 왼쪽 자식 노드가 root인 트리를 전위 순회한 결과) (그 노드의 오른쪽 자식 노드가 root인 트리를 전위 순회한 결과)이다.
중위 순회는 왼쪽 자식 노드를 중위 순회한 결과를 출력하고, 그 노드를 출력한 다음, 오른쪽 자식 노드를 중위 순회한 결과를 출력한다.
따라서 중위 순회 결과는 언제나 (그 노드의 왼쪽 자식 노드가 root인 트리를 중위 순회한 결과) (root 노드) (그 노드의 오른쪽 자식 노드가 root인 트리를 중위 순회한 결과)이다.

이진 트리를 복원할 때는 분할 정복을 사용한다.
전위 순회 결과를 통해 트리의 root 노드를 찾은 다음, 그 root 노드를 중위 순회 결과에서 찾으면, 그 노드를 중심으로 왼쪽에 위치한 모든 노드와 오른쪽에 위치한 모든 노드를 찾을 수 있다.
전위 순회 결과에서 root 노드 이후에는 그 노드를 중심으로 왼쪽에 위치한 모든 노드가 나오고 그 뒤에 오른쪽에 위치한 모든 노드가 나온다.
따라서 중위 순위 결과에서 찾을 수 있는 왼쪽에 위치한 모든 노드를 대상으로, 왼쪽의 이진 트리를 복원하고,
그 후에 오른쪽에 위치한 모든 노드를 대상으로 오른쪽의 이진 트리를 복원하는 과정을 반복할 것이다.
즉 root 노드를 찾은 후에, 그 root 노드의 왼쪽 자식을 root로 하는 이진 트리를 만들고, 오른쪽 자식을 root로 하는 이진 트리를 만드는 것이다.
전체의 이진 트리를 만드는 것이 기본 문제(problem)이고, root 노드의 왼쪽 또는 오른쪽 자식 노드를 root로 하는 이진 트리를 만드는 것이 하위 문제(sub problem)인 것이다.

이 과정에서 전위 순회 결과는 앞에서부터 순서대로 출력되므로, queue를 사용하기에 알맞으며,
중위 순회 결과는 하위 문제로 갈 때, root 노드를 기준으로 왼쪽 부분과 오른쪽 부분으로 분할되게 된다.

이진 트리가 전부 만들어지면, 이제 이를 후위 순회하며 그 결과를 출력한다.
후위 순회는 root 노드에서 먼저 왼쪽 자식 노드를 root로 하는 트리에서 후위 순회를 하고, 이후에 오른쪽 자식 노드를 root로 하는 트리에서 후위 순회를 한 다음에 root 노드를 출력한다.



### 구현 배경 지식
- 트리와 이진 트리
- 이진 트리의 순회 방법
    - preorder : root -> left -> right
    - inorder : left -> root -> right
    - postorder : left -> right -> root
    
- 분할 정복 divide and conquer

### 문제를 해결한 코드
~~~java
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    private static Queue<Integer> preorder;
    private static ArrayList<Integer> inorder;
    private static int size;

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int testcase = sc.nextInt();

        for (int t=0; t<testcase; t++) {
            size  = sc.nextInt();

            preorder = new LinkedList<>();
            inorder = new ArrayList<>();
            for (int i=0; i<size; i++) preorder.add(sc.nextInt());
            for (int i=0; i<size; i++) inorder.add(sc.nextInt());

            Node root = makeTree(0, size);

            printPostOrder(root);
            System.out.println();
        }

    }

    private static Node makeTree(int in1, int in2) {
        if (preorder.size() < 1) return null;

        int number = preorder.poll();
        int index = inorder.indexOf(number);

        Node node = new Node(number);
        if (index > in1) {
            Node left = makeTree(in1, index);
            node.left = left;
        }
        if (index < in2-1) {
            Node right = makeTree(index+1, in2);
            node.right = right;
        }

        return node;
    }

    private static void printPostOrder(Node n) {
        if (n == null) return;
        if (n.left != null) {
            printPostOrder(n.left);
        }
        if (n.right != null) {
            printPostOrder(n.right);
        }
        System.out.print(n.index+" ");
    }
}

class Node {
    public Node left;
    public Node right;
    public int index;

    public Node(int n) {
        index = n; left = null; right = null;
    }

    @Override
    public String toString() {
        int l = (left==null)? 0 : left.index;
        int r = (right==null)? 0 : right.index;
        return "Node{" + index+" : "+l+" "+r+"}";
    }
}
~~~