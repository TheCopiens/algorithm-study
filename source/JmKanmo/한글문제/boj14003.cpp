#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	int cnt = 0;
	vector<int>v;
	vector<int>p;
	vector<int>arr;
	vector<int> answer;

	v.push_back(-2e9);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int val;
		cin >> val;
		arr.push_back(val);

		if (v.back() < val) {
			v.push_back(val);
			p.push_back(++cnt);
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), val);
			*it = val;
			p.push_back(distance(v.begin(), it));
		}
	}

	cout << cnt << endl;

	for (int i = N - 1; i >= 0; i--) {
		if (p[i] == cnt) {
			answer.push_back(arr[i]);
			cnt--;
		}
	}

	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}

	return 0;
}