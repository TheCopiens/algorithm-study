# 프로그래머스 문제
- 징검다리 건너기
    - https://programmers.co.kr/learn/courses/30/lessons/64062

## 풀이 방법
### 문제 이해하기
디딤돌에 적힌 숫자가 순서대로 담긴 배열 stones와 한 번에 건너뛸 수 있는 디딤돌의 최대 칸수 k가 매개변수로 주어질 때, 
최대 몇 명까지 징검다리를 건널 수 있는지 구하는 문제이다.

### 문제 접근 방법
처음에는 단순하게 한 번씩 건너게 해서 몇 명의 친구들이 건너갈 수 있는지 찾아봤는데 효율성 테스트에서 통과하지 못했다.
찾아보니 이분 탐색으로 찾으면 된다고 해서 이분탐색으로 바꾸어 보았다.

### 구현 배경 지식
이분탐색

### 접근 방법을 적용한 코드
```java
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Solution solution = new Solution();
		int[] stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
		int k = 3;
		System.out.println(solution.solution(stones, k));
	}
}

class Solution {
	public static int MAX = 200000000;

	public int solution(int[] stones, int k) {
		int left = 1;
		int right = MAX;
		int mid = (left + right) / 2;

		while (left <= right) {
			if (isKSequence(mid, stones, k)) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}

			mid = (left + right) / 2;
		}

		return left;
	}

	public boolean isKSequence(int num, int[] stones, int k) {
		int n = 0;
		for (int i = 0; i < stones.length; i++) {
			if (stones[i] - num <= 0) {
				n++;
			} else {
				n = 0;
			}

			if (n >= k) {
				// 돌의 높이 == 친구들의 인원인 경우 연속해서 k개
				return false;
			}
		}
		return true;
	}
}
```
