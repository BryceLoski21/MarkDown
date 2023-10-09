#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h> // 消除C6011

typedef int ElemType;
typedef int Status;

#define ERROR -2;
#define OK 1;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

// 在带头结点的单链线性表L中第i个位置之前插入元素e
Status LinkList_L(LinkList& L, int i, ElemType e) {
	LinkList p = L;
	int j = 0;
	// 寻找第i-1个结点
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR; // i小于1或者大于表长加一
	LinkList s = (LinkList)malloc(sizeof(LNode)); // 生成新结点
	assert(s);
	s->data = e;
	s->next = p->next; // 插入L中
	p->next = s;
	return OK;
}

// 逆位序输入n个元素的值,建立带头结点的单链表线性表L
void CreateList_L(LinkList& L, int n) {
	L = (LinkList)malloc(sizeof(LNode));
	assert(L);
	L->next = NULL; // 建立带头结点的单链表
	for (int i = n; i > 0; --i) {
		LinkList p = (LinkList)malloc(sizeof(LNode)); // 生成新结点
		assert(p);
		scanf_s("%d", &p->data); // 输入元素值
		p->next = L->next;
		L->next = p; // 插入到表头
	}
}

void main() {
	LinkList L;
	CreateList_L(L, 5);

	ElemType e = 16;
	LinkList_L(L, 1, e);
	printf("check: %d", L->next->data);
}