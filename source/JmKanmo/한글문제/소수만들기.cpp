#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int>arr;
vector<int>primeNums = vector<int>(3001, 1);
vector<int>comb;
int answer;

void makePrimeNums()
{
	for (int i = 2; i <= sqrt(3000); i++)
	{
		for (int j = i * 2; j <= 3000; j += i)
			primeNums[j] = 0;
	}
}

void solve(int idx, int cnt)
{
	if (cnt >= 3)
	{
		int SUM = 0;
		for (int i = 0; i < comb.size(); i++) SUM += comb[i];
		if (SUM > 1 && primeNums[SUM]) answer++;
		return;
	}

	for (int i = idx + 1; i < arr.size(); i++)
	{
		comb.push_back(arr[i]);
		solve(i, cnt + 1);
		comb.pop_back();
	}
}

int solution(vector<int> nums) {
	arr = nums;
	makePrimeNums();
	solve(-1, 0);
	return answer;
}
