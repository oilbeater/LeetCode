//继续层次遍历，每一层加一
class Solution {
public:
	int maxDepth(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int layer = 0;
		if(root == NULL)
			return layer;
		vector<TreeNode *> NodeQue;
		NodeQue.push_back(root);
		layer++;
		int start = 0,end = 1;
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
				layer++;
			start = end;
			end = NodeQue.size();
		}
		return layer;
	}
};