#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> 
using namespace std;

int main()
{
	char board[4][4] = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
	vector<int> inlist;
	stack<int> instack;
	vector<int> accessed;
	for(int i = 0 ; i < 4; i++)
	{
		for(int j = 0 ; j < 4 ; j++)
		{
			int index = i*4+j;
			if(find(accessed.begin(),accessed.end(),index) != accessed.end() != accessed.end())
				continue;
			else
			{
				if(board[i][j] == 'X')
					continue;
				else
				{
					bool onboard = false;
					accessed.push_back(index);
					inlist.push_back(index);
					instack.push(index);
					while (!instack.empty())
					{
						int nowindex = instack.pop();
						int nowi = nowindex / 4;
						int nowj = nowindex % 4;
						if (nowindex < 4 || nowindex%4 == 0 ||(nowindex + 1) % 4 == 0 || nowindex > 12)
						{
							onboard = true;
						} 
						if (nowi > 0 && board[now - 4] == 'O' && find(accessed.begin(),accessed.end(),index) == accessed.end())
						{
							accessed.push_back(nowindex);
							inlist.push_back(nowindex);
							instack.push_back(nowindex);
						}
						if (nowi < 3 && board[now + 4] == 'O' && find(accessed.begin(),accessed.end(),index) == accessed.end())
						{
							accessed.push_back(nowindex);
							inlist.push_back(nowindex);
							instack.push(nowindex);
						}
						if (nowj > 0 && board[now - 1] == 'O' && find(accessed.begin(),accessed.end(),index) == accessed.end())
						{
							accessed.push_back(nowindex);
							inlist.push_back(nowindex);
							instack.push(nowindex);
						}
						if (nowj < 3 && board[now + 1] == 'O' && find(accessed.begin(),accessed.end(),index) == accessed.end())
						{
							accessed.push_back(nowindex);
							inlist.push_back(nowindex);
							instack.push(nowindex);
						}
					}
					if(onboard)
					{
						for(vector<int>::iterator it = inlist.begin(); it != inlist.end() ; it++)
						{
							board[*it] = 'X';
						}
					}

				}
			}
		}
	}
	return 0;
}