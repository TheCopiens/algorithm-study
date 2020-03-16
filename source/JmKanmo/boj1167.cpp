#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;
int N;
vector<Pair>GP[100001];
int visited[100001];
int MAX_V, MAX_LEN;

void init()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		vector<int>v;
		int cnt = 0;

		while (++cnt)
		{
			int val;
			cin >> val;
			if (val == -1)break;
			else {
				v.push_back(val);
			}
		}
		for (int j = 1; j < v.size(); j += 2) {
			GP[v[0]].push_back(Pair(v[j], v[j + 1]));
		}
	}
}

void dfs(int v, int len)
{
	visited[v] = 1;

	if (len > MAX_LEN) {
		MAX_LEN = len;
		MAX_V = v;
	}

	for (auto elem : GP[v])
	{
		if (visited[elem.first] == 0) {
			dfs(elem.first, len + elem.second);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	dfs(MAX_V, 0);
	cout << MAX_LEN << endl;
	return 0;
}