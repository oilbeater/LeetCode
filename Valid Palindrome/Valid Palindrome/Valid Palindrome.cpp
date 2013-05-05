#include <string>
using namespace std;
class Solution {
public:
	bool isPal(string s)
	{
		for (string::iterator itb = s.begin(),ite = s.end() - 1;itb < ite;itb++,ite--)
		{
			if(*ite != *itb)
				return false;
		}
		return true;
	}
	string trim(string s)
	{
		string res;
		for (auto it = s.begin();it != s.end(); it++)
		{
			if(*it >= 'a' && *it <= 'z' || *it >='0' && *it <='9')
				res += *it;
			if(*it >= 'A' && *it <= 'Z')
				res += *it + 32;
		}
		return res;
	}
	bool isPalindrome(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(isPal(trim(s)))
			return true;
		else
			return false;
	}
};

int main()
{
	Solution sol;
	sol.isPalindrome("aA");
	return 0;
}