#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* Expurgate(Node* head) {
	// �޳��ظ�Ԫ��
	Node* p, * q, * r;
	p = head;
	while (p) {
		q = p; // ��һ��λ��
		r = q->next; // �ڶ���λ��
		while (r) {
			if (p->data = r->data) {
				q = r; // �ڶ���λ��
				r = q->next; // ������λ��
			}
			else {
				// �����״γ��ֵ�λ��
				q->next = r->next;
				r = q->next;
			}
		}
		p = p->next;
	}
	return head;
}