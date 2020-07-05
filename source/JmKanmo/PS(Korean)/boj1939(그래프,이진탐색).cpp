#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int N, M;
vector<Pair>GP[10001];
int visited[10001];
int start, goal;
int answer;

void init()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		GP[A].push_back(Pair(B, C));
		GP[B].push_back(Pair(A, C));
	}
	cin >> start >> goal;
}

bool dfs(int idx, int limit)
{
	if (idx == goal)
		return true;

	visited[idx] = 1;

	for (auto elem : GP[idx])
	{
		if (!visited[elem.first] && elem.second >= limit)
		{
			if (dfs(elem.first, limit))
				return true;
		}
	}
	return false;
}

bool bfs(int limit)
{
	queue<int>q;
	q.push(start);
	visited[start] = 1;

	while (q.empty() != true)
	{
		int pos = q.front();
		q.pop();

		if (pos == goal)
			return true;

		for (auto elem : GP[pos])
		{
			if (!visited[elem.first] && elem.second >= limit)
			{
				visited[elem.first] = 1;
				q.push(elem.first);
			}
		}
	}
	return false;
}

void solve()
{
	int left = 1, right = 1000000000;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		memset(visited, 0, sizeof(visited));

		if (bfs(mid)) {
			answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
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
	cout << answer << endl;
	return 0;
}