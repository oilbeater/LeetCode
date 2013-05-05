#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isPal(string s)
{
	string t = s;
	reverse(t.begin(),t.end());
	return t == s;
}
int main()
{
	string s;
	while (cin>>s)
	{
		vector<int> result;
		result.push_back(0);
		for (unsigned i = 1; i < s.size() ; ++i)
		{
			int min  = result[i-1] + 1;
			if (isPal(s.substr(0,i+1)))
			{
				result.push_back(0);
				continue;
			}
			for(unsigned j = i ; j > 0 ; --j)
			{
				
				if (isPal(s.substr(j,i-j+1)))
				{
					int temp = 1 + result[j - 1];
					if (temp < min)
						min = temp;
				}
			}
			result.push_back(min);
		}
	}
	return 0;
}