#include<stdio.h>
#define INF 1000

int arr[INF];
int count = 0;



int addback(int data) {

	arr[count] = data;
	count++;

}

int addfirst(int data) {

	for (int i = count; i >= 1; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = data;
	count++;


}

void show() {

	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}

}


int main(void) {


	addfirst(5);
	addfirst(8);
	addfirst(9);
	addback(3);
	addback(2); 
	addback(4);
	show();

	system("pause");
	return 0;




}