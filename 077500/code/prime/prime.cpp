#include <stdio.h>

int prime(int n) {
	if (n <= 1)
		return 0; // �����������1������
	for (int i = 2; i < n; i++) {
		if (n % i == 0) 
			return 0; // ��������
	}
	return 1; // ������
}

int main() {
	for (int i = 1000; i > 1; i--) {
		if (prime(i))
			printf("%d\n", i);
	}
}