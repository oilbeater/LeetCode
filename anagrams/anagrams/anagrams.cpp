#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main()
{
	vector<string> strs;
	strs.push_back("tin");
	strs.push_back("ram");
	strs.push_back("zip");
	strs.push_back("cry");
	strs.push_back("pus");
	strs.push_back("jon");
	strs.push_back("zip");
	strs.push_back("pyx");
	vector<string> res;
	map<int , int> firststr;
	set<int> hashtable;
	int prim[24] = {2,3, 5, 7, 11, 13, 17, 19, 23, 29,31,37 ,41,43, 47, 53, 59, 61, 67, 71,73, 79,83,89 };
	for(vector<string>::iterator it = strs.begin();it != strs.end(); it++)
	{
		int primevalue = 1;
		for(int i = 0 ; i < (*it).size() ; i ++)
		{
			primevalue *= prim[(*it)[i] - 'a']; 
		}
		if(hashtable.find(primevalue) != hashtable.end())
		{
			if(firststr[primevalue] != -1)
			{
				res.push_back(strs[firststr[primevalue]]);
				firststr[primevalue] = -1;
			}
			res.push_back(*it);
		}
		else
		{
			hashtable.insert(primevalue);
			firststr[primevalue] = it - strs.begin();
		}
	}
	return 0;
}