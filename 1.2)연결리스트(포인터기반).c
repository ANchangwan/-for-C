
#include<stdio.h>//포인터기반 연결리스트
#include<stdlib.h>

typedef struct {

	int* data;
	struct Node* next;




}Node;

Node* head;


int main(void) {

	head = (Node*)malloc(sizeof(Node));
	Node* node1 = (Node*)malloc(sizeof(Node));
	node1->data = 1;
	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->data = 2;
	head->next = node1;
	node1->next = node2;
	node2->next = NULL;
	Node* cur = head->next;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}

	system("pause");
	return 0;


}