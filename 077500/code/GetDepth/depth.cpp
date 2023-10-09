#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;

#define OK 1
#define OVERFLOW -2
#define max(a, b) ((a) > (b) ? (a) : (b))

// ��������洢�Ķ�����
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

// ������������ʾ�Ķ�����T
Status CreateBiTree(BiTree& T) {
	// �������������������еĽ���ֵ
	
	int data;
	scanf_s("%d", &data);

	if (data == -1) {
		T = NULL;
	}
	else {
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data = data;

		printf("������%d��������:\n", data);
		CreateBiTree(T->lchild); // ��ʼ����������
		printf("������%d��������:\n", data);
		CreateBiTree(T->rchild); // ��ʼ����������
	}
	return OK;
}

// ����������
int depth(BiTree& root) {
	if (root == NULL) {
		return 0;
	}
	else
	{
		int leftHight = depth(root->lchild);
		int rightHight = depth(root->rchild);
		return 1 + max(leftHight, rightHight);
	}

}

void main() {
	BiTree T;
	printf("�������һ�����: \n");
	CreateBiTree(T);

	printf("���������: %d", depth(T));
}