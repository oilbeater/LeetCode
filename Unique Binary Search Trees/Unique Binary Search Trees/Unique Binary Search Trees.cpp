/*����˼�룬��֪n-1���ڵ�����и�����n���ڵ�����и�������ÿ���ڵ㵱���ڵ㣬���������������ĳ˻������
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