#include <stdio.h>
#include <stdlib.h>

typedef struct {
	
	int *data;
	struct Node *next;
	struct Node* prev;


}Node;

Node* head,*tail;


void insert(int data) {//오름차순 출력 및 양방향연결리스트
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
void removeFront() { // 첫번째 노드 삭제
	Node* node = head->next;
	head->next = node->next;
	Node* next = node->next;
	node->prev = head;
	free(node);
}

void show() { //출력함수
	Node* cur = head->next;
	while (cur != tail) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");



}


int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
	insert(5);
	insert(4);
	insert(3);
	insert(9);
	insert(15);
	delet();
	show();

	system("pause");
	return 0;
	









}
