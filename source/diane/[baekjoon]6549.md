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
가장 넓이가 큰 직사각형은 히스토그램을 이루는 직사각형의 하나의 높이를 가지고 있을 것이다.
히스토그램의 직사각형의 높이를 차례대로 받으면서, 각 높이로 만들 수 있는 가장 큰 직사각형을 만들 것이다.
직사각형을 앞에서 뒤로 지나가면서 차례로 높이와 그 직사각형의 index를 받아 stack에 쌓는다.
만약 지금 받은 직사각형의 높이가 이전 직사각형의 높이보다 낮다면, 이전 직사각형의 높이로 만들 수 있는 가장 큰 넓이의 직사각형을 구할 수 있다.
이 때 그 직사각형의 너비는 (지금 직사각형의 index)-(이전 직사각형의 높이보다 낮은 이전 직사각형 이전의 가장 가까운 직사각형의 index)-1가 될 것이다.
이전 직사각형의 높이로 만들 수 있는 가장 큰 직사각형을 만들었으니, 이 높이는 stack에서 제거되고, 지금 직사각형의 높이를 쌓는다.
stack에는 직사각형의 높이가 같거나 증가하는 수열로 들어가 있을 것이다.
모든 높이를 다 확인하면, 아직 높이로 가장 큰 직사각형을 찾지 않은 높이들은 stack에 남아있을 것이다.
그 중 마지막으로 입력된 높이는, 그 높이 이전에 입력된 높이의 직사각형 이후부터 히스토그램의 끝까지를 너비로 가장 큰 넓이의 직사각형을 만든다.
(stack에는 직사각형의 높이가 같거나 증가하는 수열로 들어가 있기 때문이다.)
즉 너비는 (전체 히스토그램의 너비)-(stack의 이전 높이의 직사각형 index)-1이다.
이렇게 모든 높이에서 만들 수 있는 가장 큰 직사각형을 찾아, 이들을 비교하여 전체 히스토그램에서 가장 넓이가 큰 직사각형을 찾는다.

### 구현 배경 지식
- Stack

### 문제를 해결한 코드
~~~java
import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String testCase = null;

        while (true) {
            testCase = sc.nextLine();
            if (testCase.equals("0")) break;

            long[] array = convert(testCase);
            Stack<Element> stack = new Stack<>(); // stack에는 현재보다 작은 것들만 남아있을 것
            int size = array.length;

            long area = Long.MIN_VALUE;
            for (int i=0; i<size; i++) {
                long height = array[i];
                // stack에 나보다 큰 직사각형이 있었다면, 그 큰 직사각형일 때의 넓이를 계산해봐야한다
                while (!stack.empty() && stack.peek().height>height) {
                    Element oldElm = stack.pop();
                    int width = (stack.empty()? i: i-stack.peek().index-1);
                    long newArea = width*oldElm.height;
                    if (area < newArea) area = newArea;
                }
                stack.push(new Element(height, i));
            }

            while(!stack.empty()) {
                Element temp = stack.pop();
                int width = (stack.empty()? size: size-stack.peek().index-1);
                long newArea = width*temp.height;
                if (area < newArea) area = newArea;
            }

            System.out.println(area);
        }

    }

    private static long[] convert(String array) {
        String[] temp = array.split(" ");
        long[] result = new long[temp.length-1];
        for (int i=1; i<temp.length; i++)
            result[i-1] = Long.parseLong(temp[i]);
        return result;
    }

}

class Element {
    public long height;
    public int index;

    public Element(long h, int i) {
        height = h; index = i;
    }
}
~~~