/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int height(TreeNode *now)
 {
     
    if(now == NULL)
        return 0;
     return 1+((height(now->left) > height(now->right))?height(now->left):height(now->right));
 }
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        if(abs(height(root->left) - height(root->right)) > 1 )
            return false;
        return (isBalanced(root->left) && isBalanced(root->right));
        
    }
};