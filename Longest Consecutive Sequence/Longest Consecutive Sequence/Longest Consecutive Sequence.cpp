#include <unordered_map>
using namespace std;
class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		unordered_map<int,int> numlen;
		int maxlen = 0;
		for (auto it = num.begin();it !=num.end() ;++it)
		{
			if (numlen.count(*it))
				continue;
			int len = 1;
			if (numlen.count(*it + 1))
			{
				len += numlen[*it + 1] ;
				numlen[*it + len - 1] = len;
			}
			int end = *it + len - 1;
			if (numlen.count(*it - 1))
			{
				len += numlen[*it - 1] ;
				numlen[*it - numlen[*it - 1] ] = len;
				numlen[end] =len;
			}
			numlen[*it] = len;
			if(len > maxlen)
				maxlen = len;
		}
		return maxlen;
	}
};

int main()
{
	Solution sol;
	int nn[5]={1,3,5,2,4};
	vector<int> num(nn,nn+5);
	sol.longestConsecutive(num);
}