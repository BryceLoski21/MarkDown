#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//typedef int ElemType;
typedef int KeyType;
typedef int Status;

#define OK 1
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define MAXSIZE 100
#define LT(a, b) ((a) < (b)) // 小于
#define EQ(a, b) ((a) == (b)) // 等于

typedef struct AVLNode* Tree;

typedef int ElementType;

struct AVLNode {

    int depth; //深度，这里计算每个结点的深度，通过深度的比较可得出是否平衡

    Tree parent; //该结点的父节点

    ElementType val; //结点值

    Tree lchild;

    Tree rchild;

    AVLNode(int val = 0) {
        parent = NULL;
        depth = 0;
        lchild = rchild = NULL;
        this->val = val;
    }
};

