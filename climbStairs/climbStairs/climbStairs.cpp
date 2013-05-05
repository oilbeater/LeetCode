
class Solution {
public:
	int stair[1000];
	int climbStairs(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 1)
		{stair[n]=1;
		return 1;}
		if(n == 2)
		{stair[n]=2;
		return 2;}
		if(n == 0)
		{stair[n]=0;
		return 0;}

		for (int i = 3;i < n + 1; i++)
		{
			stair[i] = stair[i-1]+stair[i-2];
		}
		return stair[n];
	}
};