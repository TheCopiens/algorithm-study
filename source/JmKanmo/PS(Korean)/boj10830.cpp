#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int N;
LL B;

vector<vector<LL>> answer(6, vector<LL>(6));
vector<vector<LL>> matrix(6, vector<LL>(6));

vector<vector<LL>> mulMaxrix(vector<vector<LL>>matrix1, vector<vector<LL>>matrix2)
{
	vector<vector<LL>>mul(6, vector<LL>(6));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			LL SUM = 0;

			for (int k = 1; k <= N; k++)
				SUM += (matrix1[i][k] * matrix2[k][j]);

			mul[i][j] = SUM;
			mul[i][j] %= 1000;
		}
	}
	return mul;
}

void init()
{
	cin >> N >> B;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> matrix[i][j];

			if (i == j) {
				answer[i][j] = 1;
			}
		}
	}
}

void solve()
{
	while (B > 0)
	{
		if (B % 2 != 0)
			answer = mulMaxrix(answer, matrix);

		matrix = mulMaxrix(matrix, matrix);
		B /= 2;
	}
}

void print()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	solve();
	print();
	return 0;
}
