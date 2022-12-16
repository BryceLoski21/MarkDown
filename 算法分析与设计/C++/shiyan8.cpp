#include <stdio.h>
#include <limits.h>
#include <queue>
#include <vector>
#include <stdlib.h>
using namespace std;

typedef int ElemType;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(), left(), right() {}//无参构造
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}//有参构造
};

//层序创建二叉树
void createBinaryTree(TreeNode* &root, int input[], int n) {
	if (n == 0) return;
	vector<TreeNode*> pNodes;
	for (int i = 0; i < n; i++) {
		TreeNode* pnode = new TreeNode(input[i]);
		pNodes.push_back(pnode);
	}
	for (int i = 0; i < pNodes.size(); i++) {
		TreeNode* tmp = pNodes[i];
		if (tmp->val == INT_MAX) continue;
		int left_i = 2 * i + 1;
		int right_i = 2 * i + 2;
		if (left_i < pNodes.size() && pNodes[left_i]->val != INT_MAX){
			tmp->left = pNodes[left_i];
		}
		if (right_i < pNodes.size() && pNodes[right_i]->val != INT_MAX){
			tmp->right = pNodes[right_i];
		}
	}
	root = pNodes[0];
}

void preOrder(TreeNode* root){
	if (root){
		printf("%d ", root->val);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int height(TreeNode* root){
	//TODO：实现层序遍历计算树的高度的函数
	int h = -1;
	if (root == NULL) return h;
	/*队列q中的元素类型为TreeNode*类型*/
	/*可用的函数：q.size()返回元素个数，q.front()获得队首元素，q.pop()出队，q.push(某TreeNode*类型元素)入队*/
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()){
		int level_size = q.size();
		for(int i = 0; i < level_size; i++){
			TreeNode* cur = q.front();
			q.pop();
			if(cur->left) q.push(cur->left);
			if(cur->right) q.push(cur->right);
		}
		h++;
	}
	return h;
}

int main(){
	//树的带空结点的层序遍历结果
	int input[] = { 1, 2, 3, 4, 5, INT_MAX, 6, INT_MAX, INT_MAX, 7, INT_MAX, INT_MAX, INT_MAX, 8, 9 };
	TreeNode* root;
	createBinaryTree(root, input, sizeof(input) / sizeof(input[0]));
	printf("树的高度为: %d\n", height(root));
	getchar();
	getchar();
	return 0;
}