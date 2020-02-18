#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int N, M;
vector<Pair>GP[2001];
int visited[2001];

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

bool dfs(int idx, int cnt)
{
	if (cnt >= 4)
	{
		return true;
	}

	visited[idx] = 1;

	for (auto elem : GP[idx])
	{
		if (!visited[elem.first])
		{
			if (dfs(elem.first, cnt + 1))
				return true;
		}
	}
	visited[idx] = 0;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	init();

	for (int i = 0; i < N; i++)
	{
		if (dfs(i, 0)) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}