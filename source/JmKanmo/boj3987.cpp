#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

int N, M;
const int INF = 2e9;
char board[501][501];
int PR, PC;

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;

		for (int j = 1; j <= str.length(); j++) {
			board[i][j] = str[j - 1];
		}
	}
	cin >> PR >> PC;
}

bool checkRange(Pair pos)
{
	if (pos.first<1 || pos.first>N || pos.second<1 || pos.second>M)
		return true;
	else
		return false;
}

int getIntDir(char dir)
{
	switch (dir)
	{
	case 'U': return 3;
	case 'D': return 2;
	case 'L': return 1;
	case 'R': return 0;
	}
}

char getRotatedDir(char galaxy, char dir)
{
	if (galaxy == '/')
	{
		if (dir == 'L') return 'D';
		else if (dir == 'R') return 'U';
		else if (dir == 'U') return 'R';
		else return 'L';
	}
	else
	{
		if (dir == 'L') return 'U';
		else if (dir == 'R') return 'D';
		else if (dir == 'U') return 'L';
		else return 'R';
	}
}

int solve(char dir, Pair pos)
{
	int time = 0;
	map<pair<char, Pair>, int> visited;

	while (true)
	{		
		if (checkRange(pos)) break;

		if (visited[make_pair(dir, pos)]) {
			return INF;
		}

		else {
			visited[make_pair(dir, pos)] = 1;
		}

		char ch = board[pos.first][pos.second];

		if (ch == 'C') break;

		if (ch == '.') {
			pos = Pair(pos.first + idx_1[getIntDir(dir)], pos.second + idx_2[getIntDir(dir)]);
			time++;
			continue;
		}

		dir = getRotatedDir(ch, dir);
		pos = Pair(pos.first + idx_1[getIntDir(dir)], pos.second + idx_2[getIntDir(dir)]);
		time++;
	}
	return time;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	int MAX_ = 0;
	char MAX_CH = 0;
	char dir[] = { 'U','R','D','L' };

	for (int i = 0; i < 4; i++)
	{
		int ret = solve(dir[i], Pair(PR, PC));

		if (MAX_ < ret) {
			MAX_ = ret;
			MAX_CH = dir[i];
		}
	}

	if (MAX_ == INF) {
		cout << MAX_CH << endl;
		cout << "Voyager" << endl;
	}
	else {
		cout << MAX_CH << endl;
		cout << MAX_ << endl;
	}
	return 0;
}