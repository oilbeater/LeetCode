//递归方法无法通过large judge 如果把参数改为两个数组坐标可能会通过只是要传六个参数
//postorder最后一个为根节点
//用根节点的值和inorder序列把inorder序列划为左子树右子树两部分
//根据左子树右子树大小把postorder划分为两个部分
//递归向下
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.size() == 0 && postorder.size() == 0)
			return NULL;
		int val = postorder[postorder.size() - 1]; 
		TreeNode *root = new TreeNode(val);
		auto rootindex = find(inorder.begin(),inorder.end(),val);
		int lsize = rootindex - inorder.begin();
		if (lsize != 0)
		{
			vector<int> linorder(inorder.begin(),rootindex);
			vector<int> lpostorder(postorder.begin(),postorder.begin() + lsize);
			root->left = buildTree(linorder,lpostorder);
		}
		int rsize = inorder.end() - rootindex - 1;
		if (rsize != 0)
		{
			vector<int> rinorder(rootindex + 1,inorder.end());
			vector<int> rpostorder(postorder.begin()+ lsize,postorder.end() - 1);
			root->right = buildTree(rinorder,rpostorder);
		}
		return root;
    }
};

int main()
{
	vector<int> inorder;
	inorder.push_back(-1);
	Solution sol;
	sol.buildTree(inorder,inorder);return 0;
};