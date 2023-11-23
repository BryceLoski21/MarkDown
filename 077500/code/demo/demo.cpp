#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h> // ����C6011

typedef int ElemType;
typedef int Status;

#define ERROR -2
#define OK 1

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

int abc(LinkList ha, LinkList hb) {
	LinkList pa, pb;
	pa = ha->next;
	pb = hb->next;
	int count = 1;
	while (pa && pb && pa->data == pb->data) {
		pa = pa->next;
		pb = pb->next;
		printf("ѭ����%d��\n", count);
		count += 1;
	}
	if (pa == NULL && pb == NULL)
		return 1;
	else return 0;
}

void main() {
	LinkList a, b;
	printf("����a��\n");
	CreateList_L(a, 6); // 2 4 5 7 9 12
	printf("����b��\n");
	CreateList_L(b, 5); // 2 4 5 7 9
	printf("\n%d ", abc(a, b));
	/*int aa[] = { 2,4,5,7,9,12 };
	int bb[] = { 2,4,5,7,9 };
	ElemType e;
	for (int i = 0; i < 6; i++) {
		e = aa[i];
		LinkList_L(a, i+1, e);
	}
	for (int i = 0; i < 5; i++) {
		e = bb[i];
		LinkList_L(b, i+1, e);
	}
	printf("\n%d ", abc(a, b));*/
}