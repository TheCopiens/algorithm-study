# 프로그래머스 카카오 블라인드 2019 문제
- 실패율
    - https://programmers.co.kr/learn/courses/30/lessons/42889

## 풀이 방법
### 문제 이해하기
- [입력값]
    - N : 스테이지 개수
    - int [] stages -> stages[k] : k번째 사용자의 현재 stage 위치
- [출력값]
    - 실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 return 
### 문제 접근 방법
- Stage 클래스 (스테이지 번호, 실패율) implements Comparagle<Stage>
- 이중 for문
    - 첫번째 for문은 스테이지 번호 (k)
    - 두번째 for 문은 사용자 번호 (i)라고 할때,
    - stages[i] >= k : 스테이지에 도달한 플레이어 수
    - stages[i] == k : 스테이지에 도달했지만 클리어 못한 플레이어 수 
    - 두번째 for문 다 돌때마다 우선순위 큐에 Stage 저장

### 접근 방법을 적용한 코드
```java
class Stage implements Comparable<Stage>{
	int stage_num;
	double fail_rate;
	public Stage(int stage_num){
		this.stage_num = stage_num;
		this.fail_rate=0;
	}
	public int compareTo(Stage o) {
		if(this.fail_rate == o.fail_rate){
			return Integer.compare(stage_num, o.stage_num);
		}
		return Double.compare(o.fail_rate, fail_rate);
	}
}
class Solution {
    public int solution(String dartResult) {
        int[] answer = new int[N];
        PriorityQueue<Stage> q = new PriorityQueue<>();
        for(int k=1; k<N+1; k++) {
        	Stage s = new Stage(k);
        	int not_clear=0;
        	int arrived_players=0;
        	for(int i=0; i<stages.length; i++) {
        		if(stages[i]>=k) {
        			arrived_players++;
        			if(stages[i]==k) {
        				not_clear++;
        			}
        		}
        	}
        	if(arrived_players==0) {
        		s.fail_rate=0;
        	}else {
        		s.fail_rate = (double)not_clear/arrived_players;
        	}
        	q.add(s);
        }
        for(int i=0; i<answer.length ;i++) {
        	if(!q.isEmpty()) {
        		answer[i]=q.poll().stage_num;
        	}
        }
        return answer;
    }
}
```

