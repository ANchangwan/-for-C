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

	int n, min, index;//�ѹ� �˻��Ҷ����� �߰ߵǴ� ������
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {//������ ����
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		min = INT_MAX;// ���� ū��
		for (int j = i; j < n; j++) {
			if (min > a[j]) {// a[j]�� ���� min�� ������ ���� ���
				min = a[j];
				index = j;//���� �������� ��ġ
			}
		}
		swap(&a[i], &a[index]);// �� ��ġ�� �ٲ��ش�.
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}