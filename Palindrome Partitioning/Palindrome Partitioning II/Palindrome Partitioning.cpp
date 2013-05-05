#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool isPali(string s)
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
		vector<vector<vector<string>>> result;
		vector<vector<string>> first;
		vector<string> ones;
		ones.push_back( s.substr(0,1));
		first.push_back(ones);
		result.push_back(first);
		for (unsigned int i = 1; i < s.size(); ++i)
		{
			vector<vector<string>> temp;
			for (unsigned int j = i;j >= 1; --j)
			{
				string ss = s.substr(j,i - j + 1);
				if (isPali(ss))
				{
					for (vector<vector<string>>::iterator it = result[j-1].begin();it != result[j-1].end();++it)
					{
						temp.push_back(*it);
						temp.rbegin()->push_back(ss);
					}
				}
			}
			string ss = s.substr(0,i + 1);
			if (isPali(ss))
			{
				vector<string> as;
				as.push_back(ss);
				temp.push_back(as);
			}
			result.push_back(temp);
		}
	}
	return 0;
}