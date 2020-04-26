#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <algorithm>
#define INF 987654321

using namespace std;

typedef pair<int, int> Pair;

int N, K;
vector<int>distances(100001, INF); //다익스트라 알고리즘 최단거리저장 

void init()
{
	cin >> N >> K;
}

// 다익스트라 알고리즘 이용
void dijkstra()
{
	priority_queue<Pair, vector<Pair>, greater<Pair>>pq;
	pq.push(Pair(0, N));
	distances[N] = 0;

	while (pq.empty() != true)
	{
		Pair p = pq.top();
		pq.pop();

		int cur_pos = p.second;
		int cur_time = p.first;

		for (int i = 1; i <= 3; i++)
		{
			int next_pos = p.second;
			int next_time = p.first;

			if (i == 1) {
				next_pos--;
				next_time++;
			}
			else if (i == 2) {
				next_pos++;
				next_time++;
			}
			else next_pos *= 2;

			if (next_pos < 0 || next_pos>100000) continue;

			if (distances[next_pos] > next_time) {
				distances[next_pos] = next_time;
				pq.push(Pair(next_time, next_pos));
			}
		}
	}
}

// BFS(덱) 이용
void bfs()
{
	deque<int>dq;
	vector<int>dist(100001, -1);

	dq.push_back(N);
	dist[N] = 0;

	while (dq.empty() != true)
	{
		int pos = dq.back();
		dq.pop_back();

		if (pos == K) {
			cout << dist[pos] << endl;
			break;
		}

		for (int i = 1; i <= 3; i++)
		{
			int next = pos;

			if (i == 1) {
				next *= 2;
			}
			else if (i == 2) {
				next++;
			}
			else {
				next--;
			}

			if (next < 0 || next>100000 || dist[next] >= 0)
				continue;

			if (i == 1) {
				dist[next] = dist[pos];
				dq.push_back(next);
			}
			else {
				dist[next] = dist[pos] + 1;
				dq.push_front(next);
			}
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