class Solution {
public:
	int maxProfit(vector<int> &prices) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(prices.size() == 0)
			return 0;
		int min = prices[0];
		int profit = 0;
		for(int i = 1; i< prices.size(); i++)
		{
			if(prices[i] < min)
				min =prices[i];
			if(prices[i] - min > profit)
				profit = prices[i] - min;
		}
		return profit;
	}
};