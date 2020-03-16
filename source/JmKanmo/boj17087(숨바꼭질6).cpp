#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

int N, S;
vector<int>pos;

void init()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		pos.push_back(val);
	}
}

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	else
		return gcd(b % a, a);
}

int solve()
{
	vector<int>v;

	for (int i = 0; i < pos.size(); i++) {
		v.push_back(abs(pos[i] - S));
	}

	int ans = v[0];

	for (int i = 0; i < v.size(); i++) {
		ans = gcd(ans, v[i]);
	}
	return ans;
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