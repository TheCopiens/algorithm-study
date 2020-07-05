#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

string str;
string target;
map<string, int>hash_map;

void init()
{
	cin >> str;
	cin >> target;
	for (int i = 1; i <= target.length(); i++) {
		hash_map[target.substr(i - 1, 1)] = i;
	}
}

void solve()
{
	stack<string>st;

	for (int i = 0; i < str.length(); i++)
	{
		st.push(str.substr(i, 1));

		if (hash_map[str.substr(i, 1)] == target.length())
		{
			if (st.size() < target.size()) continue;

			stack<string>temp_st;
			bool flag = true;

			for (int j = 0; j < target.length(); j++)
			{
				string prev_str = st.top();
				temp_st.push(prev_str);
				st.pop();

				if (hash_map[prev_str] != target.length() - j) {
					flag = false;
					break;
				}
			}

			if (!flag)
			{
				while (temp_st.empty() != true) {
					st.push(temp_st.top());
					temp_st.pop();
				}
			}
			else {
				while (temp_st.empty() != true)
					temp_st.pop();
			}
		}
	}

	if (st.empty()) {
		cout << "FRULA" << endl;
	}
	else {
		string answer = "";
		while (st.empty() != true) {
			answer += st.top();
			st.pop();
		}
		reverse(answer.begin(), answer.end());
		cout << answer << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	solve();
	return 0;
}