#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

int N, type;
vector<int>arr;
LL factorial[21];
LL K;
bool checked[21];
vector<int>v;

void setFactorial()
{
	factorial[1] = 1;

	for (int i = 2; i <= N; i++) {
		factorial[i] = i * factorial[i - 1];
	}
}

void init()
{
	cin >> N;
	cin >> type;

	if (type == 1)
	{
		cin >> K;
	}
	else
	{
		for (int i = 1; i <= N; i++) {
			int val;
			cin >> val;
			arr.push_back(val);
			v.push_back(i);
		}
	}
	setFactorial();
}

void solve()
{
	if (type == 1)
	{
		for (int i = 1; i <= N; i++)
		{
			int cnt = 1;

			while (factorial[N - i] && cnt * factorial[N - i] < K) cnt++;

			for (int j = 1, k = 0; j <= N; j++) {
				if (checked[j]) continue;
				else {
					if (++k == cnt) {
						arr.push_back(j);
						checked[j] = 1;
						K -= ((k - 1) * factorial[N - i]);
						break;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		LL prevPos = factorial[N];

		for (int i = 0; i < arr.size(); i++)
		{
			int f = 0;
			for (int j = v.size() - 1, k = 0; j >= 0; j--, k++) {
				if (v[j] == arr[i]) {
					f = k;
					v.erase(v.begin() + j);
					break;
				}
			}
			prevPos -= (factorial[N - (i + 1)] * f);
		}
		cout << prevPos << endl;
	}
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