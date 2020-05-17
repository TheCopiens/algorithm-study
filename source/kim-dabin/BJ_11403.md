# 백준 경로 찾기

## 문제 접근 

- 가중치 없는 방향 그래프
- BFS로 접근 



## 코드 구현	

```java
import java.io.*;
import java.util.*;

public class Main {
	static int[][] map;
	static int n;
	static boolean[]visited;
	static int[][] resMap;

	public static void bfs(int s) {
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(s);
		while (!q.isEmpty()) {
			int ver = q.poll();// 정점

			for (int i = 0; i < n; i++) {
				if (map[ver][i] == 1 && !visited[i]) {
					visited[i] = true;
					resMap[s][i] = 1;
					q.add(i);
				}
//				if(map[ver][i] == 1 ) {
//					resMap[s][i] = 1;
//				}
				
			}

		}//while end 
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		visited = new boolean[n];
		resMap = new int[n][n];

		for (int i = 0; i < n; i++) {
			String[] str = br.readLine().split(" ");
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(str[j]);
			}
		} // for end

		for (int i = 0; i < n; i++) {
				bfs(i);
				Arrays.fill(visited, false);
		} // for end

		// print the map
		for (int[] ma : resMap) {
			for (int m : ma) {
				System.out.print(m + " ");
			}
			System.out.println();
		}

	}
}

```

