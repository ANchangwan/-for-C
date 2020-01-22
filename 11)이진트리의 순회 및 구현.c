#include <stdio.h>
#include<stdlib.h>

typedef struct {

	int data;
	struct Node* leftchild;
	struct Node* Rightchild;
}Node;

Node* initNode(int data, Node* leftchild, Node* Rightchild)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftchild = leftchild;
	node->Rightchild = Rightchild;
	return node;

}

void preorder(Node* root) { //������ȸ
	if (root) {
		printf("%d ", root->data);//�ڱ��ڽ��� ���� ����Ѵ�.
		preorder(root->leftchild);//������ �湮�Ѵ�.
		preorder(root->Rightchild);//�������� �湮�Ѵ�.
	}
}
//30-17-5-23-48-37-50


void inorder(Node* root) {//������ȸ
	if (root) {
		inorder(root->leftchild);
		printf("%d ", root->data);
		inorder(root->Rightchild);
	}
}

void postorder(Node* root) {//������ȸ
	if (root) {
		postorder(root->leftchild);
		postorder(root->Rightchild);
		printf("%d ", root->data);
	}
}

int main(void) {

	Node* n7 = initNode(46, NULL, NULL);
	Node* n6 = initNode(16, NULL, NULL);
	Node* n5 = initNode(2, NULL, NULL);
	Node* n4 = initNode(6, NULL, NULL);
	Node* n3 = initNode(11, n6, n7);
	Node* n2 = initNode(89, n4, n5);
	Node* n1 = initNode(23, n2, n3);

	printf("<���� ��ȸ>\n");
	preorder(n1);
	printf("\n");
	printf("\n");
	printf("<���� ��ȸ>\n");
	inorder(n1);
	printf("\n");
	printf("\n");
	printf("<���� ��ȸ>\n");
	postorder(n1);
	printf("\n");
	printf("\n");

	system("pause");
	return 0;

}