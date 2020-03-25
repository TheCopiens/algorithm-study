#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int,int> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

struct Cheese
{
	char state; // C(³ì´Â´Ù), N(¾È³ì´Â´Ù)
	int cheese;
};

int N, M;
Cheese board[101][101];
int time, cnt;

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j].cheese;
			board[i][j].state = 'N';
			if (board[i][j].cheese) cnt++;
		}
	}
}

void bfs()
{
	queue<Pair>q;
	vector<vector<int>>visited(N + 1, vector<int>(M + 1));
	q.push(Pair(1, 1));
	visited[1][1] = 1;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx_1[i], pos.second + idx_2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>M || visited[next.first][next.second])
				continue;

			if (board[next.first][next.second].cheese) {
				board[next.first][next.second].state = 'C';
				continue;
			}
			visited[next.first][next.second] = 1;
			q.push(next);
		}
	}
}

void meltCheese()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (board[i][j].cheese && board[i][j].state == 'C')
			{
				board[i][j].cheese = 0;
				board[i][j].state = 'N';
				cnt--;
			}
		}
	}
}

void solve()
{
	while (true)
	{
		bfs();
		int temp_cnt = cnt;
		time++;
		meltCheese();
		if (cnt == 0) {
			cout << time << endl;
			cout << temp_cnt << endl;
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	solve();
	return 0;
}