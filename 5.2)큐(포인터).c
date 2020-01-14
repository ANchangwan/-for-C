#include <stdio.h>
#include <stdlib.h>
#define INF 9999999


typedef struct {

	int data;
	struct Node* next;

}Node;

typedef struct {

	Node* front;
	Node* rear;
	int count;//ť�� ����ִ� ������ ����


}Queue;

void push(Queue* queue, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) {
		queue->front = node;
	}
	else {
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;

}

void pop(Queue* queue) {

	if (queue->count == 0) {
		printf("����÷ο찡 �߻��߽��ϴ�.");
		return -INF;
	}
	Node* node = queue->front;
	int data = node->data;
	queue->front = node->next;
	free(node);
	queue->count--;
	return data;

}

void show(Queue*queue) {

	Node* cur = queue->front;
	printf("---����Ÿ�� �����Դϴ�.---");
	while (cur != NULL) {
		printf("%d \n", cur->data);
		cur = cur->next;
	}
	printf("---����Ÿ�� �����Դϴ�.---");


}

int main(void) {

	Queue queue;
	queue.front = queue.rear =NULL;
	push(&queue, 8);
	push(&queue, 7);
	pop(&queue);
	push(&queue, 3);
	pop(&queue);
	push(&queue, 1);
	show(&queue);

	system("pause");
	return 0;

}