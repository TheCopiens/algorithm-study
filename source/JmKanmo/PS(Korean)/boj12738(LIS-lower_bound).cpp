#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int N;
	int answer = 0;
	vector<int>arr;
	arr.push_back(-2e9);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int val;
		cin >> val;

		if (arr.back() < val) {
			arr.push_back(val);
			answer++;
		}
		else {
			auto it = lower_bound(arr.begin(), arr.end(), val);
			*it = val;
		}
	}
	cout << answer << endl;
	return 0;
}