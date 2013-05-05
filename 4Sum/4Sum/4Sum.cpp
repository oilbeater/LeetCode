#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class sum
{
public:
	int addsum;
	int aindex;
	int bindex;
	sum(int adds,int i ,int j){
		addsum = adds;
		aindex = i;
		bindex = j;
	}
};
bool cmp(sum i,sum j)
{
	return (i.addsum < j.addsum);
}
int main()
{
	int myarray[6] = {1,0,-1,0,-2,2};
	vector<int> num(myarray,myarray + 6);
	int target = 0;
	


	vector<sum> sumlist;
	for(int i = 0 ; i < num.size() - 1 ; i++)
	{
		for (int j = i + 1; j < num.size() ; j++)
		{
			sumlist.push_back(sum(num[i] + num[j] , i , j));
		}
	}
	sort(sumlist.begin(),sumlist.end(),cmp);

	for(vector<sum>::iterator iti = sumlist.begin();iti != sumlist.end() - 1; iti ++)
	{
		for(vector<sum>::iterator itj = iti + 1;itj != sumlist.end() - 1; itj ++)
		{
			if (iti->addsum + itj->addsum == target)
			{
				set<int> indexs;
				indexs.insert(iti->aindex);
				indexs.insert(iti->bindex);
				indexs.insert(itj->aindex);
				indexs.insert(itj->bindex);
				if (indexs.size() == 4)
				{
					vector<int> oneres;
					for(set<int>::iterator it = indexs.begin(); it!= indexs.end();it++)
					{
						oneres.push_back(num[*it]);
					}
					sort(oneres.begin(),oneres.end());
					result.insert(oneres);
				}
			}
		}
	}
	return 0;
}