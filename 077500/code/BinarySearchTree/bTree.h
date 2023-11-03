#ifndef B_TREE__
#define B_TREE__

typedef struct BinaryTree
{
    struct BinaryTree* left;
    struct BinaryTree* right;
    int idx;
    void* data;
} bTree;

// ����ڵ�
int treeInsert(bTree**, void*, int, int);

// ���ҽڵ�
int treeSearch(bTree*, int, bTree**);

// �滭��
void treeDraw(bTree*, int);

// ƽ����
void treeBalance(bTree**);

// ɾ���ڵ�
int treeDelete(bTree**, int);

// ���ı���
void treeTravel(bTree*);

// ���İ������
int treeTravelLevel(bTree*, int);

#endif

