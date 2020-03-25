#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include<cmath>
#include <algorithm>

using namespace std;

bool checkGroupVoca(map<char, vector<int>> checker)
{
	// 참 - true, 거짓 - false 반환

	for (auto voca : checker)
	{
		vector<int> v = voca.second;

		if (v.size() == 1)
			continue;
		else {
			for (int i = 0; i < v.size() - 1; i++) {
				int diff = v[i + 1] - v[i];
				if (diff > 1) {
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	int answer = 0;

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		string str;
		map<char, vector<int>>checker;
		cin >> str;

		for (int j = 0; j < str.length(); j++)
		{
			char ch = str[j];
			checker[ch].push_back(j);
		}

		if (checkGroupVoca(checker))
			answer++;
	}

	cout << answer << endl;
	return 0;
}