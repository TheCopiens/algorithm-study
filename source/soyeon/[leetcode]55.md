# Leetcode 문제
- Jump Game
    - https://leetcode.com/problems/jump-game/

## 풀이 방법
### 문제 이해하기
- 배열에 쓰여있는 수 이하로 점프를 할 때 배열의 마지막 위치에 도착할 수 있는지 구하는 문제이다.

### 문제 접근 방법
- reach 배열을 따로 만들어서 reach[i]를 i번째 칸에 도달할 수 있으면 1, 없으면 0으로 저장한다.
- 배열을 순서대로 가면서 i번째 칸에 도착할 수 있다면 그 칸에서 갈 수 있는 모든 곳을 표시한다.

- list에 원소가 하나만 있을 때를 생각하지 않아서 많이 틀렸다.

### 접근 방법을 적용한 코드
- 시간복잡도 O(N^2)
```java
class Solution {
    public boolean canJump(int[] list) {
        int length=list.length;
        int reach[]=new int[length];
		
        reach[0]=1;
        for(int idx=0;idx<length;idx++) {
            if(reach[idx]==1){
                for(int jump=1;jump<=list[idx];jump++) {
                    if(idx+jump<length)
                        reach[idx+jump]=1;
                }
            }
        }
        
        boolean isPossible=false;
        if(reach[length-1]==1)
            isPossible=true;
        
        return isPossible;
    }
}
```

### 참고: 더 간단한 코드
- 시간복잡도 O(N)

```java
class Solution {
    public boolean canJump(int[] list) {
        int reachable = 0;
    	for (int i=0; i<list.length; ++i) {
        	if (i > reachable) return false;
        	reachable = Math.max(reachable, i + list[i]);
    	}
    	return true;
	}
}
```
