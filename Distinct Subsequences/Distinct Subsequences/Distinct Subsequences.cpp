#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int numDistinct(string S, string T) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(S.empty())
			return 0;
		vector<vector<int>> dict(T.size(),vector<int>(S.size(),0));
		for(int i = 0 ;i < T.size();i++)
		{
			int count = 0;
			for (int j = i ; j < S.size() ; j++)
			{
				dict[i][j] = count;
				if (S[j] == T[i])
				{
					if (i > 0)
					{
						count += dict[i-1][j - 1];
					}
					else
					{
						count++;
					}

				}
				dict[i][j] = count;
			}
		}
		return dict[T.size() - 1][S.size() - 1];
	}
};