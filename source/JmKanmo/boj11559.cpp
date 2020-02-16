#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

char board[13][7];
vector<vector<bool>>visited = vector<vector<bool>>(13, vector<bool>(7));

void init()
{
	for (int i = 1; i <= 12; i++)
	{
		string str;
		cin >> str;

		for (int j = 1; j <= 6; j++)
		{
			board[i][j] = str[j - 1];
		}
	}
}

bool range_check(Pair next)
{
	if (next.first < 1 || next.first>12 || next.second < 1 || next.second>6) return true;
	else return false;
}

int bfs(Pair start, char color)
{
	queue<Pair>q;
	vector<vector<bool>>temp_visited = visited;
	int cnt = 1;

	q.push(start);
	temp_visited[start.first][start.second] = true;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx_1[i], pos.second + idx_2[i]);

			if (range_check(next)) continue;

			if (temp_visited[next.first][next.second] == false && board[next.first][next.second] == color)
			{
				temp_visited[next.first][next.second] = true;
				q.push(next);
				cnt++;
			}
		}
	}
	if (cnt >= 4) {
		visited = temp_visited;
	}
	return cnt;
}

void erase_puyo()
{
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (visited[i][j])
			{
				board[i][j] = '.';
			}
		}
	}
}

void down_puyo()
{
	for (int i = 12; i >= 1; i--)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (board[i][j] != '.')
			{
				int cur_pos = i;

				while (cur_pos < 12 && board[cur_pos + 1][j] == '.')
				{
					board[cur_pos + 1][j] = board[cur_pos][j];
					board[cur_pos][j] = '.';
					cur_pos++;
				}
			}
		}
	}
}

int solve()
{
	int time = 0;

	while (true)
	{
		bool flag = false;

		for (int i = 1; i <= 12; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				if (board[i][j] != '.' && visited[i][j] == false)
				{
					if (bfs(Pair(i, j), board[i][j]) >= 4) {
						flag = true;
					}
				}
			}
		}
		if (flag) {
			time++;
			erase_puyo();
			down_puyo();
			visited = vector<vector<bool>>(13, vector<bool>(7, false));
		}
		else {
			break;
		}
	}
	return time;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	cout << solve() << endl;
	return 0;
}
