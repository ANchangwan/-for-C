#include <stdio.h>
#define SIZE 10000
#define INF 9999999

int queue[SIZE];
int front = 0;
int rear = 0;

void push(int data) {

	if (rear >= SIZE)
	{
		printf("큐 오버플로우가 발생했습니다.\n");
		return;
	}
	queue[rear++] = data;

}

int pop() {

	if (front == rear) {
		printf("언더플로우가 발생했습니다.\n");
		return -INF;//반드시 반환해야한다.
	}
	return queue[front++];
}

void show() {
	printf("----큐의 앞부분----\n");
	for (int i = front; i < rear; i++) {
		printf("%d \n", queue[i]);
	}
	printf("----큐의 뒷부분----\n");


}
int main(void) {

	 ;
	push(5);
	push(4);
	pop();
	push(6);
	pop();
	show();

	system("pause");
	return 0;
}