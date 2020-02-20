#define _CRT_SECURE_NO_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 20001
#define EDGE_MAX 600001 //양방향 간선이므로 300.000개

typedef struct {

	int cost;
	int node;

}Edge;


void swap(Edge* a, Edge* b) {
	Edge temp;

	temp.cost = a->cost;
	temp.node = a->node;
	a->cost = b->cost;
	a->node = b->node;
	b->cost = temp.cost;
	b->node = temp.node;

}

typedef struct {
	Edge *heap[EDGE_MAX];
	int count;
}priorityQueue;

void push(priorityQueue *pq, Edge *edge) {
	if (pq->count >= EDGE_MAX) return;
	pq->heap[pq->count] = edge;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	while (now > 0 && pq->heap[now] < pq->heap[parent]) {
		swap(pq->heap[now], pq->heap[parent]);
		int now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

Edge* pop(priorityQueue* pq) {

	if (pq->count <= 0) return NULL;
	Edge* res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq -> count];
	int now = 0, leftchild = 1, rightchild = 2;
	int target = now;
	while (leftchild < pq->count) {
		if (pq->heap[target]->cost > pq->heap[leftchild]->cost) target = leftchild;
		if (pq->heap[target]->cost < pq->heap[rightchild]->cost && rightchild < pq->count) target = rightchild;
		if (target == now) break;
		else {

			swap(pq->heap[now], pq->heap[target]);
			now = target;
			leftchild = now * 2 + 1;
			rightchild = now * 2 + 2;

		}
	}
	return res;


}

typedef struct {
	Edge* data;
	struct Node* next;
}Node;

Node** adj;
int ans[NODE_MAX];//특정한 노드의 거리값

void addnode(Node** target, int index, Edge* edge) {
	if (target[index] == NULL) {
		target[index] = (Node*)malloc(sizeof(Node));
		target[index]->data = edge;
		target[index]->next = NULL;
	}
	else {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = edge;
		node->next = target[index];
		target[index] = node;
	}
}

int main(void) {

	int n, m, k;//k 출발하는 노드
	scanf("%d %d %d", &n, &m, &k);
	adj = (Node**)malloc(sizeof(Node) * (n + 1));
	for (int i = 0; i < n; i++) {
		adj[i] = NULL;
		ans[i] = INT_MAX;//갈수 있는 노드는 무한
	}
	priorityQueue* pq;
	pq = (priorityQueue*)malloc(sizeof(priorityQueue));//간선의 대한 정보를 담는 공간
	pq->count = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);//a=시작부분,b=다음 노드,c=간선 길이
		Edge* edge = (Edge*)malloc(sizeof(Edge));
		edge->node = b;
		edge->cost = c;
		addNode(adj, a, edge);//a번째 인덱스에 원소를 b를 추가

	}
	//다익스트라 알고리즘을 시작합니다.

	ans[k] = 0;//출발하고자하는 노드
	Edge* start = (Edge*)malloc(sizeof(Edge));
	start->cost = 0; start->node = k; push(pq, start);//출발하는 간선 정보를 삽입
	while (1) {
		Edge* now = pop(pq);//원소를 추출하면서 꺼낸다
		if (now == NULL) break;
		int curNode = now->node;//꺼낸 노드 정보
		int curCost = now->cost;// 꺼낸 노드 비용
		if (ans[curNode] < curCost) continue;//무시
		Node* cur = adj[curNode];
		while (cur != NULL) {
			Edge* temp = cur->data;
			temp->cost += curCost;
			if (temp->cost < ans[temp->node]) {
				ans[temp->node] = temp->cost; push(pq, temp);//테이블 갱신 부분
			}
			cur = cur->next;

		}
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == INT_MAX)
			printf("INF\n");
		else printf("%d\n", ans[i]);
	}
	system("pause");
	return 0;

}