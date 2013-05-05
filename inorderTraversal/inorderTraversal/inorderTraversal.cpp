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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<TreeNode*> NodeStack;
        vector<int> res;
        TreeNode* now =root;
        if(!root)
            return res;
        
        while(!NodeStack.empty()||now)
        {
            while(now)
            {
                NodeStack.push(now);
                now = now->left;
            }
            if(!NodeStack.empty())
            {
                now = NodeStack.top();
                NodeStack.pop();
                res.push_back(now->val);
                now = now->right;

            }
        }
        return res;
        
    }
};