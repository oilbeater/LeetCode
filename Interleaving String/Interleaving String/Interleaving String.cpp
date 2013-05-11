/*
���s3��һ���ַ���s1��s2��һ���ַ���ȣ��Ƚ�s1��s2����Ĵ���s2��s1��s3���洮�ȽϽ��
large judgement time limit exceed
�������dp�ķ���Ӧ��û����
*/
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		if(s1.size()+s2.size() != s3.size())
			return false;
		if(!(s1.size() || s2.size() || s3.size()))
			return true;
		bool res1,res2;
		if(s1.size() == 0||s1.size() > 0 && s1[0] != s3[0])
			res1 = false;
		else
			res1 = isInterleave(s1.substr(1), s2, s3.substr(1));
		if(s2.size() == 0||s2.size() > 0 && s2[0] != s3[0])
			res2 = false;
		else
			res2 = isInterleave(s1, s2.substr(1), s3.substr(1));
		return res1||res2;
	}
};