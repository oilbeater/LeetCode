// 3SumClosest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int myarray[4] = {0,1,2};
	vector<int> num(myarray , myarray + 3);
	int target = 0;

	sort(num.begin(),num.end());
	int size = num.size();
	int result = num[0] + num[1] + num[size - 1];
	for(int i = 0 ; i < size - 2 ; i++)
	{
		int k = size - 1;
		for(int j = i + 1 ; j < k ; )
		{
			int tmp = num[i] + num[j] + num[k];
			if (tmp > target)
			{
				k--;
			} 
			else
			{
				j++;
			}
			if (abs(result - target) > abs(tmp - target))
			{
				result = tmp;
			}
		}
	}
	return 0;
}

