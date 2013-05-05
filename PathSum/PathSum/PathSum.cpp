#include <stack>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(root == NULL)
			return false;
		TreeNode *p = root;
		TreeNode *pre = NULL;
		int now = 0;
		stack<TreeNode *> NodeStack;
		while(p || !NodeStack.empty())
		{
			while(p)
			{
				NodeStack.push(p);
				now += p->val;
				p = p->left;
			}
			p = NodeStack.top();
			if (pre == p->right || p->right == NULL)
			{
				pre = p;
				if (!p->left && !p->right)
				{
					if(sum == now)
						return true;
				}
				now -= p->val;
				NodeStack.pop();
				p = NULL;
			}
			else
				p = p->right;
		}
		return false;
	}
};