#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[1001][1001];
int n, m;//n=노드,m=간선

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {//간선의 갯수만큼 증가
		int x, y;
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
		map[y][x] = 1;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;

}