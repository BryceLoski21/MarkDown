#include <stdio.h>  

#define MAX_SIZE 10

// 以数组为存储方式的二叉树结构体  
typedef struct BinaryTree {
    int data[MAX_SIZE];  // 存储节点的数组  
    int size;             // 二叉树的大小  
} BinaryTree;

// 初始化二叉树  
void init(BinaryTree* tree, int size) {
    tree->size = size;
    for (int i = 0; i < size; i++) {
        tree->data[i] = 0;
    }
}

// 先序遍历二叉树  
void preorderTraversal(BinaryTree* tree, int index) {
    if (index >= tree->size) {
        return;
    }
    printf("%d ", tree->data[index]);  // 访问当前节点  
    preorderTraversal(tree, index * 2 + 1);  // 访问左子树  
    preorderTraversal(tree, index * 2 + 2);  // 访问右子树  
}

int main() {
    BinaryTree tree;
    init(&tree, MAX_SIZE);

    // 构建二叉树（以数组方式存储）  
    tree.data[0] = 1;
    tree.data[1] = 2;
    tree.data[2] = 3;
    tree.data[3] = 4;
    tree.data[4] = 5;
    tree.data[5] = 6;
    tree.data[6] = 7;
    tree.data[7] = 8;

    printf("先序遍历结果：");
    preorderTraversal(&tree, 0);  // 从根节点开始遍历  
    printf("\n");

    return 0;
}