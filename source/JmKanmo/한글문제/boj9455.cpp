#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int M, N;
int board[101][101];
int answer;

void init()
{
	cin >> M >> N;
	answer = 0;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}
}

void boxMoving()
{
	for (int i = M; i >= 1; i--)
	{
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j])
			{
				int cnt = 0, cur_pos = i;

				while (cur_pos + 1 <= M && board[cur_pos + 1][j] == 0)
				{
					cnt++;
					board[++cur_pos][j] = 1;
					board[cur_pos - 1][j] = 0;
				}
				answer += cnt;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int test;
	cin >> test;

	for (int t = 0; t < test; t++)
	{
		init();
		boxMoving();
		cout << answer << endl;
	}
	return 0;
}