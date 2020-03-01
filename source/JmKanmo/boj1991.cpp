#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

map<char, pair<char, char>>tree;
int N;

void init()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		tree[a] = make_pair(b, c);
	}
}

void PreOrderTraversal(char ch)
{
	if (ch == '.') 
		return;

	cout << ch;
	PreOrderTraversal(tree[ch].first);
	PreOrderTraversal(tree[ch].second);
}

void InOrderTraversal(char ch)
{
	if (ch == '.')
		return;

	InOrderTraversal(tree[ch].first);
	cout << ch;
	InOrderTraversal(tree[ch].second);
}

void PostOrderTraversal(char ch)
{
	if (ch == '.')
		return;

	PostOrderTraversal(tree[ch].first);
	PostOrderTraversal(tree[ch].second);
	cout << ch;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	PreOrderTraversal('A');
	cout << endl;
	InOrderTraversal('A');
	cout << endl;
	PostOrderTraversal('A');
	cout << endl;
	return 0;
}