#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> Pair;

int N;
map<int, Pair>tree;
vector<pair<int, int>> width_v(10001, { 0,2e9 });
int root;

int getCntOfChild(int idx)
{
	if (idx == -1)
		return 0;

	return getCntOfChild(tree[idx].second.first) + getCntOfChild(tree[idx].second.second) + 1;
}

void init()
{
	cin >> N;
	vector<int>v(N + 1);

	for (int i = 1; i <= N; i++)
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
	tree[root].first = 1 + getCntOfChild(tree[root].second.first);
}

void setColumnNumber(int i)
{
	if (i == -1) return;

	int left_child = tree[i].second.first;
	int right_child = tree[i].second.second;

	if (left_child != -1) {
		tree[left_child].first = tree[i].first - (getCntOfChild(tree[left_child].second.second) + 1);
	}

	if (right_child != -1) {
		tree[right_child].first = tree[i].first + (getCntOfChild(tree[right_child].second.first) + 1);
	}
	setColumnNumber(tree[i].second.first);
	setColumnNumber(tree[i].second.second);
}

void traversal(int idx, int depth)
{
	if (idx == -1)
		return;

	width_v[depth].first = max(width_v[depth].first, tree[idx].first);
	width_v[depth].second = min(width_v[depth].second, tree[idx].first);
	traversal(tree[idx].second.first, depth + 1);
	traversal(tree[idx].second.second, depth + 1);
}

void solve()
{
	vector<pair<int, int>> temp;

	for (int i = 1; width_v[i].first != 0 && width_v[i].second != 2e9; i++)
		temp.push_back(make_pair(i, width_v[i].first - width_v[i].second + 1));

	int MAX = 0;
	int a, b;

	for (auto elem : temp) {
		if (MAX < elem.second) {
			a = elem.first;
			b = elem.second;
			MAX = elem.second;
		}
	}
	cout << a << " " << b << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	setColumnNumber(root);
	traversal(root, 1);
	solve();
	return 0;
}
