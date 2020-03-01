#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, int> Pair;

int N, M;
int parent[10001];
vector<Pair>edges;
int start, goal;

bool comp(Pair p1, Pair p2)
{
	return p1.second > p2.second ? true : false;
}

int getParent(int idx) {
	if (idx == parent[idx])
		return idx;
	else
		return getParent(parent[idx]);
}

void merge(int idx1, int idx2)
{
	int p1 = getParent(idx1);
	int p2 = getParent(idx2);

	if (p1 != p2)
		parent[p1] = p2;
}

void init()
{
	cin >> N >> M;
	
	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		edges.push_back(Pair(make_pair(A, B), C));
	}

	cin >> start >> goal;

	for (int i = 0; i <= N; i++)
		parent[i] = i;

	sort(edges.begin(), edges.end(), comp);
}

void solve()
{
	for (auto elem : edges)
	{
		merge(elem.first.first, elem.first.second);

		if (getParent(start) == getParent(goal))
		{
			cout << elem.second << endl;
			return;
		}
	}
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