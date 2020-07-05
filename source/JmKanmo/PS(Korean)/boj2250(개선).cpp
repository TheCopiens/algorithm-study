#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>>Pair;

int N;
int root;
map<int, Pair>tree;
vector<pair<int, int>>width_v(10001, { 2e9,0 });
int num;

void init()
{
	cin >> N;

	vector<int> v(N + 1);

	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a > 0) v[a]++;
		if (b > 0) v[b]++;
		if (c > 0) v[c]++;
		tree[a] = Pair(0, make_pair(b, c));
	}

	for (int i = 1; i <= N; i++) {
		if (v[i] == 1) root = i;
	}
}

void setColumnNumber(int idx)
{
	if (idx == -1)
		return;

	setColumnNumber(tree[idx].second.first);
	if (idx > 0) tree[idx].first = ++num;
	setColumnNumber(tree[idx].second.second);
}

void traversal(int idx, int depth)
{
	if (idx == -1)
		return;

	width_v[depth].first = min(width_v[depth].first, tree[idx].first);
	width_v[depth].second = max(width_v[depth].second, tree[idx].first);
	traversal(tree[idx].second.first, depth + 1);
	traversal(tree[idx].second.second, depth + 1);
}

void getAnswer()
{
	int level = 2e9, width = 0;
	int MAX = 0;
	vector<pair<int, int>>temp;

	for (int i = 1; width_v[i].first != 2e9 && width_v[i].second != 0; i++) temp.push_back(make_pair(i, width_v[i].second - width_v[i].first + 1));
	
	for (auto elem : temp) MAX = max(MAX, elem.second);
	
	for (auto elem : temp)
	{
		if (MAX == elem.second)
		{
			if (level > elem.first)
			{
				level = elem.first;
				width = elem.second;
			}
		}
	}
	cout << level << " " << width;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	setColumnNumber(root);
	traversal(root, 1);
	getAnswer();
	return 0;
}