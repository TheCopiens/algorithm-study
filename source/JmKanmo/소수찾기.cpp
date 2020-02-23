#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string str_num;
int hash_map[10000001];
int visited[8];
int answer;

bool checkPrimeNums(int N)
{
	for (int i = 2; i <= sqrt(N); i++) {
		if (N % i == 0) return true;
	}
	return false;
}

void solve(int cnt, string num)
{
	if (cnt >= str_num.length())
		return;

	for (int i = 0; i < str_num.length(); i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			num.push_back(str_num[i]);
			if (stoi(num) > 1 && checkPrimeNums(stoi(num)) == 0 && hash_map[stoi(num)] == 0) {
				answer++;
				hash_map[stoi(num)] = 1;
			}
			solve(cnt + 1, num);
			visited[i] = 0;
			num.pop_back();
		}
	}
}

int solution(string numbers) {
	str_num = numbers;
	solve(0, "");
	return answer;
}

int main()
{
	solution("011");
	return 0;
}