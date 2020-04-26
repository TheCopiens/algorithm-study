#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

int N;
int board[26][26];
int visited[26][26];
vector<int>answer;

void init()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;

		for (int j = 1; j <= N; j++) {
			board[i][j] = str[j - 1] - '0';
		}
	}
}

int bfs(Pair start)
{
	queue<Pair>q;
	int cnt = 0;

	q.push(start);
	visited[start.first][start.second] = 1;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx_1[i], pos.second + idx_2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>N)
				continue;

			if (board[next.first][next.second] && visited[next.first][next.second] == 0)
			{
				q.push(next);
				visited[next.first][next.second] = 1;
			}
		}
	}
	return cnt;
}

int solve()
{
	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j] && visited[i][j] == 0)
			{
				cnt++;
				int k = bfs(Pair(i, j));
				if (k > 0) answer.push_back(k);
			}
		}
	}
	sort(answer.begin(), answer.end());
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	init();
	cout << solve() << endl;
	for (int elem : answer) {
		cout << elem << endl;
	}
	return 0;
}