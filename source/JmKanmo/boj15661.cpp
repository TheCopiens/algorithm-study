#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

int N;
int board[21][21];
int visited[21];
int answer = 2e9;

void init()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}
}

void dfs(int idx, int cnt, int limit)
{
	if (cnt >= limit)
	{
		// 최소차이값구하기
		vector<int>start, link;

		for (int i = 1; i <= N; i++)
		{
			if (visited[i]) start.push_back(i);
			else link.push_back(i);
		}

		int power_start = 0, power_link = 0;

		for (int i = 0; i < start.size(); i++)
		{
			for (int j = 0; j < start.size(); j++)
			{
				if (i != j)
				{
					power_start += (board[start[i]][start[j]]);
				}
			}
		}

		for (int i = 0; i < link.size(); i++)
		{
			for (int j = 0; j < link.size(); j++)
			{
				if (i != j)
				{
					power_link += (board[link[i]][link[j]]);
				}
			}
		}
		answer = min(answer, abs(power_start - power_link));
		return;
	}

	for (int i = idx + 1; i <= N; i++)
	{
		visited[i] = 1;
		dfs(i, cnt + 1, limit);
		visited[i] = 0;
	}
}

void solve()
{
	for (int i = 1; i <= N / 2; i++)
	{
		dfs(0, 0, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);	

	init();
	solve();
	cout << answer << endl;
	return 0;
}