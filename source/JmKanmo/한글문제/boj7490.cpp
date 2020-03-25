#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int N;
vector<int>arr;
vector<string>ret;
vector<string>answer;

void calc()
{
	string exp = "";

	for (int i = 0; i < ret.size(); i++)
	{
		if (ret[i] == " ")
			exp += ret[++i];
		else
			exp += ret[i];
	}

	long long tempRet = 0;
	long long calcRet = 0;
	char op = '0';

	for (int i = 0; i < exp.size(); i++)
	{
		if (exp[i] == '+' || exp[i] == '-')
		{
			if (op == '0')
			{
				calcRet = tempRet;
			}
			else
			{
				if (op == '+')
				{
					calcRet += tempRet;
				}
				else
				{
					calcRet -= tempRet;
				}
			}
			op = exp[i];
			tempRet = 0;
		}
		else
		{
			tempRet *= 10;
			tempRet += (exp[i] - '0');
		}
	}

	if (op == '+')
	{
		calcRet += tempRet;
	}
	else
	{
		calcRet -= tempRet;
	}

	if (calcRet == 0) {
		string str = "";
		for (int i = 0; i < ret.size(); i++) str += ret[i];
		answer.push_back(str);
	}
}

void solve(int idx, int cnt)
{
	if (cnt >= arr.size())
	{
		calc();
		return;
	}

	if (idx % 2 != 0)
	{
		for (int i = 1; i <= 3; i++)
		{
			switch (i)
			{
			case 1:
				ret.push_back("+");
				solve(idx + 1, cnt);
				ret.pop_back();
				break;
			case 2:
				ret.push_back("-");
				solve(idx + 1, cnt);
				ret.pop_back();
				break;
			case 3:
				ret.push_back(" ");
				solve(idx + 1, cnt);
				ret.pop_back();
				break;
			}
		}
	}
	else
	{
		ret.push_back(to_string(arr[cnt]));
		solve(idx + 1, cnt + 1);
		ret.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int test;
	cin >> test;

	for (int t = 0; t < test; t++)
	{
		cin >> N;
		arr = vector<int>(N);
		for (int i = 0; i < N; i++) arr[i] = i + 1;
		solve(0, 0);
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << "\n";
		}
		cout << "\n";
		ret.clear();
		answer.clear();
	}
	return 0;
}