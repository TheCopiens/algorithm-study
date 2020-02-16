#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

int N, M, K;
int board[1001][1001];
int step[1001][1001][11];

void init()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;

		for (int j = 1; j <= M; j++)
		{
			board[i][j] = str[j - 1] - '0';
		}
	}
}

void bfs()
{
	queue<Pair>q;
	q.push(Pair(0, make_pair(1, 1)));
	step[1][1][0] = 1;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		if (pos.second == make_pair(N, M))
		{
			cout << step[N][M][pos.first] << endl;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> next = make_pair(pos.second.first + idx_1[i], pos.second.second + idx_2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>M) 
				continue;

			if (pos.first >= K)
			{
				if (!step[next.first][next.second][pos.first] && board[next.first][next.second] == 0)
				{
					q.push(Pair(pos.first, next));
					step[next.first][next.second][pos.first] = step[pos.second.first][pos.second.second][pos.first] + 1;
				}
			}
			else
			{
				if (!step[next.first][next.second][pos.first])
				{
					if (board[next.first][next.second])
					{
						q.push(Pair(pos.first + 1, next));
						step[next.first][next.second][pos.first + 1] = step[pos.second.first][pos.second.second][pos.first] + 1;
					}
					else
					{
						q.push(Pair(pos.first, next));
						step[next.first][next.second][pos.first] = step[pos.second.first][pos.second.second][pos.first] + 1;
					}
				}
			}
		}
	}

	cout << -1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	bfs();
	return 0;
}