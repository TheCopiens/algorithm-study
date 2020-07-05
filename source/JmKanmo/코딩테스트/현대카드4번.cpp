#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;
const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

vector<vector<int>>board(7, vector<int>(7));
vector<vector<int>>visited(7, vector<int>(7));

void insertMacaron(int pos, int type)
{
	for (int i = 1; i <= 6;)
	{
		if (i + 1 <= 6 && board[i + 1][pos] == 0) {
			i++;
		}
		else {
			board[i][pos] = type;
			break;
		}
	}
}

bool bfs(Pair start, int type)
{
	queue<Pair>q;
	int cnt = 0;
	vector<vector<int>>temp_visited = visited;
	q.push(start);
	temp_visited[start.first][start.second] = 1;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx_1[i], pos.second + idx_2[i]);
			if (next.first < 1 || next.first>6 || next.second < 1 || next.second>6)
				continue;
			if (temp_visited[next.first][next.second]) continue;
			if (board[next.first][next.second] == type) {
				temp_visited[next.first][next.second] = 1;
				q.push(next);
			}
		}
	}
	if (cnt >= 3) {
		visited = temp_visited;
	}
	return cnt >= 3 ? true : false;
}

bool setBfs()
{
	bool flag = false;

	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (board[i][j] != 0 && !visited[i][j])
			{
				if (bfs(Pair(i, j), board[i][j])) {
					flag = true;
				}
			}
		}
	}
	return flag;
}

void eraseMacaron() {
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++)
		{
			if (visited[i][j]) {
				visited[i][j] = 0;
				board[i][j] = 0;
			}
		}
	}
}

void downMacaron()
{
	for (int i = 6; i >= 1; i--)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (board[i][j] != 0)
			{
				int m = i;

				while (m + 1 <= 6 && board[m + 1][j] == 0)
				{
					board[m + 1][j] = board[m][j];
					board[m][j] = 0;
					m++;
				}
			}
		}
	}
}

vector<string> solution(vector<vector<int>> macaron) {
	vector<string> answer;

	for (vector<int>elem : macaron)
	{
		insertMacaron(elem[0], elem[1]);
		while (setBfs()) {
			eraseMacaron();
			downMacaron();
		}
	}

	for (int i = 1; i <= 6; i++)
	{
		string ret = "";

		for (int j = 1; j <= 6; j++)
		{
			ret += to_string(board[i][j]);
		}
		answer.push_back(ret);
	}
	return answer;
}

int main()
{
	vector<string> ret = solution({ {1, 1},{2, 1},{1, 2},{3, 3},{6, 4},{3, 1},{3, 3},{3, 3},{3, 4},{2, 1}});

	return 0;
}