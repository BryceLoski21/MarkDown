#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a)<(b)? (a):(b))
#define max(a, b) ((a)>(b)? (a):(b))

int average(int a[], int count) {
	// ȥ����߷֣�ȥ����ͷ֣���ƽ����
	int min = 0;
	int max = 0;
	int sum = 0;
	for (int i = 0; i < count; i++) {
		min = min(a[i], min); // ȡ��Сֵ
		max = max(a[i], max); // ȡ���ֵ
		sum += a[i];
	}
	return (sum - min - max)/(count-2);
}

int search(int a[], int b) {
	// Ѱ����ͬ����û�з���-1����������±�
	int check = -1; // ��־λ
	for (int i = 0; i < 100; i++) {
		if (a[i] == b) {
			printf("�±꣺%d ", i);
			check = 0;
		}
	}
	if (check == -1)
		printf("û����ֵͬ��%d ", check);
	return check;
}

int main() {
	int a[100];
	for (int i = 0; i < 100; i++) {
		a[i] = i;
	}
	printf("ƽ���֣�%d\n", average(a, 100));
	printf("check��%d ", search(a, 49));
}