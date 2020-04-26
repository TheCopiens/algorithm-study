#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#define LIMIT 500000

using namespace std;

typedef pair<int,int> Pair;

int N, K;
int answer = -1;
vector<vector<int>>dist(LIMIT+1, vector<int>(2, -1));

void init()
{
	cin >> N >> K;
}

void bfs()
{
	queue<Pair>q;
	q.push(Pair(0, N));
	dist[N][0] = 0;

	while (q.empty() != true)
	{
		Pair elem = q.front();
		q.pop();

		int time = elem.first;
		int pos = elem.second;
		int flag = ++time % 2 == 0 ? 0 : 1;

		for (auto next : { pos - 1,pos + 1,pos * 2 })
		{
			if (next<0 || next>LIMIT || dist[next][flag] >= 0)
				continue;

			q.push(Pair(time, next));
			dist[next][flag] = time;
		}
	}
}

void solve()
{
	int time = 0;
	int pos = K;

	while (pos <= LIMIT)
	{
		if (dist[pos][0] >= 0 && time >= dist[pos][0])
		{
			if ((time - dist[pos][0]) % 2 == 0)
			{
				cout << time << endl;
				return;
			}
		}

		if (dist[pos][1] >= 0 && time >= dist[pos][1])
		{
			if ((time - dist[pos][1]) % 2 == 0)
			{
				cout << time << endl;
				return;
			}
		}
		pos += ++time;
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
	solve();
	return 0;
}