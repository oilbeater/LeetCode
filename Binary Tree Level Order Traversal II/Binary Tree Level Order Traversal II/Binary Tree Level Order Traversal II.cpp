//直接利用Binary Tree Level Order Traversal I 的算法，把最后返回值反转一下即可
//出现问题：
//	错误将reverse(res.begin(),res.end())返回
class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int>> res;
		if(root == NULL)
			return res;
		vector<TreeNode *> NodeQue;
		NodeQue.push_back(root);
		int start = 0,end = 1;
		vector<int> first;
		first.push_back(root->val);
		res.push_back(first);
		while (start < end)
		{
			vector<int> temp;
			for (int i = start; i < end ; i++)
			{
				if(NodeQue[i]->left)
				{
					NodeQue.push_back(NodeQue[i]->left);
					temp.push_back(NodeQue[i]->left->val);
				}
				if(NodeQue[i]->right)
				{
					NodeQue.push_back(NodeQue[i]->right);
					temp.push_back(NodeQue[i]->right->val);
				}
			}
			if(!temp.empty())
				res.push_back(temp);
			start = end;
			end = NodeQue.size();
		}
		reverse(res.begin(),res.end());
		return res;
	}
};