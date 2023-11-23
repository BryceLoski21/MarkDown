#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h> // 消除C6011

typedef int ElemType;
typedef int Status;

#define ERROR -2
#define OK 1

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

int abc(LinkList ha, LinkList hb) {
	LinkList pa, pb;
	pa = ha->next;
	pb = hb->next;
	int count = 1;
	while (pa && pb && pa->data == pb->data) {
		pa = pa->next;
		pb = pb->next;
		printf("循环第%d次\n", count);
		count += 1;
	}
	if (pa == NULL && pb == NULL)
		return 1;
	else return 0;
}

void main() {
	LinkList a, b;
	printf("输入a：\n");
	CreateList_L(a, 6); // 2 4 5 7 9 12
	printf("输入b：\n");
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