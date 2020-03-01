#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int>prize(N + 1);

	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		prize[i] = val;
	}

	int left = 1, right = 1;

	for (int i = 0, MAX = prize[i]; i < N - 1; i++) {
		if (MAX < prize[i + 1]) {
			left++;
			MAX = prize[i + 1];
		}
	}

	for (int i = N - 1, MAX = prize[i]; i > 0; i--) {
		if (prize[i - 1] > MAX) {
			right++;
			MAX = prize[i - 1];
		}
	}

	cout << left << endl;
	cout << right << endl;
	return 0;
}