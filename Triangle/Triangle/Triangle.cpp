/*题意有问题，答案不允许从右向左的找数字*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int minval = 0;
		if(triangle.empty())
			return minval;
		for (auto it = triangle.begin() + 1;it != triangle.end(); it++)
		{
			for (int i = 0; i < it->size();i++)
			{
				int front;
				if(i > 0)
				{
					front = (*(it-1))[i - 1];
					if (i < (*(it-1)).size())
						front = min(front,(*(it-1))[i]);
				}
				else
				{
					front = (*(it-1))[i];
				}
			//	if (i + 1 < (*(it-1)).size())
			//		front = min(front,(*(it-1))[i + 1]);
				(*it)[i] += front;
			}
		}
		minval = triangle[triangle.size() - 1][0];
		for (int i = 1;i < triangle[triangle.size() - 1].size();i++)
		{
			if(minval > triangle[triangle.size() - 1][i])
				minval = triangle[triangle.size() - 1][i];
		}
		return minval;
	}
};

int main()
{
	vector<vector<int>> triangle;
	vector<int> a,b;
	a.push_back(-1);
	b.push_back(-100);
	b.push_back(-2);
	b.push_back(-4);
	b.push_back(-2);
	b.push_back(-3);
	Solution sol;
	triangle.push_back(a);
	triangle.push_back(b);
	sol.minimumTotal(triangle);
}