#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

int N, M;
int board[1001][1001];
int visited[1001][1001];
vector<Pair>zeros;
map<int, int> hash_map;
int answer;

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (!board[i][j]) {
				zeros.push_back(Pair(i, j));
			}
		}
	}
}

void bfs(Pair start, int number)
{
	queue<Pair>q;
	int cnt = 0;
	q.push(start);
	visited[start.first][start.second] = number;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx_1[i], pos.second + idx_2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>M
				|| visited[next.first][next.second] || board[next.first][next.second] == 0)
				continue;

			q.push(next);
			visited[next.first][next.second] = number;
		}
	}
	hash_map[number] = cnt;
}

void setNumber()
{
	for (int i = 1, number = 0; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!visited[i][j] && board[i][j] == 1)
			{
				bfs(Pair(i, j), ++number);
			}
		}
	}
}

void solve()
{
	for (int i = 0; i < zeros.size(); i++)
	{
		Pair pos = zeros[i];
		map<int, int>temp_map;
		int cnt = 0;

		for (int j = 0; j < 4; j++)
		{
			Pair next = Pair(pos.first + idx_1[j], pos.second + idx_2[j]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>M)
				continue;

			if (visited[next.first][next.second] != 0 && temp_map.count(visited[next.first][next.second]) == 0)
			{
				cnt += hash_map[visited[next.first][next.second]];
				temp_map[visited[next.first][next.second]] = 1;
			}
		}
		answer = max(answer, cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	setNumber();
	solve();
	cout << answer << endl;
	return 0;
}