#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

//typedef int ElemType;
typedef int KeyType;
typedef int Status;

#define OK 1
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define MAXSIZE 100
#define LT(a, b) ((a) < (b)) // 小于
#define EQ(a, b) ((a) == (b)) // 等于

struct ElemType {
	int data;
	KeyType key;
};

typedef struct BiTNode{
	ElemType elem;
	struct BiTNode* lchild, * rchild; // 左右孩子指针
}BiTNode, *BiTree;

Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree& p) {
	// 二叉排序树关键字搜索
	if (!T) {
		p = f;
		return FALSE; // 查找不成功
	}
	else if (EQ(key, T->elem.key)) {
		p = T;
		return TRUE; // 查找成功
	}
	else if (LT(key, T->elem.key)) {
		return SearchBST(T->lchild, key, T, p); // 在左子树中继续查找
	}
	else return SearchBST(T->lchild, key, T, p); // 在右子树中继续查找
}

Status InsertBST(BiTree& T, ElemType e) {
	// 二叉排序树的插入
	/*BiTree p = (BiTree)malloc(sizeof(BiTNode));
	assert(p);*/
	BiTree p = T;
	if (!SearchBST(T, e.key, NULL, p)) { // 查找不成功
		BiTree s = (BiTree)malloc(sizeof(BiTNode));
		assert(s);
		s->elem = e;
		s->lchild = s->rchild = NULL;
		if (!p) T = s; // 被插结点*s为新的根结点
		else if (LT(e.key, p->elem.key)) p->lchild = s; // 被插结点*s为左孩子
		else p->rchild = s; // 被插结点*s为右孩子
		return TRUE;
	}
	else return FALSE; // 树中已有关键字相同的结点
}

void main() {
	BiTree T = (BiTree)malloc(sizeof(BiTNode));
	assert(T);
	T = NULL;
	//T->lchild = NULL;
	//T->rchild = NULL;
	ElemType e;
	e.data = 23;
	e.key = 23;
	InsertBST(T, e);
	printf("%d", T->elem.data);
}