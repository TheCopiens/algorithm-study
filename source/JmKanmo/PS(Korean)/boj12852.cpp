#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int N;
	cin >> N;

	queue<int>q;
	vector<Pair>step(N + 1);

	q.push(1);
	
	while (q.empty() != true)
	{
		int pos = q.front();
		q.pop();

		if (pos == N)
			break;

		if (pos * 3 <= N && step[pos * 3].second == 0) {
			q.push(pos * 3);
			step[pos * 3].second = step[pos].second + 1;
			step[pos * 3].first = pos;
		}

		if (pos * 2 <= N && step[pos * 2].second == 0) {
			q.push(pos * 2);
			step[pos * 2].second = step[pos].second + 1;
			step[pos * 2].first = pos;
		}

		if (pos + 1 <= N && step[pos + 1].second == 0) {
			q.push(pos + 1);
			step[pos + 1].second = step[pos].second + 1;
			step[pos + 1].first = pos;
		}
	}

	cout << step[N].second << endl;

	while (true)
	{
		if (N == 0)break;
		cout << N << " ";
		N = step[N].first;
	}

	return 0;
}
