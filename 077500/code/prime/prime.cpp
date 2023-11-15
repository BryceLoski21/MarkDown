#include <stdio.h>

int prime(int n) {
	if (n <= 1)
		return 0; // 必须输入大于1的整数
	for (int i = 2; i < n; i++) {
		if (n % i == 0) 
			return 0; // 不是质数
	}
	return 1; // 是质数
}

int main() {
	for (int i = 1000; i > 1; i--) {
		if (prime(i))
			printf("%d\n", i);
	}
}