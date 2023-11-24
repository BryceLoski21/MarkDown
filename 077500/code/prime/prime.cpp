#include <stdio.h>

int prime(int n) {
	if (n <= 1) // �����������1������
		return 0; 
	for (int i = 2; i < n; i++) {
		if (n % i == 0) 
			return 0; // ��������
	}
	return 1; // ������
}

int main() {
	int count = 0; // ��־λ��ÿ�����10��
	for (int i = 1000; i > 1; i--) {
		if (prime(i)) {
			printf("%d ", i);
			count += 1;
		}
		if (count == 10) {
			printf("\n");
			count = 0;
		}
	}
}