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

int N, R, C;
int answer = -1;

void init()
{
	cin >> N >> R >> C;
}

bool solve(int idx1, int idx2, int depth)
{
	if (depth == 1)
	{
		answer++;

		if (idx1 == R && idx2 == C) {
			return true;
		}

		answer++;

		if (idx1 == R && idx2 + 1 == C) {
			return true;
		}

		answer++;

		if (idx1 + 1 == R && idx2 == C) {
			return true;
		}

		answer++;

		if (idx1 + 1 == R && idx2 + 1 == C) {
			return true;
		}

		return false;
	}

	if (solve(idx1, idx2, depth / 2))
		return true;

	if (solve(idx1, idx2 + depth, depth / 2))
		return true;

	if (solve(idx1 + depth, idx2, depth / 2))
		return true;

	if (solve(idx1 + depth, idx2 + depth, depth / 2))
		return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	solve(0, 0, pow(2, N) / 2);
	cout << answer << endl;
	return 0;
}