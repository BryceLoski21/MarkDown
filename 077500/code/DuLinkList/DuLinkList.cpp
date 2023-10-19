#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int Status;
typedef int ElemType;

#define OK 1
#define OVERFLOW -2

typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode, *DuLinkList;

// 链表哨兵结点的创建
Status ListCreate(DuLinkList &L)
{
	L = (DuLinkList)malloc(sizeof(DuLNode));
	assert(L);
	L->next = L->prior = L;
	return OK;
}

DuLinkList GetElem_DuL(DuLinkList& L, int i) {
	// 获取双向循环链表L中的第i个元素
	DuLinkList p = L;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) exit(OVERFLOW); // 第i个元素不存在
	return p;
}

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
	// 在带头结点的双向循环链表L中第i个位置之前插入元素e
	// 1 <= i <= length+1
	DuLinkList p;
	if (!(p = GetElem_DuL(L, i))) exit(OVERFLOW);
	DuLinkList s = (DuLinkList)malloc(sizeof(DuLNode));
	if (!s) exit(OVERFLOW);
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

int main() {
	DuLinkList L;
	ListCreate(L);
	for (int i = 1; i < 7; i++) {
		ListInsert_DuL(L, i, i);
	}
	DuLinkList p = L->next;
	for (int i = 1; i < 7; i++) {
		printf("%d ", p->data);
		p = p->next;
	}
	return 0;
}