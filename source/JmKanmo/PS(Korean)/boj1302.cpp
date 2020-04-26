#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	map<string, int> hash_map;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		hash_map[str]++;
	}

	string title;
	int MAX = 0;

	for (auto elem : hash_map)
	{
		if (MAX < elem.second) {
			title = elem.first;
			MAX = elem.second;
		}
	}

	cout << title << endl;
	return 0;
}