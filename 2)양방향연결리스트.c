#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int data;
	struct Node* prev;
	struct Node* next;



}Node;

Node* head, *tail;

int insert(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	Node* cur;
	cur = head->next;
	while (cur->data < data && cur != NULL) {

		cur = cur->next;

	}

	Node* prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	cur->prev = node;
	node->next = cur;




}