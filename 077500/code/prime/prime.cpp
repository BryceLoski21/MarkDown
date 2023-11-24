#include <stdio.h>

int prime(int n) {
	if (n <= 1) // 必须输入大于1的整数
		return 0; 
	for (int i = 2; i < n; i++) {
		if (n % i == 0) 
			return 0; // 不是质数
	}
	return 1; // 是质数
}

int main() {
	int count = 0; // 标志位，每行输出10个
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