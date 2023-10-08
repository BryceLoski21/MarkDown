#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

int count = 0;

// 二叉树的二叉链表存储表示
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild; // 左右孩子指针
}BiTNode, *BiTree;

// 构造二叉链表表示的二叉树T
Status CreateBiTree(BiTree &T) {
	int data;
	scanf_s("%d", &data);

	if (data == -1) {
		T = NULL; // 结束递归时让当前结点的指针指向NULL
	}
	else {
		T = (BiTree)malloc(sizeof(BiTree)); // 分配内存
		if (!T) { // T == NULL, 内存分配失败,结束递归
			printf("内存分配失败\n");
			exit(OVERFLOW);
		}
		T->data = data;

		printf("请输入%d的左子树: ", data);
		CreateBiTree(T->lchild); // 遍历左子树

		printf("请输入%d的右子树: ", data);
		CreateBiTree(T->rchild); // 遍历右子树
	}
	return OK;
}

//	先序遍历二叉树
void PreOrderTraverse(BiTree T)		
{
	if (T == NULL)
	{
		return;
	}
	printf("%d ", T->data);
	PreOrderTraverse(T->lchild); //	遍历左子树
	PreOrderTraverse(T->rchild); //	遍历右子树
}

// 返回二叉树中叶子结点个数
int GetCountOfLeaf(BiTree &r) {
	// int count = 0; 
	// bug：每次递归调用count都会初始化为0
	// debug: 把count定义成全局变量
	if (r != NULL) { // 非空
		if (r->lchild == NULL && r->rchild == NULL) {
			count++;
		}
		GetCountOfLeaf(r->lchild);
		GetCountOfLeaf(r->rchild);
	}
	return count;
}

int main() {
	BiTree T;

	printf("请输入第一个结点的数据: \n");
	CreateBiTree(T);

	PreOrderTraverse(T);

	printf("叶子结点个数: %d", GetCountOfLeaf(T));

	return 0;
}