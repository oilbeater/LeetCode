#include <unordered_set>
#include <list>
#include <set>
using namespace std;
class Solution {
public:
	bool isDistOne(string src,string des)
	{
		if (src.length() != des.length())
			return false;
		int len = src.length();
		int diff = 0;
		for(int i = 0; i < len ; i++)
		{
			if (src[i] != des[i])
				++diff;
			if(diff > 1)
				return false;
		}
		if(diff == 1)
			return true;
		else
			return false;
	}
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(start == end)
			return 0;
		set<string> find;
		find.insert(start);
		dict.erase(start);
		int ladder = 1;
		while(find.size() != 0)
		{
			set<string> temp;
			for (auto its = find.begin();its != find.end();++its)
			{
				for (auto itd = dict.begin();itd != dict.end();++itd)
				{
					if (isDistOne(*its,*itd))
						temp.insert(*itd);
				}
				for (auto its = temp.begin();its != temp.end();++its)
				{
					if (dict.count(*its) > 0)
						dict.erase(*its);
				}
			}
			find = temp;
			ladder++;
			if(find.find(end) != find.end())
				return ladder;
		}
		return 0;
	}
};