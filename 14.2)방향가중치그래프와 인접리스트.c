#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int index;
	int distance;
	struct Node* next;

}Node;

void addFront(Node* root, int index, int distance) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->distance = distance;
	node->next = root->next;
	root->next = node;

}
void showAll(Node* root) {
	Node* cur = root->next;
	while (cur != NULL) {
		printf(" %d (거리: %d)", cur->index, cur->distance);
		cur = cur->next;
	}
}
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	Node** a = (Node**)malloc(sizeof(Node*) * (n + 1));// 각 인덱스가 1부터 출발한다는 가정
	for (int i = 0; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;//기본적인 루트는 널값
	}
	for (int i = 0; i < m; i++) {
		int x, y, distance;
		scanf("%d %d %d", &x, &y, &distance);
		addFront(a[x], y, distance);
	}
	for (int i = 0; i <= n; i++) {
		printf("원소[%d]", i);
		showAll(a[i]);
		printf("\n");
	}
	system("pause");
	return 0;

}