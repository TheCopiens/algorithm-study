#include <string>
#include <vector>

using namespace std;

bool checkNewId(vector<string> registered_list, string new_id)
{
	for (string id : registered_list)
	{
		if (new_id == id) 
		{
			return false;
		}
	}
	return true;
}

bool checkSubStr(string str_a, string str_b)
{
	if (str_a.length() < 3 || str_a.length() > 6) return false;

	if (str_b.length() > 6) return false;

	for (int i = 0; i < str_a.length(); i++)
	{
		if (isupper(str_a[i]) || !isalpha(str_a[i])) return false;
	}

	if (str_b.length() >= 1)
	{
		if (str_b[0] == '0') {
			return false;
		}
	}
	return true;
}

pair<string, string> splitStr(string id)
{
	string str_a = "", str_b = "";

	for (int i = 0; i < id.length(); i++)
	{
		if (isalpha(id[i])) {
			str_a += id.substr(i, 1);
		}
		else {
			str_b += id.substr(i, 1);
		}
	}
	return make_pair(str_a, str_b);
}

string makeNewId(string new_id)
{
	pair<string, string>splited = splitStr(new_id);
	string first = splited.first;
	if (splited.second == "") {
		first += "0";
	}
	else {
		first += to_string(stoi(splited.second) + 1);
	}
	return first;
}

bool checkSum(string new_id)
{
	for (int i = 0; i < new_id.length(); i++)
	{
		string str_a = new_id.substr(0, i + 1);
		string str_b = new_id.substr(i + 1, new_id.length());
		if (checkSubStr(str_a, str_b)) {
			return true;
		}
	}
	return false;
}

string solution(vector<string> registered_list, string new_id) {
	string answer = "";

	while (checkNewId(registered_list, new_id) == false || !checkSum(new_id))
	{
		new_id = makeNewId(new_id);
	}
	answer = new_id;
	return answer;
}

int main()
{
	string str = solution({ "cow", "cow1", "cow2", "cow3", "cow4", "cow9", "cow8", "cow7", "cow6", "cow5" },"cow");
}