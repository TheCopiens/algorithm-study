#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string str;
int pos;
int temp_pos;
vector<int>factorials(12);

int getFactorial(int N) {
	int ret = 1;
	for (int i = N; i >= 1; i--) ret *= i;
	return ret;
}

void solve()
{
	for (int i = 1; i <= 11; i++) factorials[i] = getFactorial(i);

	while (cin >> str >> pos)
	{
		temp_pos = pos;

		if (pos > getFactorial(str.length())) {
			cout << str << " " << temp_pos << " = ";
			cout << "No permutation" << "\n";
		}
		else {
			vector<char>ret;
			vector<char>arr;
			vector<bool>visited;
			int len = str.length();

			for (int i = 0; i < len; i++) {
				arr.push_back(str[i]);
				visited.push_back(false);
			}

			for (int i = 1; i <= len; i++)
			{
				int cnt = 1;

				while (factorials[len - i] && cnt * factorials[len - i] < pos) cnt++;

				for (int j = 0, k = 0; j < arr.size(); j++) {
					if (visited[j]) continue;

					if (++k == cnt) {
						ret.push_back(str[j]);
						visited[j] = true;
						break;
					}
				}
				pos -= ((cnt - 1) * factorials[len - i]);
			}
			cout << str << " " << temp_pos << " = ";
			for (int i = 0; i < ret.size(); i++) cout << ret[i];
			cout << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}