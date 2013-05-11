/*归纳思想，已知n-1个节点的排列个数，n个节点的排列个数等于每个节点当根节点，左右两子树个数的乘积再求和
*/
class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        res.push_back(1);
        res.push_back(1);
        for(int i = 2;i <= n;i++)
        {
            int temp = 0;
            for(int j = 1 ; j <= i ;j++ )
                temp += res[j - 1] * res[i-j];
            res.push_back(temp);
        }
        return res[n];
    }
};