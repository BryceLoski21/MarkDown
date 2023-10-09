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

// 静态查找表的顺序存储结构
typedef struct SSTable {
	ElemType *elem;
	KeyType *key;
	int length;
}SSTable;

// 初始化静态查找表
Status InitSSTable_ST(SSTable& ST) {
	ST.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!ST.elem) exit(OVERFLOW);
	ST.key = (KeyType*)malloc(LIST_INIT_SIZE * sizeof(KeyType));
	if (!ST.key) exit(OVERFLOW);
	ST.length = 0;
	return OK;
}

// 在顺序表ST中查找其关键字等于key的元素,若找到,返回其位置,否则为0
int Search_Seq(SSTable ST, KeyType key) {
	int i;
	ST.key[0] = key; // 哨兵
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
