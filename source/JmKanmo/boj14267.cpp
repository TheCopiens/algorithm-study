#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include<stack>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int N, M;
vector<int>GP[100001];
vector<Pair>input;
int visited[100001];
int step[100001];

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		if (i == -1) continue;
		GP[n].push_back(i);
	}

	for (int i = 0; i < M; i++) {
		int k, w;
		cin >> k >> w;
		input.push_back(Pair(k, w));
	}
}

void bfs(int n)
{
	queue<int>q;
	q.push(n);
	visited[n] = 1;
	
	while (q.empty() != true)
	{
		int pos = q.front();
		q.pop();

		for (auto elem : GP[pos])
		{
			if (!visited[elem])
			{
				step[elem] += step[pos];
				visited[elem] = 1;
				q.push(elem);
			}
		}
	}
}

void solve()
{
	for (auto elem : input) {
		step[elem.first] += elem.second;
	}

	bfs(1);

	for (int i = 1; i <= N; i++) {
		cout << step[i] << " ";
	}
	cout << endl;
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