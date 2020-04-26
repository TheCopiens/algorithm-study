#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx_1[] = { -2,-2,0,0,2,2 };
const int idx_2[] = { -1,1,-2,2,-1,1 };

int N;
Pair start, goal;
int step[201][201];

void init()
{
	cin >> N;
	cin >> start.first >> start.second >> goal.first >> goal.second;
}

void bfs()
{
	queue<Pair>q;
	q.push(start);

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		if (pos == goal) {
			cout << step[pos.first][pos.second] << endl;
			return;
		}

		for (int i = 0; i < 6; i++)
		{
			Pair next = Pair(pos.first + idx_1[i], pos.second + idx_2[i]);

			if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= N) 
				continue;

			if (!step[next.first][next.second])
			{
				step[next.first][next.second] = step[pos.first][pos.second] + 1;
				q.push(next);
			}
		}
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
	return 0;
}