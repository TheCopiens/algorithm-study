#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, K;
map<int, int> hash_map;

void init()
{
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int val;
		cin >> val;
		hash_map[val] = 1;
	}
}

bool checkNumber(int num)
{
	vector<int>ret;
	int div = 10;

	while (num != 0)
	{
		if (hash_map.count(num % 10) == 0)
		{
			return true;
		}
		num /= 10;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();

	for (int i = N; i >= 1; i--) {
		if (N >= i)
		{
			if (!checkNumber(i)) {
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}