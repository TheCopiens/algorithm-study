#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int N;
	int cnt = 1;
	int time = 0;

	cin >> N;

	while (true)
	{
		if (N >= cnt) {
			N -= cnt;
			cnt++;
			time++;
		}
		else {
			cnt = 1;
		}
		if (N <= 0) break;
	}

	cout << time << endl;
	return 0;
}