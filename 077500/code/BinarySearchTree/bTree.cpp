#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bTree.h"

// ����ڵ�
/*
    tree ���ڵ�
    data �ڵ��е�����
    idx  �ڵ������
    dataSize һ�β���ڵ�ĸ���
*/
int treeInsert(bTree** tree, void* data, int idx, int dataSize)
{
    bTree* treeNode = NULL;

    // Ҷ�ӽڵ�����ҽڵ�
    if (NULL == *tree)
    {
        // �����ڵ�
        treeNode = (bTree*)malloc(sizeof(bTree));
        if (NULL == treeNode)
        {
            perror("malloc: ");
            return -1;
        }
        treeNode->data = malloc(dataSize);
        if (NULL == treeNode->data)
        {
            perror("malloc: ");
            return -1;
        }

        treeNode->left = NULL;
        treeNode->right = NULL;
        treeNode->idx = idx;
        if (NULL == memcpy(treeNode->data, data, dataSize))
        {
            perror("memcpy: ");
            return -2;
        }

        // ���ӽڵ�
        *tree = treeNode;

        return 0;
    }

    // �½ڵ�������ȸ��ڵ������ڵ���������
    if (idx > (*tree)->idx)
    {
        return treeInsert(&(*tree)->right, data, idx, dataSize);
    }

    return treeInsert(&(*tree)->left, data, idx, dataSize);
}

// ���ҽڵ�
/*
    tree ���ĸ��ڵ�
    idx  Ҫ���ҽڵ������
    node �ҵ��Ľڵ�
*/
int treeSearch(bTree* tree, int idx, bTree** node)
{
    if (NULL == tree)
    {
        // ������Ҷ�ӽڵ����������
        return 0;
    }

    // �����Ƚ�
    if (tree->idx == idx)
    {
        *node = tree;
        return 0;
    }

    if (idx > tree->idx)
    {
        return treeSearch(tree->right, idx, node);
    }

    return treeSearch(tree->left, idx, node);
}

// �滭��
/*
    tree  ���ĸ��ڵ�
    level ���ڵ�����ն���߽�ľ���
*/
void treeDraw(bTree* tree, int level)
{
    int i;

    // ������Ҷ�ӽڵ����������
    if (NULL == tree)
        return;

    // �����󵹣��Ȼ����������ٻ����ڵ㣬�ڻ�������
    treeDraw(tree->right, level + 1);

    // ���ڵ�֮ǰ�����ݽڵ����ڵĲ�������ӡ�ָ��
    for (i = 0; i < level; i++)
        printf("\t");

    //sleep(1);
    printf("%d\n\n", tree->idx);

    // �ҵ���һ��Ҫ���Ľڵ��Ժ󣬻�Ҫ����һ�������Բ�return
    treeDraw(tree->left, level + 1);
}

// ��ȡ���ڵ������������������ڵ������
static int getNodeNum(bTree* tree)
{
    if (NULL == tree)
    {
        return 0;
    }

    // �ݹ�Ҷ�ӽڵ�������������ڵ��������
    return getNodeNum(tree->left) + 1 + getNodeNum(tree->right);
}

static bTree* maxLeftDepth(bTree* tree)
{
    if (NULL == tree->left)
    {
        return tree;
    }

    return maxLeftDepth(tree->left);
}

static bTree* maxRightDepth(bTree* tree)
{
    if (NULL == tree->right)
    {
        return tree;
    }

    return maxRightDepth(tree->right);
}

// ����
static int turnLeft(bTree** tree)
{
    bTree* root = *tree;    // ��¼���ڵ�
    *tree = (*tree)->right; // ���������������ĸ��ڵ��Ϊ�µĸ��ڵ�
    root->right = NULL;     // �ɸ��ڵ�Ͽ�������

    bTree* leftNode;
    leftNode = maxLeftDepth(*tree); // �ҵ��µĸ��ڵ�������������ڵ�
    leftNode->left = root;

    // ������ƽ��Ĺ���
    // getchar();
    // printf("-------------------------\n");
    // treeDraw(*tree, 0);

    return 0;
}

// ����
static int turnRight(bTree** tree)
{
    bTree* root = *tree;
    (*tree) = (*tree)->left;
    root->left = NULL;

    bTree* rightNode;
    rightNode = maxRightDepth(*tree); // �ҵ��µĸ��ڵ�������������ڵ�
    rightNode->right = root;

    // getchar();
    // printf("-------------------------\n");
    // treeDraw(*tree, 0);

    return 0;
}

