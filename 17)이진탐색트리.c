#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node* leftchild;
	struct Node* rightchild;
}Node;

Node* insertNode(Node* root, int data) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->leftchild = root->rightchild = NULL;
		root->data = data;
		return root;
	}
	else {
		if (root->data > data) {
			root->leftchild = insertNode(root->leftchild, data);
		}
		else {
			root->rightchild = insertNode(root->rightchild, data);
		}
	}
	return root;
}

Node* searchNode(Node* root, int data) {
	if (root == NULL) return NULL;
	if (root->data == data) return root;
	else if (root->data > data) return searchNode(root->leftchild, data);
	else return searchNode(root->rightchild, data);
}

void preorder(Node* root) {
	if (root == NULL) return;
	printf("%d ", root->data);
	preorder(root->leftchild);
	preorder(root->rightchild);
}

Node* deleteNode(Node* root, int data) {
	Node* node = NULL;
	if (root == NULL) return NULL;
	if (root->data > data) root->leftchild = deleteNode(root->leftchild, data);
	else if (root->data < data) root->rightchild = deleteNode(root->rightchild, data);
	else {
		if (root->leftchild != NULL && root->rightchild != NULL) {
			node = findeMinNode(root->rightchild);
			root->data = node->data;
			root->rightchild = deleteNode(root->rightchild, node->data);
		}
		else {
			node = (root->leftchild != NULL) ? root->leftchild : root->rightchild;
			free(root);
			return node;
		}
	}
}


int main(void) {
	Node* root = NULL;
	root = insertNode(root, 30);
	root = insertNode(root, 17);
	root = insertNode(root, 48);
	root = insertNode(root, 5);
	root = insertNode(root, 23);
	root = insertNode(root, 37);
	root = insertNode(root, 50);
	preorder(root);
	printf("\n"); 
	system("pause");
	return 0;

}

Node* findeMinNode(Node* root) {
	Node* node = root;
	while (node->leftchild != NULL) {
		node = node->leftchild;
	}
	return node;
}