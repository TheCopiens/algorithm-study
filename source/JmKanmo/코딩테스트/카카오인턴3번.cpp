#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int answer = 0;
int banner_cnt = 0;
int userId_cnt = 0;
vector<int>ids;
vector<string>userId;
vector<string>bannerId;
int visited[9];
bool flag = false;

bool check(string user, string banner) {
	if (user.length() != banner.length())
		return false;
	else {
		for (int i = 0; i < user.length(); i++) {
			if (banner[i] == '*' || user[i] == banner[i])
				continue;
			else {
				return false;
			}
		}
		return true;
	}
}

void checkId(int idx)
{
	if (idx >= ids.size()) {
		flag = true;
		return;
	}

	for (int i = 0; i < bannerId.size(); i++) {
		if (!visited[i] && check(userId[ids[idx]], bannerId[i])) {
			visited[i] = 1;
			checkId(idx + 1);
			visited[i] = 0;
		}
	}
}

void dfs(int idx, int cnt)
{
	if (cnt >= banner_cnt)
	{
		checkId(0);
		if (flag) {
			answer++;
			flag = false;
		}
		return;
	}

	for (int i = idx + 1; i < userId_cnt; i++) {
		ids.push_back(i);
		dfs(i, cnt + 1);
		ids.pop_back();
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	userId = user_id;
	bannerId = banned_id;
	banner_cnt = banned_id.size();
	userId_cnt = user_id.size();
	dfs(-1, 0);
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "*rodo", "******", "******" }) << endl;
	return 0;
}