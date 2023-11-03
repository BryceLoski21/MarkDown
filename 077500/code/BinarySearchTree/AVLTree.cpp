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
#define LT(a, b) ((a) < (b)) // С��
#define EQ(a, b) ((a) == (b)) // ����

typedef struct AVLNode* Tree;

typedef int ElementType;

struct AVLNode {

    int depth; //��ȣ��������ÿ��������ȣ�ͨ����ȵıȽϿɵó��Ƿ�ƽ��

    Tree parent; //�ý��ĸ��ڵ�

    ElementType val; //���ֵ

    Tree lchild;

    Tree rchild;

    AVLNode(int val = 0) {
        parent = NULL;
        depth = 0;
        lchild = rchild = NULL;
        this->val = val;
    }
};

