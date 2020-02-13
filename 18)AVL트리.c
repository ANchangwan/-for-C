#include<stdio.h>
#include<stdlib.h>

int getmax(int a, int b) {
	if (a > b) return a;

	return b;
}

typedef struct {

	int data;
	int height;//높이 저장해야 시간복잡도를 보장할 수 있음
	struct Node* leftchild;
	struct Node* rightchild;


}Node;

int getHeight(Node* node) {

	if (node == NULL) return 0;

	return node->height;
}

void setheight(Node* node) {

	node->height = getmax(getHeight(node->leftchild), getHeight(node->rightchild)) + 1;
}

int getDifference(Node* node) {
	if (node == NULL) return 0;
	Node* leftchild = node->leftchild;
	Node* rightchild = node ->rightchild;
	return getHeight(leftchild) - getHeight(rightchild);
}

Node* rotateLL(Node* node) {
	Node* leftchild = node->leftchild;
	node->leftchild = node->rightchild;
	leftchild->rightchild = node;
	setHeight(node); //회전 이후에 높이를 다시 계산
	return leftchild; //leftchild는 이후에 setheight() 수행

}

Node* rotateRR(Node* node) {
	Node* rightchild = node->rightchild;
	node->rightchild = node->leftchild;
	rightchild->leftchild = node;
	setHeight(node); //회전 이후에 높이를 다시 계산
	return rightchild; //leftchild는 이후에 setheight() 수행

}

Node* rotateLR(Node* node) {
	Node* leftchild = node->leftchild;
	node->leftchild = rotateRR(leftchild);
	setHeight(node->leftchild);
	return rotateLL(node);
	
}
Node* rotateRL(Node* node) {
	Node* rightchild = node->rightchild;
	node->rightchild = rotateLL(rightchild);
	setHeight(node->leftchild);
	return rotateRR(node);

}

Node* balance(Node* node) {
	int difference = getDifference(node);
	if (difference >= 2) {
		if (getDifference(node->leftchild) >= 1) {
			node = rotateLL(node);
		}
		else {
			node = rotateLR(node);
		}
	}
	else if (difference <= -2) {
		if (getDifference(node->rightchild) <= -1) {
			node = rotateRR(node);
		}
		else {
			node = rotateRL(node);
		}
	}
	setheight(node);
	return node;
}

Node* insertNode(Node* node, int data) {
	if (!node) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->height = 1;
		node->leftchild = node->rightchild = NULL;
	}
	else if (data < node->data) {
		node->leftchild = insertNode(node->leftchild, data);
		node = balance(node);
	}
	else if (data > node->data) {
		node->rightchild = insertNode(node->rightchild, data);
		node = balance(node);
	}
	else {
		printf("데이터 중복이 발생했습니다\n");
	}
	return node;

}

Node* root = NULL;

void display(Node* node, int level) {
	if (node != NULL) {
		display(node->rightchild, level + 1);
		printf("\n");
		if (node == root) {
			printf("Root: ");
		}
		for (int i = 0; i < level && node != root; i++) {
			printf("     ");

		}
	}
	printf("%d(%d)", node->data, getHeight(node));
	display(node->leftchild, level + 1);
}

int main(void) {

	root = insertNode(root, 7);
	root = insertNode(root, 6);
	root = insertNode(root, 5);
	root = insertNode(root, 3);
	root = insertNode(root, 1);
	root = insertNode(root, 9);
	root = insertNode(root, 8);
	root = insertNode(root, 12);
	root = insertNode(root, 16);
	root = insertNode(root, 18);
	root = insertNode(root, 23);
	root = insertNode(root, 21);
	root = insertNode(root, 14);
	root = insertNode(root, 15);
	root = insertNode(root, 16);
	root = insertNode(root, 20);
	display(root, 1);
	printf("\n");
	system("pause");


}