class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int start = 0, end = num.size() - 1;
		if (start > end)
			return NULL;
		int val = num[(start + end)/2];
		TreeNode *root = new TreeNode(val);

		if((start + end)/2 - 1 >= start)
		{
			vector<int> left(num.begin() + start , num.begin() + (start + end)/2);
			root->left = sortedArrayToBST(left);
		}
		if((start + end)/2 + 1 <= end)
		{
			vector<int> right(num.begin() + (start + end)/2 + 1 , num.begin() + end + 1);
			root->right = sortedArrayToBST(right);
		}
		return root;
	}
	TreeNode *sortedListToBST(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> temp;
		while (head != NULL)
		{
			temp.push_back(head->val);
			head = head->next;
		}
		return sortedArrayToBST(temp);
	}
};