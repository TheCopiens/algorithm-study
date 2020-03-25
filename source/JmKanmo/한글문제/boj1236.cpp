#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
char board[51][51];
int answer = 2e9;

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++) {
			board[i][j] = str[j - 1];
		}
	}
}

void solve()
{
	int cnt1 = 0;

	for (int i = 1; i <= N; i++)
	{
		bool flag = false;

		for (int j = 1; j <= M; j++)
		{
			if (board[i][j] == 'X') {
				flag = true;
				break;
			}
		}
		if (!flag) cnt1++;
	}

	int cnt2 = 0;

	for (int i = 1; i <= M; i++)
	{
		bool flag = false;

		for (int j = 1; j <= N; j++)
		{
			if (board[j][i] == 'X') {
				flag = true;
				break;
			}
		}
		if (!flag)cnt2++;
	}
	answer = max(cnt1, cnt2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	solve();
	cout << answer << endl;
	return 0;
}