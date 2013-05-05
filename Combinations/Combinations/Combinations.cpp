#include <vector>
using namespace std;
vector<vector<int> > calcn(int k, int n)
{
	vector<vector<int> > fres;
	if (k > 1)
	{
		vector<vector<int> > res = calcn(k-1,n);
		for (int i = 0;i < res.size();i++)
		{
			for(int j = res[i][res[i].size() - 1] + 1;j < n + 1;j++)
			{
				vector<int> tmp = res[i];
				tmp.push_back(j);
				fres.push_back(tmp);
			}
		}
		return fres;
	}
	if (k == 1)
	{	
		for(int i = 1 ;i < n + 1;i++)
		{
			vector<int> tmp;
			tmp.push_back(i);
			fres.push_back(tmp);
		}

		return fres;
	}
}
int main()
{
	vector<vector<int> >res;
	res = calcn(3,4);

	return 0;
}