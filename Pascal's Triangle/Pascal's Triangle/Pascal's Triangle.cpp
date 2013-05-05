#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int>> res;
		for(int i = 0 ;i < numRows ; i++)
		{
			vector<int> temp;
			if(i > 0)
				temp.push_back(1);
			for (int j = 0 ;j < i - 1;j++)
				temp.push_back(res[i - 1][j] + res[i - 1][j + 1]);
			temp.push_back(1);
			res.push_back(temp);
		}
		return res;
	}
};