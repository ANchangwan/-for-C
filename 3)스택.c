#include<stdio.h>
#define  SIZE 1000
#define INF 999999

int stack[SIZE];
int top = -1;

int push(int data) {

	if (top == SIZE - 1) {
		printf("-- ���������÷η��Դϴ�.--");
		return;
	}
	stack[++top] = data;



}

int pop() {

	if (top == -1)
	{
		printf("������ ����ֽ��ϴ�.\n");
		return -INF;

	}
	return stack[top--];



}

void show() {

	printf("---- �ֻ���Դϴ�.----\n");
	for (int i = top; i >= 0; i--) {

		printf("%d \n", stack[i]);
	}
	printf("----���ϴ��Դϴ�.\n");
	printf("\n");

}

int main(void) {

	

	

	system("pause");
	return 0;





}
//�迭�� �̿��ϸ� �޸� �뷮�� ��ȿ�������� ��� �� �� �ִ�.
//