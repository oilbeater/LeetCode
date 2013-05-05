class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		sort(candidates.begin(),candidates.end());
		vector<vector<int> > res;
		vector<int> one;
		findsum(candidates,0,target,res,one);
		return res;

	}
	void findsum(vector<int> &input,int start,int target,vector<vector<int> > &res,vector<int> one)
	{
		if (target == 0)
		{
			res.push_back(one);
			return;
		}
		else if(target > 0 && start < input.size())
		{
			for (int i = 0 ; i <= target/input[start] ; i++)
			{
				if (i > 0)
				{
					one.push_back(input[start]);
				}
				findsum(input,start+1,target - i*input[start],res,one);
			}
		}
	}
};

//class Solution {
//public:
//	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
//		// Start typing your C/C++ solution below
//		// DO NOT write int main() function
//		sort(num.begin(),num.end());
//		set<vector<int> > res;
//		vector<int> one;
//		findsum(num,0,target,res,one);
//		vector<vector<int> > resu(res.begin(),res.end());
//
//		return resu;       
//	}
//	void findsum(vector<int> &input,int start,int target,set<vector<int> > &res,vector<int> one)
//	{
//		if (target == 0)
//		{
//			res.insert(one);
//			return;
//		}
//		else if(target > 0 && start < input.size())
//		{
//			for (int i = 0 ; i <= 1 ; i++)
//			{
//				if (i > 0)
//				{
//					one.push_back(input[start]);
//				}
//				findsum(input,start+1,target - i*input[start],res,one);
//			}
//		}
//	}
//};