#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int N;
char op[20];
int answer = -2e9;

void init()
{
	cin >> N;
	string str;
	cin >> str;
	for (int i = 1; i <= N; i++)
		op[i] = str[i - 1];
}

int calc(int left, char op, int right)
{
	switch (op)
	{
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	}
}

void dfs(int idx, int sum)
{
	if (idx >= N)
	{
		answer = max(answer, sum);
		return;
	}

	if (idx + 2 <= N)
	{
		dfs(idx + 2, calc(sum, op[idx + 1], op[idx + 2] - '0'));
	}
	if (idx + 4 <= N)
	{
		dfs(idx + 4, calc(sum, op[idx + 1], calc(op[idx + 2] - '0', op[idx + 3], op[idx + 4] - '0')));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	init();

	if (N == 1) {
		cout << op[1] - '0' << endl;
	}
	else {
		dfs(1, op[1] - '0');
		cout << answer << endl;
	}
	return 0;
}