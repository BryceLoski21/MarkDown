#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* Expurgate(Node* head) {
	// 剔除重复元素
	Node* p, * q, * r;
	p = head;
	while (p) {
		q = p; // 第一个位置
		r = q->next; // 第二个位置
		while (r) {
			if (p->data = r->data) {
				q = r; // 第二个位置
				r = q->next; // 第三个位置
			}
			else {
				// 保留首次出现的位置
				q->next = r->next;
				r = q->next;
			}
		}
		p = p->next;
	}
	return head;
}