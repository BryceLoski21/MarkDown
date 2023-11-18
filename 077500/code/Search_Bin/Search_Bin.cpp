#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define OK 1
#define OVERFLOW -2
#define INIT_LENGTH 100

typedef int Status;

typedef int KeyType;

typedef struct {
	KeyType key; // �ؼ�����
	int data;
}ElemType;

typedef struct {
	ElemType* elem; // 0�ŵ�Ԫ����
	int length;
}SSTable;

// �۰����˳����йؼ�����ͬ��Ԫ��,�����±�
int Search_Bin(SSTable ST, KeyType key) {
	int low = 1;
	int high = ST.length;
	while (low < high) {
		int mid = (low + high) / 2;
		if (ST.elem[mid].key == key)
			return mid;
		if (ST.elem[mid].key > key)
			high = mid - 1;
		if (ST.elem[mid].key < key)
			low = mid + 1;
	}
	return 0;
}

Status Insert_ST(SSTable &ST, int i, ElemType e) {
	// ��i��λ�ò���e
	if (i<1 || i>ST.length)
		return OVERFLOW; // λ�ò��Ϸ�
	if (ST.length == INIT_LENGTH) {
		ElemType* newbase = (ElemType*)realloc(ST.elem, (ST.length + INIT_LENGTH) * sizeof(ElemType));
		assert(newbase);
		ST.elem = newbase;
	}
	ElemType* q = &(ST.elem[i - 1]);
	for (ElemType* p = &(ST.elem[ST.length - 1]); p >= q; --p) {
		*(p + 1) = *p;
	}
	*q = e;
	ST.length += 1;
	return OK;
}

int main() {
	SSTable ST;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * INIT_LENGTH);
	ST.length = 1;

	ElemType e;

	for (int i = 1; i < 10; i++) {
		e.data = e.key = i;
		Insert_ST(ST, 1, e);
	}

	printf("%d ", Search_Bin(ST, 4));

	return 0;
}