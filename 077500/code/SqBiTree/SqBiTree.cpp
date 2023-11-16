#include <stdio.h>  

#define MAX_SIZE 10

// ������Ϊ�洢��ʽ�Ķ������ṹ��  
typedef struct BinaryTree {
    int data[MAX_SIZE];  // �洢�ڵ������  
    int size;             // �������Ĵ�С  
} BinaryTree;

// ��ʼ��������  
void init(BinaryTree* tree, int size) {
    tree->size = size;
    for (int i = 0; i < size; i++) {
        tree->data[i] = 0;
    }
}

// �������������  
void preorderTraversal(BinaryTree* tree, int index) {
    if (index >= tree->size) {
        return;
    }
    printf("%d ", tree->data[index]);  // ���ʵ�ǰ�ڵ�  
    preorderTraversal(tree, index * 2 + 1);  // ����������  
    preorderTraversal(tree, index * 2 + 2);  // ����������  
}

int main() {
    BinaryTree tree;
    init(&tree, MAX_SIZE);

    // �����������������鷽ʽ�洢��  
    tree.data[0] = 1;
    tree.data[1] = 2;
    tree.data[2] = 3;
    tree.data[3] = 4;
    tree.data[4] = 5;
    tree.data[5] = 6;
    tree.data[6] = 7;
    tree.data[7] = 8;

    printf("������������");
    preorderTraversal(&tree, 0);  // �Ӹ��ڵ㿪ʼ����  
    printf("\n");

    return 0;
}