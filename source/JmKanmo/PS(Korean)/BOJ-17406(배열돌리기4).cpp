#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

struct Rotate {
	int r, c, s;

	Rotate() {}

	Rotate(int r, int c, int s) {
		this->r = r;
		this->c = c;
		this->s = s;
	}

	Pair left_Up() {
		return Pair(r - s, c - s);
	}

	Pair right_Down() {
		return Pair(r + s, c + s);
	}
};

int N, M, K;
vector<vector<int>> board;
vector<Rotate>rotates;
vector<bool>visited;
int answer = 2e9;

void init()
{
	cin >> N >> M >> K;

	board = vector<vector<int>>(N + 1, vector<int>(M + 1));
	visited = vector<bool>(K + 1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		rotates.push_back(Rotate(r, c, s));
	}
}

vector<vector<int>>do_rotate(vector<vector<int>>board, Rotate rot_info)
{
	Pair left_up = rot_info.left_Up();
	Pair right_down = rot_info.right_Down();
	Pair left_down = Pair(right_down.first, left_up.second);
	Pair right_up = Pair(left_up.first, right_down.second);

	vector<vector<int>>ret = board;

	while (left_up.first < right_down.first)
	{
		for (int i = left_up.second; i < right_up.second; i++) {
			ret[left_up.first][i + 1] = board[left_up.first][i];
		}

		for (int i = right_up.first; i < right_down.first; i++) {
			ret[i + 1][right_up.second] = board[i][right_up.second];
		}

		for (int i = right_down.second; i > left_down.second; i--) {
			ret[right_down.first][i - 1] = board[right_down.first][i];
		}

		for (int i = left_down.first; i > left_up.first; i--) {
			ret[i - 1][left_down.second] = board[i][left_down.second];
		}

		left_up = Pair(left_up.first + 1, left_up.second + 1);
		left_down = Pair(left_down.first - 1, left_down.second + 1);
		right_up = Pair(right_up.first + 1, right_up.second - 1);
		right_down = Pair(right_down.first - 1, right_down.second - 1);
	}

	return ret;
}

int get_Min(vector<vector<int>>board) {
	int MIN = 2e9;

	for (int i = 1; i <= N; i++)
	{
		int SUM = 0;

		for (int j = 1; j <= M; j++)
			SUM += board[i][j];

		MIN = min(MIN, SUM);
	}
	return MIN;
}

void solve(int cnt, vector<vector<int>>board)
{
	if (cnt >= rotates.size())
	{
		answer = min(answer, get_Min(board));
		return;
	}

	for (int i = 0; i < rotates.size(); i++)
	{
		if (visited[i] == false)
		{
			//회전함수호출
			vector<vector<int>>temp = do_rotate(board, rotates[i]);
			visited[i] = true;
			solve(cnt + 1, temp);
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	init();
	solve(0, board);
	cout << answer << endl;
	return 0;
}