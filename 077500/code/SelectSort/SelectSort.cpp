#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100 // ���Ա�洢�ռ��ʼ������
#define LISTINCREMENT 10 // ���Ա��������

typedef int ElemType;
typedef int Status;

typedef struct SqList {
	ElemType *elem;
	int length;
	int listsize; // �洢������sizeof(ElemType)Ϊ��λ
}SqList;

Status InitList_Sq(SqList& L) {
	// ����һ�������Ա�L
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW); // ����ʧ��
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

int SelectMinKey(SqList& L, int i) {
	int min = i;
	for (int j = i + 1; j < L.length; j++) 
		if (L.elem[j] < L.elem[min]) min = j;
	return min;
}

void SelectSort(SqList& L) {
	// ��˳�����м�ѡ������
	for (int i = 0; i < L.length; i++) {
		int j = SelectMinKey(L, i); // ѡ����С�ļ�¼
		if (i != j) {
			int temp = L.elem[i];
			L.elem[i] = L.elem[j];
			L.elem[j] = temp;
		}
	}
}

void main() {
	SqList L;
	InitList_Sq(L);

	int a[5] = { 28, 64, 36, 16, 49 };
	for (int i = 0; i < 5; i++) {
		L.elem[i] = a[i];
		L.length++; // ���Ԫ��ͬʱ�ǵ����ӳ���
		printf("%d ", L.elem[i]);
	} // ��ӡδ�����˳���
	printf("\n"); 

	SelectSort(L);

	for (int i = 0; i < 5; i++) { // ��ӡ������˳���
		printf("%d ", L.elem[i]);
	}
}