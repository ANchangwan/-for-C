#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int data;
	struct Node* next;



}Node;

Node* head;


void addfront(Node* root, int data) {//��� �߰�
	Node* node = (Node*)malloc(sizeof(Node));//�߰��� ��� ����
	node->data = data;
	node->next = root->next;//head�� ����Ű�� ���(=node1)
	root->next = node;//�߰��� ���
}


void add_delet(Node* root) {

	Node* front = root->next;//node1�� ����
	root->next = front->next;//node1�� �������� node2�� ����
	free(front);//node1�� ������ �Ҵ�����
}


void freeAll(Node* root) {
	Node* cur = head->next;//head�� next
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
		cur = cur->next;//���� ��带 ����Ų��.

	}
}





int main(void) {

	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	addfront(head, 2);
	addfront(head, 5);
	addfront(head, 1);
	addfront(head, 7);
	add_delet(head);
	showAll(head);
	freeAll(head);

	system("pause");
	return 0;

}