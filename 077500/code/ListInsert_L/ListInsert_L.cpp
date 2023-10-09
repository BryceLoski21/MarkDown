#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h> // ����C6011

typedef int ElemType;
typedef int Status;

#define ERROR -2;
#define OK 1;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

// �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
Status LinkList_L(LinkList& L, int i, ElemType e) {
	LinkList p = L;
	int j = 0;
	// Ѱ�ҵ�i-1�����
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR; // iС��1���ߴ��ڱ���һ
	LinkList s = (LinkList)malloc(sizeof(LNode)); // �����½��
	assert(s);
	s->data = e;
	s->next = p->next; // ����L��
	p->next = s;
	return OK;
}

// ��λ������n��Ԫ�ص�ֵ,������ͷ���ĵ��������Ա�L
void CreateList_L(LinkList& L, int n) {
	L = (LinkList)malloc(sizeof(LNode));
	assert(L);
	L->next = NULL; // ������ͷ���ĵ�����
	for (int i = n; i > 0; --i) {
		LinkList p = (LinkList)malloc(sizeof(LNode)); // �����½��
		assert(p);
		scanf_s("%d", &p->data); // ����Ԫ��ֵ
		p->next = L->next;
		L->next = p; // ���뵽��ͷ
	}
}

void main() {
	LinkList L;
	CreateList_L(L, 5);

	ElemType e = 16;
	LinkList_L(L, 1, e);
	printf("check: %d", L->next->data);
}