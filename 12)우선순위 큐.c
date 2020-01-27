#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10000

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

typedef struct {

	int heap[MAX_SIZE];
	int count;
}prioirtyQueue;

void push(prioirtyQueue* pq, int data)
{
	if (pq->count >= MAX_SIZE)
		return;
	pq->heap[pq->count] = data;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	while (now > 0 && pq->heap[now] > pq->heap[parent])
	{
		swap(&pq->heap[now], &pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

int pop(prioirtyQueue *pq)
{
	if (pq->count <= 0) return -9999;
	int res = pq->heap[0];//������ ���
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];//���� ��Ʈ ��带 �־��ش�.
	int now = 0, leftchild = 1, rightchild = 2;
	int target = now;//�ٲٰ����ϴ� �ڽĳ��
	while (leftchild < pq->count) {//���Ұ� �����Ҷ����� �ݺ�
		if (pq->heap[target] < pq->heap[leftchild])
			target = leftchild;
		if (pq->heap[target] < pq->heap[rightchild] && rightchild < pq->count)//�ε����� ���� �ʱ� ���� rightchild<pq->count�� ����
			target = rightchild;
		if (target == now)
			break;
		else {
			swap(&pq->heap[now], &pq->heap[target]);
			int now = target;
			leftchild = now * 2 + 1;
			rightchild = now * 2 + 2;
		}
	}
	return res;
}
int main(void) {
	int n, data;
	scanf("%d", &n);
	prioirtyQueue pq;
	pq.count = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		push(&pq, data);
	}
	for (int i = 0; i < n; i++) {
		int data = pop(&pq);
		printf("%d ", data);
	}
	system("pause");
	return 0;
}