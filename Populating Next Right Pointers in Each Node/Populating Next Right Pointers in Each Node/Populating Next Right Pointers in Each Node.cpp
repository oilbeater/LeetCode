#include <iostream>
#include <vector>
using namespace std;
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root ==NULL)
			return;
		int start = 0;
		int end = 1;
		vector<TreeLinkNode *> nodeq;
		nodeq.push_back(root);
		while(start < end)
		{
			int i = start;
			int addCount = 0;
			for ( ;i < nodeq.size() - 1; i++)
			{
				nodeq[i]->next = nodeq[i+1];
			}
			nodeq[i]->next = NULL;
			for (int  i = start; i < end ; i++)
			{
				if (nodeq[i]->left)
				{
					nodeq.push_back(nodeq[i]->left);
					addCount++;
				}
				if (nodeq[i]->right)
				{
					nodeq.push_back(nodeq[i]->right);
					addCount++;
				}
			}
			start = end;
			end += addCount;
		}        
    }
};