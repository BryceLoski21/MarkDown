#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100 // 线性表存储空间初始分配量
#define LISTINCREMENT 10 // 线性表分配增量

typedef int ElemType;
typedef int Status;

typedef struct SqList {
	ElemType *elem;
	int length;
	int listsize; // 存储容量以sizeof(ElemType)为单位
}SqList;

Status InitList_Sq(SqList& L) {
	// 构造一个空线性表L
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW); // 分配失败
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
	// 对顺序表进行简单选择排序
	for (int i = 0; i < L.length; i++) {
		int j = SelectMinKey(L, i); // 选择最小的记录
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
		L.length++; // 添加元素同时记得增加长度
		printf("%d ", L.elem[i]);
	} // 打印未排序的顺序表
	printf("\n"); 

	SelectSort(L);

	for (int i = 0; i < 5; i++) { // 打印排序后的顺序表
		printf("%d ", L.elem[i]);
	}
}