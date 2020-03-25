#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
	vector<int>dp(N);

	for (int i = 0; i < v.size(); i++)
	{
		int MAX = 0;

		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
				MAX = max(MAX, dp[j]);
		}
		dp[i] = (MAX + v[i]);
	}

	int answer = 0;

	for (int i = 0; i < N; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer << endl;
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