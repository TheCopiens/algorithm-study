#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
long long answer;
vector<int>hash_map(101);

bool comp(int a,int b) {
	return a > b ? true : false;
}

void solve()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = str.length() - 1, k = 1; j >= 0; j--, k *= 10)
			hash_map[str[j] - 'A'] += k;
	}
	sort(hash_map.begin(), hash_map.end(),comp);

	for (int i = 0, j = 9; i < hash_map.size() && hash_map[i]; i++, j--)
		answer += (j * hash_map[i]);	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	solve();
	cout << answer << endl;
	return 0;
}