#include <stack>
using namespace std;
struct TreeNode {
  int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
	int sumNumbers(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (!root)
		{
			return 0;
		}
		stack<TreeNode *> par;
		int sum = 0;
		int rsum = 0;
		TreeNode *pre = NULL,*p = root;
		while (!par.empty()||p)
		{
			while (p)
			{
				par.push(p);
				sum = sum * 10 + p->val; 
				p = p->left;
			}
			p = par.top();
			if(p->right == NULL || pre == p->right)
			{
				if (p->left == NULL && p->right == NULL)
				{
					rsum += sum;
				}
				pre = p;
				par.pop();
				sum /= 10;
				p = NULL;
			}
			else
			{
				p = p->right;
			}
		}
		return rsum;
	}
};