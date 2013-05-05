/*
1.交换出错
2.reverse用成了reserve
3.判断不需要计算后忘记把剩余字符串附加到结果中
4.substr用法忘记
*/

#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string a = "100";
	string b = "110010";

	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());

	if (a.size() < b.size())
	{
		string tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	int size = b.size();
	int addin = 0;
	string result = "";
	for(int i = 0 ; i < size ; i++)
	{
		int onebit = (a[i] - '0') + (b[i] - '0') + addin;
		if (onebit == 0 || onebit == 1)
		{
			result += (onebit + '0');
			addin = 0;
		} 
		else
		{
			result += (onebit - 2 + '0');
			addin = 1;
		}
	}
	for(int i = size ; i < a.size() ; i++)
	{
		int onebit = (a[i] - '0') + addin;
		result += (onebit%2 + '0');
		addin = onebit/2;
		if(addin == 0)
		{
			result += a.substr(i+1); 
			break;
		}
	}
	if (addin == 1)
	{
		result += '1';
	}
	reverse(result.begin(),result.end());
	return 0;
}