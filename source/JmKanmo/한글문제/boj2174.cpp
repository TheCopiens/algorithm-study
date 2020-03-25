#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

struct Order
{
	int number;
	char type;
	int cnt;

	Order() {}

	Order(int number, char type, int cnt) {
		this->number = number;
		this->type = type;
		this->cnt = cnt;
	}
};

struct Robot
{
	Pair pos;
	char dir;

	Robot(){}

	Robot(Pair pos, char dir)
	{
		this->pos = pos;
		this->dir = dir;
	}
};

vector<Robot>robots;
vector<Order> orders;
int A, B;
int N, M;

void init()
{
	cin >> A >> B;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		char dir;
		cin >> x >> y >> dir;
		robots.push_back(Robot(Pair(B - (y - 1), x), dir));
	}

	for (int i = 0; i < M; i++)
	{
		int number;
		char type;
		int cnt;
		cin >> number >> type >> cnt;
		orders.push_back(Order(number, type, cnt));
	}
}

void rotateLeft(int number)
{
	switch (robots[number].dir)
	{
	case 'N':
		robots[number].dir = 'W';
		break;
	case 'W':
		robots[number].dir = 'S';
		break;
	case 'S':
		robots[number].dir = 'E';
		break;
	case 'E':
		robots[number].dir = 'N';
		break;
	}
}

void rotateRight(int number)
{
	switch (robots[number].dir)
	{
	case 'N':
		robots[number].dir = 'E';
		break;
	case 'W':
		robots[number].dir = 'N';
		break;
	case 'S':
		robots[number].dir = 'W';
		break;
	case 'E':
		robots[number].dir = 'S';
		break;
	}
}

bool checkRange(Pair next) {
	if (next.first<1 || next.first > B || next.second < 1 || next.second > A)
		return true;
	else
		return false;
}

int checkCollapse(Pair next)
{
	int i = 0;

	for (auto robot : robots)
	{
		if (robot.pos == next) {
			return i + 1;
		}
		i++;
	}
	return -1;
}

bool moveRobot(int number, char type)
{
	Pair next = Pair();

	if (type == 'N')
		next = Pair(robots[number].pos.first - 1, robots[number].pos.second);

	else if (type == 'S')
		next = Pair(robots[number].pos.first + 1, robots[number].pos.second);

	else if (type == 'W')
		next = Pair(robots[number].pos.first, robots[number].pos.second - 1);
	else
		next = Pair(robots[number].pos.first, robots[number].pos.second + 1);

	if (checkRange(next)) {
		cout << "Robot " << number + 1 << " crashes into the wall" << endl;
		return true;
	}

	int collapseIdx = checkCollapse(next);

	if (collapseIdx > 0) {
		cout << "Robot " << number + 1 << " crashes into robot " << collapseIdx << endl;
		return true;
	}

	robots[number].pos = next;
	return false;
}

bool doOrder(int number, char type)
{
	if (type == 'L') {
		rotateLeft(number);
	}
	else if (type == 'R') {
		rotateRight(number);
	}
	else
	{
		if (moveRobot(number, robots[number].dir)) return true;
	}

	return false;
}

void solve()
{
	for (int i = 0; i < orders.size(); i++)
	{
		Order order = orders[i];

		for (int j = 0; j < order.cnt; j++)
		{
			if (doOrder(order.number - 1, order.type)) {
				return;
			}
		}
	}
	cout << "OK" << endl;
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