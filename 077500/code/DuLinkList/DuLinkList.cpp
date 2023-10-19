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

// �����ڱ����Ĵ���
Status ListCreate(DuLinkList &L)
{
	L = (DuLinkList)malloc(sizeof(DuLNode));
	assert(L);
	L->next = L->prior = L;
	return OK;
}

DuLinkList GetElem_DuL(DuLinkList& L, int i) {
	// ��ȡ˫��ѭ������L�еĵ�i��Ԫ��
	DuLinkList p = L;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) exit(OVERFLOW); // ��i��Ԫ�ز�����
	return p;
}

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
	// �ڴ�ͷ����˫��ѭ������L�е�i��λ��֮ǰ����Ԫ��e
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