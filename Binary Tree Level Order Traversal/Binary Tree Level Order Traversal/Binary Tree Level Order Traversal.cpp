//简单层次遍历，利用start和end记录当前层开始和结束坐标
//出现问题：
//	最后一层叶子节点没有孩子，还会建立一个空的vector加入最后结果
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
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
		return res;
    }
};