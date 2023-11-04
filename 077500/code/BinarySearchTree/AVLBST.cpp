#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

//typedef int ElemType;
typedef int KeyType;
typedef int Status;

#define OK 1
//#define TRUE 1
//#define FALSE 0
typedef enum {TRUE=1, FALSE=0}Boolean;
#define OVERFLOW -2
#define MAXSIZE 100
#define LT(a, b) ((a) < (b)) // С��
#define EQ(a, b) ((a) == (b)) // ����
#define max(a, b) ((a) > (b)? (a) : (b)) // �������ֵ
#define LH +1 //���
#define EH 0  //�ȸ�
#define RH -1 //�Ҹ�


struct ElemType {
	int data;
	KeyType key;
};

typedef struct BSTNode {
	ElemType elem;
	int bf; // ƽ������
	struct BSTNode* lchild, * rchild;
}BSTNode, * BSTree;

void R_Rotate(BSTree& p) {
	// ����, ����֮ǰ�������������
	BSTree lc = p->lchild; // lcָ��*p��������
	p->lchild = lc->rchild; // lc����������Ϊ*p��������
	lc->rchild = p;
	p = lc; // pָ���µĸ����
}

void L_Rotate(BSTree& p) {
	// ����, ����֮ǰ�������������
	BSTree rc = p->rchild; // rcָ��*p��������
	p->rchild = rc->lchild; // rc����������Ϊ*p��������
	rc->lchild = p;
	p = rc; // pָ���µĸ����
}

void LeftBalance(BSTree& T){
	// ����ָ�����ָ���Ϊ���Ķ���������ƽ����ת����
	BSTree lc, rd;
	lc = T->lchild;          // lcָ��*T�������������
	switch (lc->bf){         // ���*T����������ƽ��ȣ�������Ӧƽ�⴦��
	case LH:                 // �½�������*T�����ӵ��������ϣ�Ҫ������������
		T->bf = lc->bf = EH;
		R_Rotate(T);
		break;
	case RH:                 // �½�������*T�����ӵ��������ϣ�Ҫ��˫������
		rd = lc->rchild;     // rdָ��*T�����ӵ���������
		switch (rd->bf){       // �޸�*T�������ӵ�ƽ������
		case LH:
			T->bf = RH;
			lc->bf = EH;
			break;
		case EH:
			T->bf = lc->bf = EH;
			break;
		case RH:
			T->bf = EH;
			lc->bf = LH; 
			break;
		}
		rd->bf = EH;
		L_Rotate(T->lchild); // ��*T��������������ƽ�⴦��
		R_Rotate(T);         // ��*T������ƽ�⴦��
	}
}


void RightBalance(BSTree& T){
	// ����ָ�����ָ���Ϊ���Ķ���������ƽ����ת����
	BSTree rc, ld;
	rc = T->rchild;         // rcָ��*T�������������
	switch (rc->bf){        // ���*T����������ƽ��ȣ�������Ӧƽ�⴦��
	case RH:                // �½�������*T���Һ��ӵ��������ϣ�Ҫ������������
		T->bf = rc->bf = EH;
		L_Rotate(T); 
		break;
	case LH:                // �½�������*T���Һ��ӵ��������ϣ�Ҫ��˫������
		ld = rc->lchild;    // ldָ��*T���Һ��ӵ���������
		switch (ld->bf){    // �޸�*T�����Һ��ӵ�ƽ������
		case LH:
			T->bf = EH;
			rc->bf = RH; 
			break;
		case EH: 
			T->bf = rc->bf = EH; 
			break;
		case RH: 
			T->bf = LH; 
			rc->bf = EH;
			break;
		}
		ld->bf = EH;
		R_Rotate(T->rchild); // ��*T��������������ƽ�⴦��
		L_Rotate(T);         // ��*T������ƽ�⴦��
	}
}

Status InsertAVL(BSTree& T, ElemType e, Boolean& taller) {
	// ƽ������������Ĳ���(�����ڹؼ�����ͬ�Ľ��)
	// taller��ӳT�������
	if (!T) { // �����½��, taller��TRUE
		T = (BSTree)malloc(sizeof(BSTNode));
		assert(T);
		T->elem = e;
		T->lchild = T->rchild = NULL;
		T->bf = EH;
		taller = TRUE;
	}
	else {
		if (EQ(e.key, T->elem.key)) { // ���д��ڹؼ�����ͬ�Ľ��,taller��FALSE,���ٲ���
			taller = FALSE;
			return 0;
		}
		// ����������������
		if (LT(e.key, T->elem.key)) { 
			if (!InsertAVL(T->lchild, e, taller)) return 0; // ������
			if (taller) {
				switch (T->bf) { // ���ƽ������
				case LH:
					LeftBalance(T);
					taller = FALSE;
					break;
				case EH:
					T->bf = LH;
					taller = TRUE;
					break;
				case RH:
					T->bf = EH;
					taller = FALSE;
					break;
				}
			}
		}
		// ������������������
		else {
			if (!InsertAVL(T->rchild, e, taller)) return 0; // ������
			if (taller) {
				switch (T->bf) { // ���ƽ������
				case LH:
					T->bf = EH;
					taller = FALSE;
					break;
				case EH:
					T->bf = RH;
					taller = TRUE;
					break;
				case RH:
					RightBalance(T);
					taller = FALSE;
					break;
				}
			}
		}
	}
	return 1;
}

void inOrderTraverse(BSTree& T) {
	if (T) {
		inOrderTraverse(T->lchild);
		printf("%d ", T->elem.data);
		inOrderTraverse(T->rchild);
	}
}

int main() {

	// ƽ�����������
	BSTree bsT = (BSTree)malloc(sizeof(BSTNode));
	assert(bsT);
	bsT = NULL; // ����һ�ſ���
	ElemType e;
	Boolean taller;
	for (int i = 0; i < 10; i++) { // �ҵ�֧��
		e.data = e.key = i;
		InsertAVL(bsT, e, taller);
	}
	//printf("%d ", bsT->elem.key);
	inOrderTraverse(bsT);
	return 0;
}