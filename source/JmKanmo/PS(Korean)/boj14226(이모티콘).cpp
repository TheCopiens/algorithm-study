#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, int> Pair;

int S;
int visited[1001][1001];// [클립보드][화면]

void bfs()
{
	queue<Pair>q;
	visited[0][1] = 1;
	q.push(Pair(make_pair(0, 1), 0));

	while (q.empty() != true)
	{
		Pair pos = q.front();
		int clipboard = pos.first.first;
		int scene = pos.first.second;
		int time = pos.second;
		q.pop();

		if (pos.first.second == S)
		{
			cout << pos.second << endl;
			return;
		}

		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
				Pair next = Pair(make_pair(scene, scene), time + 1);
				if (visited[next.first.first][next.first.second]) continue;
				visited[next.first.first][next.first.second] = 1;
				q.push(next);
			}
			else if (i == 1)
			{
				Pair next = Pair(make_pair(clipboard, clipboard + scene), time + 1);

				if (next.first.second > S || visited[next.first.first][next.first.second])
					continue;

				q.push(next);
				visited[next.first.first][next.first.second] = 1;
			}
			else
			{
				Pair next = Pair(make_pair(clipboard, scene - 1), time + 1);

				if (next.first.second < 0 || visited[next.first.first][next.first.second])
					continue;

				q.push(next);
				visited[next.first.first][next.first.second] = 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> S;
	bfs();
	return 0;
}