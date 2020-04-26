#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int answer;
string str;
string target;

int getCntOfStr(int idx)
{
	int cnt = 0;

	for (int i = idx; i < str.length(); i++)
	{
		string substr = str.substr(i, target.length());
		if (substr == target) {
			cnt++;
			i += (target.length() - 1);
		}
	}
	return cnt;
}

void init()
{
	getline(cin, str);
	getline(cin, target);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();

	for (int i = 0; i < str.length(); i++) {
		answer = max(answer, getCntOfStr(i));
	}

	cout << answer << endl;
	return 0;
}