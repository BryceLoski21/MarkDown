#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int ElemType;
typedef int KeyType;
typedef int Status;

#define OK 1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100

// ��̬���ұ��˳��洢�ṹ
typedef struct SSTable {
	ElemType *elem;
	KeyType *key;
	int length;
}SSTable;

// ��ʼ����̬���ұ�
Status InitSSTable_ST(SSTable& ST) {
	ST.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!ST.elem) exit(OVERFLOW);
	ST.key = (KeyType*)malloc(LIST_INIT_SIZE * sizeof(KeyType));
	if (!ST.key) exit(OVERFLOW);
	ST.length = 0;
	return OK;
}

// ��˳���ST�в�����ؼ��ֵ���key��Ԫ��,���ҵ�,������λ��,����Ϊ0
int Search_Seq(SSTable ST, KeyType key) {
	int i;
	ST.key[0] = key; // �ڱ�
	for (i = ST.length; ST.key[i] != key; --i);
	return i;
}

void main() {
	SSTable ST;
	InitSSTable_ST(ST);

	int a[5] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 5; i++) {
		ST.key[i] = i;
		ST.elem[i] = i;
		ST.length++;
	}

	printf("location: %d", Search_Seq(ST, 4));
}
