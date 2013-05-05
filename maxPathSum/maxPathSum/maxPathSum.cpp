/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int findmax(TreeNode* now,int &max,int &maxnode)
 {
     if(now == NULL)
        return 0;
    else
        {
            if(now->val > maxnode)
                maxnode = now->val;
            int leftmax = findmax(now->left,max,maxnode);
            int rightmax =  findmax(now->right,max,maxnode);
            int nowmax = leftmax + rightmax + now->val;
            if(max < nowmax)
                max = nowmax;
            if(leftmax >rightmax)
                rightmax = leftmax;
            return (rightmax + now->val > 0)?(rightmax + now->val):0;
        }
 }
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
        int maxnode = root->val;
        findmax(root,max,maxnode);
        return max?max:maxnode;
    }
};