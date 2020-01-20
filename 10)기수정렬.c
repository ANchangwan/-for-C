#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

void RadixSort(int* a, int n)
{
	int res[MAX], MAX_VELUE = 0;
	int exp = 1;//���� �ڸ������� ���ϴ� ����
	for (int i = 0; i < n; i++) {
		if (a[i] > MAX_VELUE)
			MAX_VELUE = a[i];//����ū���� ���ϴ� ������ ���� ū���� �ڸ����� ���ϱ� ���ؼ�
	}
	while (MAX_VELUE / exp > 0) {//1�� �ڸ����� ���
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
		{
			bucket[a[i] / exp % 10]++;//�ڸ��� �迭 ó��

		}
		for (int i = 1; i < 10;i++)
		{
			bucket[i] += bucket[i - 1];//�������
		}
		for (int i = n - 1; i >= 0; i--) {//���� �ڸ��� ������ ������ ����
			res[--bucket[a[i] / exp % 10]] = a[i];
		}
		for (int i = 0; i < n; i++) //�⺻ �迭 ����
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