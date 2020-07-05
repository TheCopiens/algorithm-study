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
vector<Pair>GP[501];
int visited[501];
int step[501];
int answer;

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

int bfs()
{
	queue<int>q;
	q.push(1);
	visited[1] = 1;

	while (q.empty() != true)
	{
		int pos = q.front();
		q.pop();

		for (auto elem : GP[pos])
		{
			if (visited[elem.first] == 0)
			{
				visited[elem.first] = 1;
				q.push(elem.first);
				step[elem.first] = step[pos] + 1;
			}
		}
	}

	int ret = 0;

	for (int i = 0; i < 501; i++)
	{
		if (step[i] == 1 || step[i] == 2)
		{
			ret++;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	cout << bfs() << endl;
	return 0;
}