#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	map<string, int>hash_map =
	{
	{"c=",1},{"c-",1},{"dz=",1},{"d-",1},
	{"lj",1},{"nj",1},{"s=",1},{"z=",1}
	};

	string str;
	int idx = 0;
	int cnt = 0;

	cin >> str;

	while (idx < str.length())
	{
		string sub1 = str.substr(idx, 2);
		string sub2 = str.substr(idx, 3);

		if (hash_map.count(sub1)) {
			idx += 2;
		}
		else if (hash_map.count(sub2)) {
			idx += 3;
		}
		else {
			idx += 1;
		}
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}