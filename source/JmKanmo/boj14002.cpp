#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, vector<int>>Pair;

int N;
vector<int>v;

void init()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
}

void solve()
{
	vector<Pair>dp(N);

	for (int i = 0; i < v.size(); i++)
	{
		int MAX = 0;
		int idx = -1;

		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
			{
				if (MAX < dp[j].first)
				{
					MAX = dp[j].first;
					idx = j;
				}
			}
		}
		dp[i].first = (MAX + 1);
		if (idx != -1)dp[i].second = dp[idx].second;
		dp[i].second.push_back(v[i]);
	}

	Pair answer = { 0,{} };

	for (int i = 0; i < dp.size(); i++)
	{
		if (answer.first < dp[i].first)
		{
			answer.first = dp[i].first;
			answer.second = dp[i].second;
		}
	}

	cout << answer.first << endl;

	for (auto elem : answer.second)
		cout << elem << " ";	
	cout << endl;
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