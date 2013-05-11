//�ݹ鷽���޷�ͨ��large judge ����Ѳ�����Ϊ��������������ܻ�ͨ��ֻ��Ҫ����������
//postorder���һ��Ϊ���ڵ�
//�ø��ڵ��ֵ��inorder���а�inorder���л�Ϊ������������������
//������������������С��postorder����Ϊ��������
//�ݹ�����
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.size() == 0 && postorder.size() == 0)
			return NULL;
		int val = postorder[postorder.size() - 1]; 
		TreeNode *root = new TreeNode(val);
		auto rootindex = find(inorder.begin(),inorder.end(),val);
		int lsize = rootindex - inorder.begin();
		if (lsize != 0)
		{
			vector<int> linorder(inorder.begin(),rootindex);
			vector<int> lpostorder(postorder.begin(),postorder.begin() + lsize);
			root->left = buildTree(linorder,lpostorder);
		}
		int rsize = inorder.end() - rootindex - 1;
		if (rsize != 0)
		{
			vector<int> rinorder(rootindex + 1,inorder.end());
			vector<int> rpostorder(postorder.begin()+ lsize,postorder.end() - 1);
			root->right = buildTree(rinorder,rpostorder);
		}
		return root;
    }
};

int main()
{
	vector<int> inorder;
	inorder.push_back(-1);
	Solution sol;
	sol.buildTree(inorder,inorder);return 0;
};