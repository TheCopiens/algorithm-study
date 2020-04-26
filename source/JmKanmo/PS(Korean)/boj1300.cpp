#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	int left = 1, right = K, answer = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		long long cnt = 0;

		for (int i = 1; i <= N; i++) cnt += min(mid / i, N);

		if (cnt < K)
			left = mid + 1;
		else
		{
			answer = mid;
			right = mid - 1;
		}
	}

	cout << answer << endl;
	return 0;
}