#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int N;
vector<char> alphabets;
vector<string>voca_list;
bool visited[10];
int hash_map[100];
int alphabet_len;
long long answer;

void init()
{
	map<char, int>hash_map;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		voca_list.push_back(str);

		for (int j = 0; j < str.length(); j++) {
			if (hash_map.count(str[j]) == 0) {
				hash_map[str[j]] = 1;
				alphabets.push_back(str[j]);
			}
		}
	}
	alphabet_len = alphabets.size();
}

void solve(int idx)
{
	if (idx >= alphabet_len)
	{
		long long SUM = 0;

		for (int i = 0; i < voca_list.size(); i++)
		{
			long long temp_sum = 0;

			for (int j = 0; j < voca_list[i].size(); j++)
			{
				temp_sum += hash_map[voca_list[i][j]];
				temp_sum *= 10;
			}
			SUM += temp_sum;
		}
		answer = max(answer, SUM);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (visited[i]) continue;
		hash_map[alphabets[idx]] = i;
		visited[i] = 1;
		solve(idx + 1);
		hash_map[alphabets[idx]] = 0;
		visited[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	init();
	solve(0);
	cout << answer / 10 << endl;
	return 0;
}