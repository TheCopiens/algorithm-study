#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str, target;
char answer[1000001];
int idx;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> str >> target;

	for (int i = 0; i < str.length(); i++)
	{
		answer[idx++] = str[i];

		if (answer[idx - 1] == target[target.length() - 1])
		{
			if (idx < target.length())
				continue;

			bool flag = true;

			for (int j = 0; j < target.length(); j++)
			{
				if (answer[idx - 1 - j] != target[target.length() - 1 - j])
				{
					flag = false;
					break;
				}
			}

			if (flag)
				idx -= target.length();
		}
	}

	if (idx == 0) {
		cout << "FRULA" << endl;
	}
	else {
		for (int i = 0; i < idx; i++) {
			cout << answer[i];
		}
		cout << endl;
	}
	return 0;
}