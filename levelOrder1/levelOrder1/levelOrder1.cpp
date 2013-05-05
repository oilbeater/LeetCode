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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode*> NodeQueue;
        NodeQueue.push(root);
        int count = 1;
        vector<vector<int> > res;
        if(!root) return res;
        while(!NodeQueue.empty())
        {
            int tempcount = 0;
            vector<int> row;
            for(int i = 0;i < count; i++)
            {
                TreeNode* now = NodeQueue.front();
                NodeQueue.pop();
                row.push_back(now->val);
                if(now->left)
                {
                    NodeQueue.push(now->left);
                    tempcount++;
                }
                if(now->right)
                {
                    NodeQueue.push(now->right);
                    tempcount++;
                }
            }
            count = tempcount;
            res.push_back(row);
        }
        return res;
    }
};