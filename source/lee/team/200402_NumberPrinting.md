# NumberPrinting
LINE 2019 기출

## 문제 접근 방법
- `크기, 숫자열`입력을 저장하는 클래스를 만듦
- 최대 높이:max, 각 높이:height, 중간값:middle=max/2-1
- TOP정렬일때 숫자가 쓰이기 시작하는 start 위치:0
- MIDDLE정렬일때 숫자가 쓰이기 시작하는 start 위치:middle-h/2
- BOTTOM정렬일때 숫자가 쓰이기 시작하는 start 위치:max-h+1

### 코드
```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;

public class Solution {
    static class Number {
        int size;
        String numbers;

        public Number(int size, String numbers) {
            this.size = size;
            this.numbers = numbers;
        }

    }

    private static void printNumbers(List<Number> list, String sort) {
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input1 = br.readLine().split(" ");
        int N = Integer.parseInt(input1[0]);
        String sort = input1[1];

        List<Number> list = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            String[] input2 = br.readLine().split(" ");
            Number number = new Number(Integer.parseInt(input2[0]), input2[1]);
            list.add(number);
        }

        printNumbers(list, sort);
    }
}

```

### Time complexity
O()

### Space complexity
O()   
