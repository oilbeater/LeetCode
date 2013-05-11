//和Construct Binary Tree from Inorder and Postorder Traversal类似
//不能通过large judge memory limit exceeded
#include<vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(preorder.size() == 0 && inorder.size() == 0)
			return NULL;
		int val = preorder[0];
		TreeNode *root = new TreeNode(val);
		int rootindex = 0;
		while (inorder[rootindex] != val)
			rootindex++;
		if (rootindex > 0)
		{
			int lsize = rootindex ;
			vector<int> linorder(inorder.begin(),inorder.begin() + lsize);
			vector<int> lpreorder(preorder.begin() + 1 ,preorder.begin() + 1 + lsize);
			root->left = buildTree(lpreorder,linorder);
		}
		if (rootindex < inorder.size() - 1)
		{
			int rsize = inorder.size() - rootindex - 1;
			vector<int> rinorder(inorder.begin() + rootindex + 1,inorder.end());
			vector<int> rpreorder(preorder.begin() + rootindex + 1,preorder.end());
			root->right = buildTree(rpreorder,rinorder);
		}
		return root;
    }
};