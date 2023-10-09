#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;

#define OK 1
#define OVERFLOW -2
#define max(a, b) ((a) > (b) ? (a) : (b))

// 二叉链表存储的二叉树
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

// 构造二叉链表表示的二叉树T
Status CreateBiTree(BiTree& T) {
	// 按先序次序输入二叉树中的结点的值
	
	int data;
	scanf_s("%d", &data);

	if (data == -1) {
		T = NULL;
	}
	else {
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data = data;

		printf("请输入%d的左子树:\n", data);
		CreateBiTree(T->lchild); // 开始遍历左子树
		printf("请输入%d的右子树:\n", data);
		CreateBiTree(T->rchild); // 开始遍历右子树
	}
	return OK;
}

// 求二叉树深度
int depth(BiTree& root) {
	if (root == NULL) {
		return 0;
	}
	else
	{
		int leftHight = depth(root->lchild);
		int rightHight = depth(root->rchild);
		return 1 + max(leftHight, rightHight);
	}

}

void main() {
	BiTree T;
	printf("请输入第一个结点: \n");
	CreateBiTree(T);

	printf("二叉树深度: %d", depth(T));
}