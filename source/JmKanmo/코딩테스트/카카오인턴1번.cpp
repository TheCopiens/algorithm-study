#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;
	stack<int>st;

	for (int i = 0; i < moves.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (board[j][moves[i] - 1])
			{
				if (!st.empty() && board[j][moves[i] - 1] == st.top())
				{
					answer += 2;
					st.pop();
				}
				else {
					st.push(board[j][moves[i] - 1]);
				}
				board[j][moves[i] - 1] = 0;
				break;
			}
		}
	}
	return answer;
}

int main()
{
	solution({ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} },
		{ 1,5,3,5,1,2,1,4 });
	return 0;
}