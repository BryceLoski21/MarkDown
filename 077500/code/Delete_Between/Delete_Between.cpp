#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h> // 取消C6011

typedef int ElemType;
typedef int Status;

#define OK 1
#define OVERFLOW -2

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

Status CreateList_L(LinkList& L, int n) {
	L = (LinkList)malloc(sizeof(LNode));
	assert(L);
	L->next = NULL; // 建立带头结点的单链表
	for (int i = n; i > 0; --i) {
		LinkList p = (LinkList)malloc(sizeof(LNode));
		assert(p);
		scanf_s("%d", & p->data);
		p->next = L->next; // p->next = L->next = NULL
		L->next = p; // 插入到表头
	}
	return OK;
}

void Delete_Between(LinkList& L, ElemType min, ElemType max) {
	if (!L) exit(OVERFLOW);
	LinkList p, q;
	p = L;   //p指向前驱结点，一开始指向头结点
	//当结点存在(p->next是要遍历的结点)
	while (p->next){   
		//p指向要删除结点的前驱，删除p的下一个结点q
		if (p->next->data > min && p->next->data < max){  
			q = p->next; 
			p->next = q->next;
			free(q);
		}
		else
			p = p->next;
	}
}

void main() {
	LinkList L;
	CreateList_L(L, 5);
	Delete_Between(L, 5, 9);

	LinkList p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
}