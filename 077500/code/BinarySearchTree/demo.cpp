#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bTree.h"

#define NAMESIZE 128

struct Data
{
    unsigned char drugCode;  // ҩ��
    char drugName[NAMESIZE]; // ҩ��
};

static int print(struct Data* treeData)
{
    printf("drugCode: %hhu drugName: %s\n",
        treeData->drugCode, treeData->drugName);

    return 0;
}

int main()
{
    int idxArr[] = { 1, 2, 3, 7, 6, 5, 9, 8, 4, 15, 29, 17, 23 };
    int i;
    struct Data drugData;
    bTree* treeRoot = NULL; // ָ���ʼ��ΪNULL����ָֹ��һ��δ֪�Ŀռ�

    for (i = 0; i < sizeof(idxArr) / sizeof(*idxArr); i++)
    {
        drugData.drugCode = idxArr[i] + rand() % 100;
        snprintf(drugData.drugName, NAMESIZE, "drug_%ld", time(NULL) - idxArr[i]);

        treeInsert(&treeRoot, &drugData, idxArr[i], sizeof(struct Data));
    }

    int idx = 3;
    bTree* treeNode = NULL;
    treeSearch(treeRoot, idx, &treeNode);
    if (NULL != treeNode)
    {
        struct Data* drugNode = (Data*)treeNode->data;
        print(drugNode);
    }

    // ���ڵ����ߵ�0���ַ���ʼ��ӡ
    treeDraw(treeRoot, 0);

    // ƽ�������
    treeBalance(&treeRoot);
    printf("ƽ������������з�x3\n\n\n");
    treeDraw(treeRoot, 0);

    // ɾ������Ϊ3�Ľڵ�
    if (treeDelete(&treeRoot, idx) == 0)
    {
        printf("ɾ������Ϊ3�Ľ�㣬���з�x3\n\n\n");
        treeDraw(treeRoot, 0);
    }

    treeTravel(treeRoot);
    printf("���з�\n");

    treeTravelLevel(treeRoot, sizeof(idxArr) / sizeof(*idxArr));
    printf("���з�\n");

    return 0;
}
