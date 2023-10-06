#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//typedef int KeyType;
typedef int ElemType;
typedef int Status;

#define OVERFLOW -2
#define OK 1;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#define LT(a, b) ((a) < (b))

typedef struct SqList{
	ElemType *elem;
	//KeyType key;
	int length;
	int listsize;
}SqList;

Status InitList_Sq(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

void ShellSort_2(int* arr, int size) {
	int gap = size;
	while (gap > 1) {
		gap = gap / 3 + 1;	//调整希尔增量
		for (int i = 0; i < size - gap; i++) {	//从0遍历到size-gap-1
			int temp = arr[i + gap];
			while (i >= 0) {
				if (arr[i] > temp) {
					arr[i + gap] = arr[i];
					i -= gap;
				}
				else
					break;
			}
			arr[i + gap] = temp;	//以 i+gap 作为插入位置
		}
	}
}

void ShellInsert(SqList &L, int dk) {
	for (int i = dk; i < L.length; i++) {
		if (LT(L.elem[i], L.elem[i - dk])) { // 将L.elem[i]插入有序增量子表
			int temp = L.elem[i - dk]; // 暂存
			L.elem[i - dk] = L.elem[i]; // 把后面大的记录移到前面
			int j;
			for (j = i - dk; j > 0 && LT(temp, L.elem[j]); j -= dk) { ;
				L.elem[j + dk] = L.elem[j]; // 把前面小的记录移到后面
			}
			L.elem[j+dk] = temp; // 插入
		}
	}
	/*for (int i = 0; i < L.length; i++) {
		printf("%d ", L.elem[i]);
	}
	printf("\n");*/
}

void ShellSort(SqList &L, int dlta[], int t) {
	// 按增量序列dlta[0...t-1]对顺序表L进行希尔排序
	for (int k = 0; k < t; ++k)
		ShellInsert(L, dlta[k]); // 一趟增量为dlta[k]的插入排序
}

int main() {
	SqList L;
	InitList_Sq(L);
	int a[6] = { 25, 73, 12, 80, 116, 15 };
	int dlta[3] = { 3, 2, 1 };
	for (int i = 0; i < 6; i++) {
		L.elem[i] = a[i];
		L.length++;
	}
	printf("L.length:%d\n", L.length);

	//ShellSort_2(a, 6);

	ShellSort(L, dlta, 3);

	for (int i = 0; i < 6; i++) {
		printf("%d ", L.elem[i]);
	}

	return 0;
}