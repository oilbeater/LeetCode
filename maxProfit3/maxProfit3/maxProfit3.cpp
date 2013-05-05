#include <vector>
using namespace std;

int main()
{
	vector<int> prices;
	prices.push_back(1);
	if(prices.size() == 0)
		return 0;
	vector<int> firstprofit;
	firstprofit.push_back(0);
	firstprofit.push_back(0);
	vector<int> secondprofit;
	secondprofit.push_back(0);
	secondprofit.push_back(0);
	int min = prices[0];
	int profit = 0;
	for(int i = 1; i< prices.size(); i++)
	{
		if(prices[i] < min)
			min =prices[i];
		if(prices[i] - min > profit)
			profit = prices[i] - min;
		firstprofit.push_back(profit);
	}
	reverse(prices.begin(),prices.end());
	min = prices[0];
	profit = 0;
	for(int i = 1; i< prices.size(); i++)
	{
		if(prices[i] > min)
			min =prices[i];
		if(prices[i] - min < profit)
			profit = prices[i] - min;
		secondprofit.push_back(-profit);
	}
	reverse(secondprofit.begin(),secondprofit.end());
	int maxprofit = 0;
	for(int i = 0;i<firstprofit.size();i++)
	{
		if(firstprofit[i] + secondprofit[i] > maxprofit)
			maxprofit = firstprofit[i] + secondprofit[i];
	}
	return 0;
}