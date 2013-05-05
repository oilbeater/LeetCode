#include <stack>
#include <queue>
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
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int>> res;
		if(root == NULL)
			return res;
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
					{
						vector<int> temp;
						vector<TreeNode *> tempnode;
						while(!NodeStack.empty())
						{
							TreeNode *tt = NodeStack.top();
							temp.push_back(tt->val);
							tempnode.push_back(tt);
							NodeStack.pop();
						}
						reverse(temp.begin(),temp.end());
						res.push_back(temp);
						for (auto it = tempnode.begin(); it != tempnode.end(); it++)
						{
							NodeStack.push(*it);
						}
					}
				}
				now -= p->val;
				NodeStack.pop();
				p = NULL;
			}
			else
				p = p->right;
		}
		return res;
	}
};