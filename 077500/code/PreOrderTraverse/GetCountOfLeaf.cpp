#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

int count = 0;

// �������Ķ�������洢��ʾ
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild; // ���Һ���ָ��
}BiTNode, *BiTree;

// ������������ʾ�Ķ�����T
Status CreateBiTree(BiTree &T) {
	int data;
	scanf_s("%d", &data);

	if (data == -1) {
		T = NULL; // �����ݹ�ʱ�õ�ǰ����ָ��ָ��NULL
	}
	else {
		T = (BiTree)malloc(sizeof(BiTree)); // �����ڴ�
		if (!T) { // T == NULL, �ڴ����ʧ��,�����ݹ�
			printf("�ڴ����ʧ��\n");
			exit(OVERFLOW);
		}
		T->data = data;

		printf("������%d��������: ", data);
		CreateBiTree(T->lchild); // ����������

		printf("������%d��������: ", data);
		CreateBiTree(T->rchild); // ����������
	}
	return OK;
}

//	�������������
void PreOrderTraverse(BiTree T)		
{
	if (T == NULL)
	{
		return;
	}
	printf("%d ", T->data);
	PreOrderTraverse(T->lchild); //	����������
	PreOrderTraverse(T->rchild); //	����������
}

// ���ض�������Ҷ�ӽ�����
int GetCountOfLeaf(BiTree &r) {
	// int count = 0; 
	// bug��ÿ�εݹ����count�����ʼ��Ϊ0
	// debug: ��count�����ȫ�ֱ���
	if (r != NULL) { // �ǿ�
		if (r->lchild == NULL && r->rchild == NULL) {
			count++;
		}
		GetCountOfLeaf(r->lchild);
		GetCountOfLeaf(r->rchild);
	}
	return count;
}

int main() {
	BiTree T;

	printf("�������һ����������: \n");
	CreateBiTree(T);

	PreOrderTraverse(T);

	printf("Ҷ�ӽ�����: %d", GetCountOfLeaf(T));

	return 0;
}