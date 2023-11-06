#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a)<(b)? (a):(b))
#define max(a, b) ((a)>(b)? (a):(b))

int average(int a[], int count) {
	// 去掉最高分，去掉最低分，求平均分
	int min = 0;
	int max = 0;
	int sum = 0;
	for (int i = 0; i < count; i++) {
		min = min(a[i], min); // 取最小值
		max = max(a[i], max); // 取最大值
		sum += a[i];
	}
	return (sum - min - max)/(count-2);
}

int search(int a[], int b) {
	// 寻找相同数，没有返回-1，有则输出下标
	int check = -1; // 标志位
	for (int i = 0; i < 100; i++) {
		if (a[i] == b) {
			printf("下标：%d ", i);
			check = 0;
		}
	}
	if (check == -1)
		printf("没有相同值：%d ", check);
	return check;
}

int main() {
	int a[100];
	for (int i = 0; i < 100; i++) {
		a[i] = i;
	}
	printf("平均分：%d\n", average(a, 100));
	printf("check：%d ", search(a, 49));
}