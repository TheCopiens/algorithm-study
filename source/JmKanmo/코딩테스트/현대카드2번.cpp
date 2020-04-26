#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores) {
	map<string, vector<int>>hash_map;
	vector<bool>isRight = vector<bool>(ip_addrs.size(), true);

	for (int i = 0; i < ip_addrs.size(); i++)
	{
		hash_map[ip_addrs[i]].push_back(i);
	}
	
	for (auto elem : hash_map)
	{
		int SIZE = elem.second.size();

		if (SIZE >= 4)
		{
			for (auto temp : elem.second) {
				isRight[temp] = false;
			}
		}
		else if (SIZE == 3)
		{
			map<string, int>lang_map;
			for (auto temp : elem.second) {
				string lang = langs[temp];
				if (lang == "C" || lang == "C++" || lang == "C#") {
					lang_map["C"]++;
				}
				else {
					lang_map[langs[temp]]++;
				}
			}

			if (lang_map.size() == 1) {
				for (auto temp : elem.second) {
					isRight[temp] = false;

				}
			}
		}
		else if (SIZE == 2)
		{
			map<string, int> lang_map;
			map<int, int> score_map;
			for (auto temp : elem.second) {
				string lang = langs[temp];
				if (lang == "C" || lang == "C++" || lang == "C#") {
					lang_map["C"]++;
				}
				else {
					lang_map[langs[temp]]++;
				}
				score_map[scores[temp]]++;
			}

			if (lang_map.size() == 1 && score_map.size() == 1) {
				for (auto temp : elem.second) {
					isRight[temp] = false;
				}
			}
		}
	}
	int cnt = 0;
	for (auto elem : isRight) {
		if (elem == true) cnt++;
	}
	return cnt;
}

int main()
{
	solution({ "5.5.5.5", "155.123.124.111", "10.16.125.0", "155.123.124.111", "5.5.5.5", "155.123.124.111", "10.16.125.0", "10.16.125.0" },
		{ "Java", "C++", "Python3", "C#", "Java", "C", "Python3", "JavaScript" },
		{ 294, 197, 373, 45, 294, 62, 373, 373 });
}