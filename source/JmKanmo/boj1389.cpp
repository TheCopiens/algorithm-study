#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int N, M;
vector<Pair>GP[1001];
int visited[1001];
int step[1001];

void init()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		GP[a].push_back(Pair(b, 1));
		GP[b].push_back(Pair(a, 1));
	}
}

void bfs(int start)
{
	queue<int>q;
	q.push(start);
	visited[start] = 1;

	while (q.empty() != true)
	{
		int pos = q.front();
		q.pop();

		for (auto elem : GP[pos])
		{
			int next = elem.first;

			if (visited[next] == 0)
			{
				q.push(next);
				visited[next] = 1;
				step[next] = step[pos] + 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();

	int MIN = 2e9;
	vector<int>SUM(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		bfs(i);	
		for (int j = 1; j <= N; j++) SUM[i] += step[j];
		memset(visited, 0, sizeof(visited));
		memset(step, 0, sizeof(step));
	}

	int answer = 0;

	for (int i = N; i >= 1; i--) {
		if (SUM[i] <= MIN) {
			answer = i;
			MIN = SUM[i];
		}
	}

	cout << answer << endl;
	return 0;
}