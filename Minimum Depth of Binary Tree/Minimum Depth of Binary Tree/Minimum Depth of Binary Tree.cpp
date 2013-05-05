#include <vector>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (root == NULL)
			return 0;
		vector<TreeNode *> NodeQue;
		NodeQue.push_back(root);
		int start = 0,end = 1;
		int layer = 1;
		while (start < end)
		{
			for (int i = start;i < end; i++)
			{
				TreeNode *p = NodeQue[i];
				if(!p->left && !p->right)
					return layer;
				if (p->left)
					NodeQue.push_back(p->left);
				if(p->right)
					NodeQue.push_back(p->right);
			}
			start = end;
			if (end < NodeQue.size())
			{
				end = NodeQue.size();
				layer++;
			}
		}
		return layer;
    }
};