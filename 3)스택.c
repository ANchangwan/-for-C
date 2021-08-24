#include<stdio.h>
#define  SIZE 1000
#define INF 999999

int stack[SIZE];
int top = -1;

int push(int data) {

	if (top == SIZE - 1) {
		printf("-- 스택오버플로러입니다.--");
		return;
	}
	stack[++top] = data;
}

int pop() {

	if (top == -1)
	{
		printf("스택이 비워있습니다.\n");
		return -INF;

	}
	return stack[top--];
}

void show() {

	printf("---- 최상단입니다.----\n");
	for (int i = top; i >= 0; i--) {

		printf("%d \n", stack[i]);
	}
	printf("----최하단입니다.\n");
	printf("\n");

}

int main(void) {
	
	push(1);
	push(2);
	push(3);
	pop();
	show();
	
	system("pause");
	return 0;
	
}
//배열을 이용하면 메모리 용량이 비효율적으로 사용 될 수 있다.
//
