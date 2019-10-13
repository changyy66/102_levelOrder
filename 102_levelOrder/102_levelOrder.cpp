// 102_levelOrder.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

3
/ \
9  20
/  \
15   7
返回其层次遍历结果：

[
[3],
[9,20],
[15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <queue>
using namespace std;


/**
* Definition for a binary tree node.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	void order(queue<TreeNode*>& q1, vector<vector<int>>& res)
	{
		if (q1.size() == 0)return;
		vector<int> v;
		TreeNode* tmp;
		int n = q1.size();
		while (n--)
		{
			tmp = q1.front();
			q1.pop();
			if (tmp->left)q1.push(tmp->left);
			if (tmp->right)q1.push(tmp->right);
			v.push_back(tmp->val);
		}
		res.push_back(v);
		order(q1, res);
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root)return{};
		queue<TreeNode*> q1;
		vector<vector<int>> res;
		q1.push(root);
		order(q1, res);
		return res;

	}
};

int main()
{
    return 0;
}

