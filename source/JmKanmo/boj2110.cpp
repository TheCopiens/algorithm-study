#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int N, C;
vector<int>home_pos;
int answer;

void init()
{
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		int val;
		cin >> val;
		home_pos.push_back(val);
	}
	sort(home_pos.begin(), home_pos.end());
}

bool check(int limit)
{
	int cnt = 1;
	
	for (int i = 1, value = home_pos[0]; i < N; i++)
	{
		if (value + limit <= home_pos[i])
		{
			value = home_pos[i];
			cnt++;
		}
	}

	return cnt >= C ? true : false;
}

void binary_search()
{
	int left = 1, right = home_pos[home_pos.size() - 1] - home_pos[0];

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (check(mid)) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	binary_search();
	cout << answer << endl;
	return 0;
}