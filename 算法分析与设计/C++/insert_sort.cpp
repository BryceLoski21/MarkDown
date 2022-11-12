#include <stdio.h>
#include <iostream>
#include<stdlib.h>
using namespace std;

void insert_sort(int a[], int n){
	//插入排序
	for(int i = 1; i < n; i++){
		int cur = a[i];
		int p_i = i - 1;
		while(p_i >= 0 && a[p_i] > cur){
			a[p_i + 1] = a[p_i];
			p_i--;
		}
		a[p_i + 1] = cur;
	}
}

void shell_sort(int a[], int n){
    //希尔排序
	int gap = n / 2;
	while(gap){
		for(int i = gap; i < n; i += gap){
			int cur = a[i];
			int pre_i = i - gap;
			while(pre_i >= 0 && a[pre_i] > cur){
				a[pre_i + gap] = a[pre_i];
				pre_i -= gap;
			}
			a[pre_i + gap] = cur;
		}
		gap /= 2;
	}
}


int main(){
	int a[8] = { 5, 3, 6, 4, 1, 2, 8, 7 };
	insert_sort(a, 8);
	for (int i = 0; i < 8; i++){
		printf("%d ", a[i]);
	}
	system("pause");
	printf("\n");
	int b[8] = { 5, 3, 6, 4, 1, 2, 8, 7 };
	shell_sort(b, 8);
	for (int i = 0; i < 8; i++){
		printf("%d ", b[i]);
	}
	system("pause");
	printf("\n");
	return 0;
}