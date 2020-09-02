# 프로그래머스 문제

- 실패율
    - https://programmers.co.kr/learn/courses/30/lessons/42889
    
### 문제 이해하기
실패율 = 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

### 문제 접근 방법

### 구현 배경 지식
객체 정렬

### 접근 방법을 적용한 코드
```java
import java.util.*;
class Solution {
	public int[] solution(int N, int[] stages) {
		int[] answer = new int[N];
		Stage[] stage = new Stage[N + 1];
		for (int i = 0; i <= N; i++) {
			stage[i] = new Stage(i);
		}

		for (int i = 0; i < stages.length; i++) {
			if (stages[i] <= N) {
				stage[stages[i]].add();
			}
		}

		int num = stages.length;
		for (int i = 1; i <= N; i++) {
			stage[i].setFailPer(num);
			num -= stage[i].getFail();
		}

		Arrays.sort(stage);

		int index = 0;
		for (Stage subStage : stage) {
			if (subStage.getStageNum() == 0) {
				continue;
			}

			answer[index++] = subStage.getStageNum();
		}

		return answer;
	}
}

class Stage implements Comparable<Stage> {
	private int fail;
	private int stageNum;
	private double failPer;

	public Stage(int stageNum) {
		this.stageNum = stageNum;
		this.fail = 0;
	}

	public void add() {
		this.fail++;
	}

	public void setFailPer(int people) {
		if (people == 0) {
			this.failPer = 0;
		} else {
			this.failPer = fail / (double) people;
		}
	}

	public int getFail() {
		return this.fail;
	}

	public int getStageNum() {
		return this.stageNum;
	}

	@Override
	public int compareTo(Stage o) {
		if (this.failPer > o.failPer) {
			return -1;
		} else if (this.failPer == o.failPer) {
			if (this.stageNum > o.stageNum) {
				return 1;
			} else {
				return -1;
			}
		} else {
			return 1;
		}
	}

	@Override
	public String toString() {
		return "( " + stageNum + ": " + fail + " )";
	}
}
```
