#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

void RadixSort(int* a, int n)
{
	int res[MAX], MAX_VELUE = 0;
	int exp = 1;//일의 자릿수부터 구하는 공식
	for (int i = 0; i < n; i++) {
		if (a[i] > MAX_VELUE)
			MAX_VELUE = a[i];//가장큰값을 구하는 이유는 가장 큰값의 자릿수를 구하기 위해서
	}
	while (MAX_VELUE / exp > 0) {//1의 자리부터 계산
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
		{
			bucket[a[i] / exp % 10]++;//자릿수 배열 처리

		}
		for (int i = 1; i < 10;i++)
		{
			bucket[i] += bucket[i - 1];//누적계산
		}
		for (int i = n - 1; i >= 0; i--) {//같은 자릿수 끼리는 순서를 유지
			res[--bucket[a[i] / exp % 10]] = a[i];
		}
		for (int i = 0; i < n; i++) //기본 배열 갱신
			a[i] = res[i];
		
		exp *= 10;
	}
}

int main(void) {

	int a[MAX];
	int i, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	RadixSort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("\n");
	system("pause");
	return 0;
	


}