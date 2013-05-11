//很无耻的继续用之前的算法，调整最后的res，感觉题意应该是让编码的人按照他的要求顺序来遍历而不是直接改结果

class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
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
		for(int i = 0;i< res.size();i++)
		{
			if(i%2 == 1)
				reverse(res[i].begin(),res[i].end());
		}
		return res;
	}
};