# 카카오 블라인드 테스트 문제 : 기둥과 보 설치
=========================
- https://www.welcomekakao.com/learn/courses/30/lessons/60061

### 풀이 방법

#### 문제 접근 방법
- 모든 좌표에 Coordinate객체 생성
- 해당 좌표(x,y)를 꼭지점으로 하는 모든 구조물 저장
    - 설치 시 : isPossible(x좌표, y좌표, 구조물 종류)
    - 삭제 시 : (x,y)을 끝점으로 하는 모든 구조물에 대하여 isPossible검사
    

### 구현 배경 지식

#### 접근 방법을 적용한 코드

```java


import java.util.*;

class Solution {
    static Coordinate[][] check;
	static class Coordinate{
		int x;
		int y;
		String a;
		List<String> starts ;
		List<String> ends;
		public Coordinate(int x, int y) {
			this.x = x;
			this.y = y;
			this.starts = new LinkedList<>();
			this.ends  = new LinkedList<>(); 
		}
		// x, y를 시작점으로 하는 구조물 반환 
		public List<String> findByStart(int x, int y) {
			return this.starts;
		}
		// x, y를 끝점으로 하는 구조물 반환
		public List<String> findByEnd(int x, int y) {
			return this.ends;
		}
		public void setCoor(int x, int y,String a) {
			this.x = x;
			this.y = y;
			this.a = a;
			this.starts.add(a);
			if(a.equals("0")) {
				check[x][y+1].ends.add(a);
			}else if(a.equals("1")) {
				check[x+1][y].ends.add(a);
			}
		}
		
		public void delete(int x, int y, String a) {
			this.starts.remove(a);
			this.a ="-1";
			if(a.equals("0") && !check[x][y+1].ends.isEmpty()) {
				check[x][y+1].findByEnd(x,y+1).remove(a);
			}else if(a.equals("1") && !check[x+1][y].ends.isEmpty()) {
				check[x+1][y].findByEnd(x+1,y).remove(a);
			}
			
		}
	}
	
	public static boolean isPossible(int x, int y, String a) {
		// 설치
		/* 기둥 : 바닥 위, 보 한쪽 끝 위, 다른 기둥 위
		 * 보 : 한쪽 끝 기둥 위, 양쪽 끝 보 
		 * */
		if(a.equals("0")) {// 기둥
			if(y==0) {
				return true;
			}else if(!check[x][y].findByStart(x,y).isEmpty() || !check[x][y].findByEnd(x,y).isEmpty()) {
				return true;
			}
		}else if(a.equals("1")){	//보
			if(check[x][y].findByEnd(x,y).contains("0") ||check[x+1][y].findByEnd(x+1,y).contains("0")) {
				return true;
			}
			if(check[x][y].findByEnd(x,y).contains("1") && check[x+1][y].findByStart(x+1, y).contains("1")) {
				return true;
			}
		}
		return false;
	}
    public int[][] solution(int n, int[][] build_frame) {
		check = new Coordinate[n+1][n+1];
		for(int i=0; i<n+1; i++) {
			for(int j=0; j<n+1; j++) {
				check[i][j] = new Coordinate(i,j);
			}
		}
		for(int i=0; i<build_frame.length; i++) {
			int x = build_frame[i][0];
			int y = build_frame[i][1];
			String a = Integer.toString(build_frame[i][2]); 	// 보 ==1 or 기둥==0
			int b = build_frame[i][3];   // 설치 or 삭제
			
			if(b==1) {  // 설치
				if(isPossible(x,y,a)) {
					check[x][y].setCoor(x, y, a);
				}
			}else if(b==0){// 삭제
				// 선 삭제
				check[x][y].delete(x, y, a);
				for(String ae : check[x][y].starts) {
					if(!isPossible(x,y,ae)) {
						check[x][y].setCoor(x, y, a);
					}
				}
				for(String ae : check[x][y].ends) {
					if(!isPossible(x,y,ae)) {
						check[x][y].setCoor(x, y, a);
					}
				}
				// 기둥 : (x,y+1)을 시작점 or 끝점
				if(a.equals("0")) {
					for(String ae : check[x][y+1].starts) {
						if(!isPossible(x,y+1,ae)) {
							check[x][y].setCoor(x, y, a);
						}
					}
					for(String ae : check[x][y+1].ends) {
						if(!isPossible(x,y+1,ae)) {
							check[x][y].setCoor(x, y, a);
						}
					}
				}else if(a.equals("1")) {	// 보 : (x+1,y)를 시작점 or 끝점
					for(String ae : check[x+1][y].starts) {
						if(!isPossible(x+1,y,ae)) {
							check[x][y].setCoor(x, y, a);
						}
					}
					for(String ae : check[x+1][y].ends) {
						if(!isPossible(x+1,y,ae)) {
							check[x][y].setCoor(x, y, a);
						}
					}
				}
			}
		}
		List<Coordinate> answerli = new ArrayList<>();
		for(int i=0; i<n+1; i++) {
			for(int j=0; j<n+1; j++) {
				if(!check[i][j].starts.isEmpty()) {
					answerli.add(check[i][j]);
				}
			}
		}
		int[][] answer = new int[answerli.size()][3];
		int t =0;
		for(Coordinate c : answerli) {
			answer[t][0] = c.x;
			answer[t][1] = c.y;
			answer[t][2] = Integer.parseInt(c.a);
            t++;
		}
		return answer;
    }
}
```
