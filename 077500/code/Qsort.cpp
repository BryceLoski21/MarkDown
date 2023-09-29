#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OVERFLOW 0
#define OK 1

typedef int ElemType;
typedef int Status;


typedef struct{

    ElemType *elem;

    int length;

    int listsize;
}SqList;

Status InitList_Sq(SqList &L){

    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));

    if(!L.elem) exit(OVERFLOW);

    L.length = 0;

    L.listsize = LIST_INIT_SIZE;

    return OK;
}

int Partition(SqList &L, int low, int high){

    L.r[0] = L.r[low];

    int pivotkey = L.r[low].key;

    while(low < high){

        while(low < high && L.r[high].key >= pivotkey) --high;
        L.r
    }

    return 0;
}

void Qsort(SqList &L, int low, int high){
    
    if(low < high){

        int pivotloc = Partition(L, low, high);
    }
}

int main(){
    
    return 0;
}