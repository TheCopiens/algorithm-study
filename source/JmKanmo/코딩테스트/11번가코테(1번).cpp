#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int solution(string S, string pattern)
{
	int answer = 0;
	int patLen = pattern.length();
	map<char, int> hash_map;

	for (int i = 0; i < patLen; i++) hash_map[pattern[i]]++;

	for (int i = 0; i <= S.length() - patLen; i++)
	{
		map<char, int>temp_map;

		for (int j = i; j < i + patLen; j++) temp_map[S[j]]++;

		bool flag = true;

		for (auto elem : hash_map)
		{
			if (temp_map[elem.first] != elem.second) {
				flag = false;
				break;
			}
		}
		if (flag) {
			answer++;
		}
	}
	return answer;
}