// ƽ����
void treeBalance(bTree** tree)
{
    int sub = 0;
    if (NULL == *tree)
    {
        // �ݹ鵽Ҷ�ӽڵ����������
        return;
    }

    while (1)
    {
        // ���ڵ���������ڵ�ĸ������������ڵ�ĸ�������ֵΪ1����Ϊ��ƽ��
        sub = getNodeNum((*tree)->left) - getNodeNum((*tree)->right);
        if (sub >= -1 && sub <= 1)
        {
            break;
        }
        // ��������ǰ�ڵ����������Ϊ���ڵ㡣��������Ϊ�¸��ڵ��������
        else if (sub < -1)
        {
            turnLeft(tree);
        }
        // ��������ǰ�ڵ����������Ϊ���ڵ㡣��������Ϊ�¸��ڵ��������
        else if (sub > 1)
        {
            turnRight(tree);
        }
    }

    // ���ڵ�ƽ����Ժ�ƽ����������
    treeBalance(&(*tree)->left);

    treeBalance(&(*tree)->right);
}

// ɾ���ڵ�
/*
    tree ���ĸ��ڵ�
    idx  Ҫɾ���ڵ������
*/
int treeDelete(bTree** tree, int idx)
{
    bTree** deleteNode = tree;
    // ָ����ڵ��ָ���ƶ���Ҫɾ���Ľڵ���
    while (*deleteNode != NULL && (*deleteNode)->idx != idx)
    {
        if (idx < (*deleteNode)->idx)
            deleteNode = &(*deleteNode)->left;
        else
            deleteNode = &(*deleteNode)->right;
    }
    if (NULL == *deleteNode)
    {
        return -1;
    }

    bTree* cur = *deleteNode;
    // Ҫɾ���ڵ㣬�������ĸ��ڵ㣬���ǵ�ǰ�ڵ�

    if (NULL == cur->left)
    {
        *deleteNode = cur->right;
    }
    else
    {
        *deleteNode = cur->left;
        bTree* rightNode;
        rightNode = maxRightDepth(cur->left);
        rightNode->right = cur->right;
    }

    free(cur->data);

    free(cur);

    return 0;
}

// ������� - �����ҵ�˳��
// ������� - ����ҵ�˳��
// ������� - ���Ҹ���˳��
void treeTravel(bTree* tree)
{
    if (NULL == tree)
    {
        return;
    }

    printf("%d ", tree->idx);
    fflush(stdout);

    treeTravel(tree->left);

    treeTravel(tree->right);
}

// ���İ������
int treeTravelLevel(bTree* tree, int idxLen)
{
    // ʹ�ö��д�Žڵ�
    typedef struct
    {
        int* idx;
        int head, tail;
    } idxQueue;

    idxQueue* queue = (idxQueue*)malloc(sizeof(idxQueue));
    if (NULL == queue)
    {
        perror("malloc: ");
        return -1;
    }
    // ͷ���ڵ�λ�ò�������
    queue->idx = (int*)malloc(sizeof(int) * idxLen);
    if (NULL == queue->idx)
    {
        perror("malloc: ");
        return -1;
    }
    queue->head = queue->tail = 0;

    queue->tail = (queue->tail + 1) % idxLen;
    queue->idx[queue->tail] = tree->idx; // ���ڵ����
    bTree* node;
    int isRoot = 1;

    while (1)
    {
        // ������������еĽڵ�
        if ((queue->head == queue->tail) && (isRoot == 0))
            break;
        isRoot = 0;

        queue->head = (queue->head + 1) % idxLen;
        printf("%d ", queue->idx[queue->head]);
        fflush(stdout);
        if ((queue->tail + 1) % idxLen == queue->head)
            break;

        // ���ڵ����
        treeSearch(tree, queue->idx[queue->head], &node);

        // ���ڵ�����ڵ�����
        if (NULL != node->left)
        {
            queue->tail = (queue->tail + 1) % idxLen;
            queue->idx[queue->tail] = node->left->idx;
        }
        // ���ڵ����ҽڵ�����
        if (NULL != node->right)
        {
            queue->tail = (queue->tail + 1) % idxLen;
            queue->idx[queue->tail] = node->right->idx;
        }
    }
    free(queue);
    free(queue->idx);

    return 0;
}
