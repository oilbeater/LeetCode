class Solution {
public:
	int maxProfit(vector<int> &prices) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int profit = 0;
		if(prices.size() == 0) return profit;
		int first = prices[0];
		for(int i = 0 ;i < prices.size();i++)
		{
			if(prices[i] < first)
				first = prices[i];
			if(prices[i] > first)
			{
				profit += prices[i] - first;
				first = prices[i];
			}
		}
		return profit;
	}
};