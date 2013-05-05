#include <stack>
#include <queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 class Solution {
 public:
	 void flatten(TreeNode *root) {
		 // Start typing your C/C++ solution below
		 // DO NOT write int main() function
		 if(root == NULL)
			 return;
		 TreeNode *p = root;
		 stack<TreeNode *> NodeStack;
		 queue<TreeNode *> NodeQue;
		 do 
		 {
			 if (!p)
			 {
				 p = NodeStack.top();
				 NodeStack.pop();
			 }
			 NodeQue.push(p);
			 if (p->right)
			 {
				 NodeStack.push(p->right);
			 }
			 p = p->left;
		 } while (!NodeStack.empty()||p);
		 p = root;
		 p->left = NULL;
		 NodeQue.pop();
		 while (!NodeQue.empty())
		 {
			 p->right = new TreeNode(NodeQue.front()->val);
			 NodeQue.pop();
			 p = p->right;
		 }
	 }
 };