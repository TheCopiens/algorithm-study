# 카카오 blind 2020 
- 자물쇠와 열쇠
    - https://programmers.co.kr/learn/courses/30/lessons/60059

## 풀이 방법
### 문제 이해하기
- 입력 : 2차원 배열 key, 2차원 배열 lock  (0은 홈, 1은 돌기)
- 출력 : lock을 열 수 있으면 true, 없으면 false
- 조건 
    - key의  돌기 -> lock의 홈 딱 맞으면 열림
    - 돌기와 돌기가 만나면 안됨
    - key는 lock 영역을 벗어날 수 있음
    - key는 회전, 이동 가능

### 문제 접근 방법
- 90도씩 회전한 4가지 형태의 keys list 만들기
- key가 lock 영역을 벗어나는 것 까지 포함하는 전체 영역 map 만든다
- key를 90도씩 회전하며 모든 map 영역을 탐색한다. 
### 구현 배경 지식
- 완전탐색
### 접근 방법을 적용한 코드
```java
import java.util.*;
class Solution {
    static int m;
	static int n;
	static int size;
    public boolean solution(int[][] key, int[][] lock) {

        m = key.length;
        n = lock.length;
        // 회전한 모든 key의 경우의 수 담기 (총 4가지)
        int[][][] keys = lotatedKeys(key);
        
        // map 영역 정의
        size = n+2*m-2;
        int[][] map = new int[size][size];
        for(int i=m-1; i<m-1+n; i++) {
        	for(int j=m-1; j<m-1+n; j++) {
        		map[i][j] += lock[i-m+1][j-m+1];
        	}
        }
        
        // 완탐 : 모든 map 영역 탐색 -> test 함수 (lock 영역의 모든 값이 1이면 true 리턴)
        for(int t=0; t<4; t++) {
        	for(int i=0; i<size-m+1; i++) {
        		for(int j=0; j<size-m+1; j++) {	// key의 0,0 시작 점
        			if(isLockOpened(keys[t], i, j, map)== true) {
//        				System.out.println("lock open");
        				return true;
        			}
        		}
        	}
        }
        return false;
        
    }
    static boolean isLockOpened(int[][] key,int x, int y, int[][] map) {
		int[][] tempMap = copyMap(map);

		// key + map 
		for(int i=0; i<m; i++) {
			for(int j=0; j<m; j++) {
				tempMap[x+i][y+j] += key[i][j];
			}
		}
		
//		debug(tempMap, 0, 0, size);
//		debug(tempMap, x, y, n);
		
		// 검사 : lock 영역의 모든 값 1
		for(int i=m-1; i<m-1+n; i++) {
			for(int j=m-1; j<m-1+n; j++) {
				if(tempMap[i][j]!=1) {
					return false;
				}
			}
		}
		return true;
	}
	
	
	static int[][][] lotatedKeys(int[][] key) {
		int[][][] keys = new int[4][m][n];
		for(int i=0; i<m; i++) {
    		for(int j=0; j<m; j++) {
    			keys[0][i][j] = key[i][j];
    		}
    	}
        
        for(int t=1; t<4; t++) {
        	for(int i=0; i<m; i++) {
        		for(int j=0; j<m; j++) {
        			keys[t][j][m-i-1] = keys[t-1][i][j];
        		}
        	}
        }
        return keys;
	}
	static int[][] copyMap(int[][] map){
		int[][] tempMap = new int[size][size];
		for(int i=0; i<size; i++) {
			for(int j=0; j<size; j++) {
				tempMap[i][j] = map[i][j];
			}
		}
		return tempMap;
	}

    static void debug(int[][] map, int x, int y, int size) {// 검사 범위
        for(int i=x; i<x+size; i++) {
            for(int j=y; j<y+size; j++) {
                System.out.print(map[i][j]+" ");
            }
            System.out.println();
        }
        
        System.out.println("==================");
    }
}


```

