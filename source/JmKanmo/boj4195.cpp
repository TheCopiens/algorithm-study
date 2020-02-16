#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int parent[200001];
int cost[200001];
int F;

int find(int idx)
{
	if (parent[idx] == idx) return parent[idx];
	return find(parent[idx]);
}

int merge(int idx1, int idx2)
{
	int p1 = find(idx1);
	int p2 = find(idx2);

	if (p1 != p2)
	{
		cost[p1] += cost[p2];
		parent[p2] = parent[p1];
	}
	return cost[p1];
}

void init()
{
	cin >> F;

	for (int i = 1; i <= 2 * F; i++) {
		parent[i] = i;
		cost[i] = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int  test;
	cin >> test;

	for (int t = 0; t < test; t++)
	{
		map<string, int> hash_map;

		init();

		for (int i = 0, number = 0; i < F; i++)
		{
			string a, b;
			cin >> a >> b;

			if (hash_map[a] == 0) hash_map[a] = ++number;
			if (hash_map[b] == 0) hash_map[b] = ++number;
			cout << merge(hash_map[a], hash_map[b]) << "\n";
		}
	}
	return 0;
}