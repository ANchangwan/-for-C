#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define SIZE 1000


int a[SIZE];


int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {

	int n, min, index;//한번 검색할때마다 발견되는 작은값
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {//원소의 갯수
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		min = INT_MAX;// 가장 큰값
		for (int j = i; j < n; j++) {
			if (min > a[j]) {// a[j]의 값이 min의 값보다 작을 경우
				min = a[j];
				index = j;//가장 작은값의 위치
			}
		}
		swap(&a[i], &a[index]);// 두 위치를 바꿔준다.
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}