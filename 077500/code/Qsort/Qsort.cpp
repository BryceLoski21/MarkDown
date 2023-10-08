#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OVERFLOW -2
#define OK 1

typedef int ElemType;
typedef int Status;


typedef struct SqList {

    ElemType* elem;

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

int Partition(SqList& L, int low, int high) {

    //L.elem[0] = L.elem[low];

    int pivotkey = L.elem[low];

    int temp;

    while (low < high) {

        while (low < high && L.elem[high] >= pivotkey) --high;

        temp = L.elem[low];
        L.elem[low] = L.elem[high];
        L.elem[high] = temp;

        while (low < high && L.elem[low] <= pivotkey) ++low;

        temp = L.elem[high];
        L.elem[high] = L.elem[low];
        L.elem[low] = temp;
    }

    //L.elem[low] = L.elem[0];
    for (int count = 0; count < 7; count++) {
        printf("%d  ", L.elem[count]);
    }
    printf("\n");

    return low;
}

void Qsort(SqList& L, int low, int high) {

    if (low < high) {

        int pivotloc = Partition(L, low, high);

        Qsort(L, low, pivotloc - 1);

        Qsort(L, pivotloc + 1, high);
    }
}

int main() {

    SqList L;

    int a[7] = { 65, 76, 18, 36, 95, 30, 15 };

    InitList_Sq(L);

    for (int count = 0; count < 7; count++) {
        L.elem[count] = a[count];
    }

    //printf("³õÊ¼ÐòÁÐ£º");
    //for (int count = 0; count < 7; count++) {
    //    printf("%d  ", L.elem[count]);
    //}
    //printf("\n");

    Qsort(L, 0, 6);

    return 0;
}