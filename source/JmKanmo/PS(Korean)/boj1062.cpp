#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, K;
vector<string>voca;
int visited[26];
int answer;

void init()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		string sub_str = "";
		for (int j = 4; j < str.length() - 4; j++) sub_str += str[j];
		voca.push_back(sub_str);
	}

	visited['a' - 'a'] = 1;
	visited['n' - 'a'] = 1;
	visited['t' - 'a'] = 1;
	visited['i' - 'a'] = 1;
	visited['c' - 'a'] = 1;
}

int getCntOfRead()
{
	int ret = 0;

	for (int i = 0; i < voca.size(); i++)
	{
		bool flag = false;

		for (auto item : voca[i])
		{
			if (visited[item - 'a'] == 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag) ret++;
	}

	return ret;
}

void dfs(int idx, int cnt)
{
	if (cnt >= K - 5)
	{
		answer = max(answer, getCntOfRead());
		return;
	}

	for (int i = idx + 1; i < 26; i++) {
		if (visited[i])
			continue;

		visited[i] = 1;
		dfs(i, cnt + 1);
		visited[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();

	if (K == 26) {
		answer = N;
	}
	else if (K >= 5) {
		dfs(-1, 0);
	}
	cout << answer << endl;
	return 0;
}