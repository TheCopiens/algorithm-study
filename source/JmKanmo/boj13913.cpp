#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int N, K;

void init()
{
	cin >> N >> K;
}

void bfs()
{
	queue<int>q;
	vector<int>dist(100001, -1);
	vector<int>step(100001);

	dist[N] = 0;
	q.push(N);

	while (q.empty() != true)
	{
		int pos = q.front();
		q.pop();

		if (pos == K)
		{
			cout << dist[pos] << endl;

			stack<int>st;

			while (pos != N) {
				st.push(pos);
				pos = step[pos];
			}

			st.push(N);

			while (st.empty() != true) {
				cout << st.top() << " ";
				st.pop();
			}
			break;
		}

		for (int i = 1; i <= 3; i++)
		{
			int next = pos;

			if (i == 1) next--;
			else if (i == 2) next++;
			else next *= 2;

			if (next < 0 || next>100000 || dist[next] >= 0)
				continue;

			dist[next] = dist[pos] + 1;
			step[next] = pos;
			q.push(next);
		}
	}
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