
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int myarray[6] = {-1,0,1,2,-1,4};
	vector<int> num(myarray , myarray + 6);
	vector<vector<int> > reslist;
	int target = 0;
	sort(num.begin(),num.end());
	int size = num.size();

	int result = num[0] + num[1] + num[size - 1];
	for(int i = 0 ; i < size - 2 ; )
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
				if(tmp < target)
					j++;
				else
				{
					int myarray[3] = {num[i],num[j],num[k]};
					vector<int> oneres(myarray , myarray + 3);
					reslist.push_back(oneres);
					while(num[j] == myarray[1])
						j++;
					while(num[k] == myarray[2])
						k--;
				}
			}
		}
		while(num[i+1] == num[i])
			i++;
		i++;
	}   
	return 0;
}