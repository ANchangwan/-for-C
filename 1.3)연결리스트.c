#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int data;
	struct Node* next;



}Node;

Node* head;


void addfront(Node* root, int data) {//노드 추가
	Node* node = (Node*)malloc(sizeof(Node));//추가할 노드 공간
	node->data = data;
	node->next = root->next;//head가 가리키는 노드(=node1)
	root->next = node;//추가한 노드
}

void addrear(Node*root, int data){// 맨 뒤쪽 노드 추가
	Node* node = (Node*)malloc(sizeof(Node));//추가할 노드 공간
	node->data = data;
	Node*cur = root->next;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = node;
	node->next = NULL;
}


void add_delet(Node* root) {

	Node* front = root->next;//node1을 저장
	root->next = front->next;//node1의 다음공간 node2를 저장
	free(front);//node1의 공간을 할당해제
}


void freeAll(Node* root) {
	Node* cur = head->next;//head의 next
	while (cur != NULL) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
}

void showAll(Node* root) {
	Node* cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;//다음 노드를 가리킨다.

	}
}





int main(void) {

	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	addfront(head, 2);
	addfront(head, 5);
	addfront(head, 1);
	addfront(head, 7);
	addrear(head, 8);
	add_delet(head);
	showAll(head);
	freeAll(head);

	system("pause");
	return 0;

}
