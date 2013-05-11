/**
 * 利用same tree 在比较时将左子树和右子树进行比较
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL && q != NULL || p != NULL && q == NULL)
            return false;
        if(p->val != q ->val)
            return false;
        else
            return isSameTree(p->left,q->right) && isSameTree(p->right , q->left);       
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root != NULL)
            return isSameTree(root->left,root->right);
        return true;
    }
};