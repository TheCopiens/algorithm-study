# [카카오/자바] 자물쇠와 열쇠



## 코드구현

```java
import java.util.*;
class Solution {
 public static boolean open = false;
	public static int M, N;

	public static class Node {
		public int row; // row 열 y
		public int col; // column 행 x

		public Node(int x, int y) {
			this.row = y;
			this.col = x;
		}

	}// Node end

	public static int[][] rotate(int m, int[][] k) { // 90도씩 회전
		int[][] tmp = new int[m][m];

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = k[m - j - 1][i];
			}
		}
		return tmp;
	}

	public static int[][] copyArray(int[][] arr) {
		int[][] tmp = new int[arr.length][arr.length];
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length; j++) {
				tmp[i][j] = arr[i][j];
			}
		}

		return tmp;
	}

	public static boolean checkArr(int[][] key, int[][] lock) {
		Queue<Node> q = new LinkedList<>();
		q.add(new Node(0, 0)); // queue start

		boolean ok = false;
		while (!q.isEmpty()) {
			Node cur = q.poll();
			int nowX = cur.col;
			int nowY = cur.row;
			int[][] cloneLock = copyArray(lock);

			if (nowX >= lock.length || nowY >= lock.length) {
				break;
			}

			if (nowY + key.length >= lock.length) {
				nowX++;
				nowY = 0;
			}
			for (int i = 0; i < key.length; i++) {
				for (int j = 0; j < key.length; j++) {
					if (nowX + i < 0 || nowY + j < 0 || nowX + i >= lock.length || nowY + j >= lock.length) {
						continue;
					}
					cloneLock[nowX + i][nowY + j] += key[i][j];

				} // for end
			} // for end

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (i + M < 0 || j + M < 0 || i + M >= lock.length || j + M >= lock.length) {
						continue;
					}
					if (cloneLock[i + M][j + M] != 1) {
						ok = false;
						break; // 홈이 있으면
					} else {
						ok = true;
					}
				} // for end


				if (!ok)	break;
				

			} // for end

			if (ok) {
				break;
			} else {
				q.add(new Node(nowX, nowY + 1));
			}

		}

		return ok;

	}

	public static void dfs(int cnt, int[][] key, int[][] lock) {
		open = checkArr(key, lock);

		if (open) {
			return;
		}

		if (cnt == 4) {
			return;
		}

		dfs(cnt + 1, rotate(key.length, key), lock);

	}

	public boolean solution(int[][] key, int[][] lock) {
		M = key.length;
		N = lock.length;
		int[][] copyLock = new int[N + 2 * M][N + 2 * M];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				copyLock[i + M][j + M] = lock[i][j];
			}
		}

		dfs(0, key, copyLock);

		return open;
	}

}
```

