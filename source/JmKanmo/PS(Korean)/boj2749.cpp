#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	long long n;
	int M = 1000000;
	int P = 15 * (M / 10);
	vector<int>fibo = vector<int>(P + 1, 0);

	cin >> n;

	fibo[1] = 1;

	for (int i = 2; i <= P; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2])%M;
	}

	cout << fibo[n % P] << endl;

	return 0;
}