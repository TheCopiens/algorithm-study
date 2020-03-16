#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int N, K;
int visited[100001];
int step[100001];
int answer_time;
int answer_count;

void bfs()
{
	queue<Pair>q;
	q.push(Pair(0, N));
	visited[N] = 1;

	while (q.empty() != true)
	{
		Pair ret = q.front();
		q.pop();

		int time = ret.first;
		int pos = ret.second;

		if (pos == K) {
			answer_time = time;
			answer_count++;
		}

		for (int i = 1; i <= 3; i++)
		{
			int next1 = pos;

			switch (i)
			{
			case 1:
			{
				next1--;
				break;
			}
			case 2:
			{
				next1++;
				break;
			}
			case 3:
			{
				next1 *= 2;
				break;
			}
			}

			if (next1 < 0 || next1>100000)
				continue;

			if (visited[next1] == 0)
			{
				q.push(Pair(time + 1, next1));
				visited[next1] = 1;
				step[next1] = step[pos] + 1;
			}
			else if (step[pos] + 1 == step[next1]) {
				q.push(Pair(time + 1, next1));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> K;
	bfs();
	cout << answer_time << endl;
	cout << answer_count<< endl;
	return 0;
}