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
#define LT(a, b) ((a) < (b)) // 小于
#define EQ(a, b) ((a) == (b)) // 等于
#define max(a, b) ((a) > (b)? (a) : (b)) // 返回最大值
#define LH +1 //左高
#define EH 0  //等高
#define RH -1 //右高


struct ElemType {
	int data;
	KeyType key;
};

typedef struct BSTNode {
	ElemType elem;
	int bf; // 平衡因子
	struct BSTNode* lchild, * rchild;
}BSTNode, * BSTree;

void R_Rotate(BSTree& p) {
	// 右旋, 处理之前的左子树根结点
	BSTree lc = p->lchild; // lc指向*p的左子树
	p->lchild = lc->rchild; // lc的右子树接为*p的左子树
	lc->rchild = p;
	p = lc; // p指向新的根结点
}

void L_Rotate(BSTree& p) {
	// 左旋, 处理之前的右子树根结点
	BSTree rc = p->rchild; // rc指向*p的右子树
	p->rchild = rc->lchild; // rc的左子树接为*p的右子树
	rc->lchild = p;
	p = rc; // p指向新的根结点
}

void LeftBalance(BSTree& T){
	// 对以指针Ｔ所指结点为根的二叉树作左平衡旋转处理
	BSTree lc, rd;
	lc = T->lchild;          // lc指向*T的左子树根结点
	switch (lc->bf){         // 检查*T的左子树的平衡度，并作相应平衡处理
	case LH:                 // 新结点插入在*T的左孩子的左子树上，要作单右旋处理
		T->bf = lc->bf = EH;
		R_Rotate(T);
		break;
	case RH:                 // 新结点插入在*T的左孩子的右子树上，要作双旋处理
		rd = lc->rchild;     // rd指向*T的左孩子的右子树根
		switch (rd->bf){       // 修改*T及其左孩子的平衡因子
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
		L_Rotate(T->lchild); // 对*T的左子树作左旋平衡处理
		R_Rotate(T);         // 对*T作右旋平衡处理
	}
}


void RightBalance(BSTree& T){
	// 对以指针Ｔ所指结点为根的二叉树作右平衡旋转处理
	BSTree rc, ld;
	rc = T->rchild;         // rc指向*T的左子树根结点
	switch (rc->bf){        // 检查*T的右子树的平衡度，并作相应平衡处理
	case RH:                // 新结点插入在*T的右孩子的右子树上，要作单左旋处理
		T->bf = rc->bf = EH;
		L_Rotate(T); 
		break;
	case LH:                // 新结点插入在*T的右孩子的左子树上，要作双旋处理
		ld = rc->lchild;    // ld指向*T的右孩子的左子树根
		switch (ld->bf){    // 修改*T及其右孩子的平衡因子
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
		R_Rotate(T->rchild); // 对*T的右子树作左旋平衡处理
		L_Rotate(T);         // 对*T作左旋平衡处理
	}
}

Status InsertAVL(BSTree& T, ElemType e, Boolean& taller) {
	// 平衡二叉排序树的插入(不存在关键字相同的结点)
	// taller反映T长高与否
	if (!T) { // 插入新结点, taller置TRUE
		T = (BSTree)malloc(sizeof(BSTNode));
		assert(T);
		T->elem = e;
		T->lchild = T->rchild = NULL;
		T->bf = EH;
		taller = TRUE;
	}
	else {
		if (EQ(e.key, T->elem.key)) { // 树中存在关键字相同的结点,taller置FALSE,不再插入
			taller = FALSE;
			return 0;
		}
		// 进入左子树中搜索
		if (LT(e.key, T->elem.key)) { 
			if (!InsertAVL(T->lchild, e, taller)) return 0; // 不插入
			if (taller) {
				switch (T->bf) { // 检查平衡因子
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
		// 进入右子树进行搜索
		else {
			if (!InsertAVL(T->rchild, e, taller)) return 0; // 不插入
			if (taller) {
				switch (T->bf) { // 检查平衡因子
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

	// 平衡二叉排序树
	BSTree bsT = (BSTree)malloc(sizeof(BSTNode));
	assert(bsT);
	bsT = NULL; // 构造一颗空树
	ElemType e;
	Boolean taller;
	for (int i = 0; i < 10; i++) { // 右单支树
		e.data = e.key = i;
		InsertAVL(bsT, e, taller);
	}
	//printf("%d ", bsT->elem.key);
	inOrderTraverse(bsT);
	return 0;
}