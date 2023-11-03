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
#define LT(a, b) ((a) < (b)) // С��
#define EQ(a, b) ((a) == (b)) // ����

struct ElemType {
	int data;
	KeyType key;
};

typedef struct BiTNode{
	ElemType elem;
	struct BiTNode* lchild, * rchild; // ���Һ���ָ��
}BiTNode, *BiTree;

Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree& p) {
	// �����������ؼ�������
	if (!T) {
		p = f;
		return FALSE; // ���Ҳ��ɹ�
	}
	else if (EQ(key, T->elem.key)) {
		p = T;
		return TRUE; // ���ҳɹ�
	}
	else if (LT(key, T->elem.key)) {
		return SearchBST(T->lchild, key, T, p); // ���������м�������
	}
	else return SearchBST(T->lchild, key, T, p); // ���������м�������
}

Status InsertBST(BiTree& T, ElemType e) {
	// �����������Ĳ���
	/*BiTree p = (BiTree)malloc(sizeof(BiTNode));
	assert(p);*/
	BiTree p = T;
	if (!SearchBST(T, e.key, NULL, p)) { // ���Ҳ��ɹ�
		BiTree s = (BiTree)malloc(sizeof(BiTNode));
		assert(s);
		s->elem = e;
		s->lchild = s->rchild = NULL;
		if (!p) T = s; // ������*sΪ�µĸ����
		else if (LT(e.key, p->elem.key)) p->lchild = s; // ������*sΪ����
		else p->rchild = s; // ������*sΪ�Һ���
		return TRUE;
	}
	else return FALSE; // �������йؼ�����ͬ�Ľ��
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