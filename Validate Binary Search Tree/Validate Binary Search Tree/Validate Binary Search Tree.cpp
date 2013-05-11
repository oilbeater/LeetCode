/**

Ҫ�����ڶ���������������������Ϊ�������У�����ֻҪ���ֺ�һ������ǰһ����С�Ϳ����жϲ�����ȷ�Ķ���������
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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        TreeNode *p = root,*q = root;
        while(q->left != NULL)
            q = q->left;
        int start = q->val - 1 ;
        stack<TreeNode *> NodeStack;
        while(p || !NodeStack.empty())
        {
            while(p)
            {
                NodeStack.push(p);
                p = p->left;
            }
            p = NodeStack.top();
            NodeStack.pop();
            if(start >= p->val)
                return false;
            else
                start = p->val;
            p = p->right;
        }
        return true;
    }
};