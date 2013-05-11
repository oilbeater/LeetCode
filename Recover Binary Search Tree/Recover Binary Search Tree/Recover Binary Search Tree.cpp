/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
                if(root == NULL)
            return ;
        TreeNode *p = root,*q = root;
    	TreeNode *pre = NULL,*first = NULL,*second = NULL;
        while(q->left != NULL)
            q = q->left;
        stack<TreeNode *> NodeStack;
        while(p || !NodeStack.empty())
        {
            while(p)
            {
                NodeStack.push(p);
                p = p->left;
            }
            p = NodeStack.top();
			if (pre == NULL || pre->val < p->val)
			{
				pre = p;
			}
			else
			{
				if(first == NULL)
				{
					first = pre;
					second = p;
				}
				else
					second = p;
				pre = p;
			}
            NodeStack.pop();
            
            p = p->right;
        }
		int val = first->val;
		first->val = second->val;
		second->val = val;
        return ;
    }
};