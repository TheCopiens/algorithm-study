#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>


using namespace std;

vector<int> arr;

void init()
{
	for (int i = 1; i <= 9; i++)
	{
		int n;
		cin >> n;
		arr.push_back(n);
	}
}

void solve(int idx, int cnt, vector<int>param)
{
	if (cnt == 7) {
		int SUM = 0;
		for (int i = 0; i < param.size(); i++) {
			SUM += arr[param[i]];
		}
		if (SUM == 100) {
			for (int elem : param) {
				cout << arr[elem] << endl;
			}
		}
		return;
	}

	for (int i = idx + 1; i < arr.size(); i++) {
		param.push_back(i);
		solve(i, cnt + 1, param);
		param.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	solve(-1, 0, {});
	return 0;
}