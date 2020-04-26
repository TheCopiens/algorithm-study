#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

struct Board
{
	char ch;
	int time;

	Board() {}

	Board(char ch, int time) {
		this->ch = ch;
		this->time = time;
	}
};

int R, C, N;
Board board[201][201];

void init()
{
	cin >> R >> C >> N;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> board[i][j].ch;
		}
	}
}

void solve()
{
	int t = 0;
	bool flag = false;

	while (t < N)
	{
		if (t == 0)
		{
			for (int i = 1; i <= R; i++)
			{
				for (int j = 1; j <= C; j++)
				{
					if (board[i][j].ch == 'O')
						board[i][j].time++;
				}
			}
		}
		else
		{
			if (!flag) {
				for (int i = 1; i <= R; i++)
				{
					for (int j = 1; j <= C; j++)
					{
						if (board[i][j].ch == '.') {
							board[i][j].ch = 'O';
							board[i][j].time = 0;
						}
						else {
							board[i][j].time++;
						}
					}
				}
				flag = true;
			}
			else {
				for (int i = 1; i <= R; i++)
				{
					for (int j = 1; j <= C; j++)
					{
						if (board[i][j].ch == 'O' && board[i][j].time + 1 == 3)
						{
							board[i][j].ch = '.';
							board[i][j].time = 0;

							for (int k = 0; k < 4; k++)
							{
								int n_idx1 = i + idx_1[k], n_idx2 = j + idx_2[k];

								if (n_idx1<1 || n_idx1>R || n_idx2<1 || n_idx2>C)
									continue;

								if (board[n_idx1][n_idx2].ch == 'O' && board[n_idx1][n_idx2].time + 1 < 3) {
									board[n_idx1][n_idx2].ch = '.';
									board[n_idx1][n_idx2].time = 0;
								}
							}
						}
						if (board[i][j].ch == 'O') board[i][j].time++;
					}
				}
				flag = false;
			}
		}
		t++;
	}
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cout << board[i][j].ch;
		}
		cout << "\n";
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