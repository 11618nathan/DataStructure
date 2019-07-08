//=======================================================
// Queue (ť) :  ��⿭ !! 
// -> ���� �� ����Ÿ ���� �����±��� ( First In First Out) 
// ->  �������� ó���� �ϱ����� ��� !! 
//   EX) ����, �Ĵ� ��ȣǥ 
//=======================================================
// �迭�� �̿��� ť�� ���� !! 
#include <stdio.h>
#define MAX 5
/* 
int front = -1, rear = -1;

int Queue[MAX]; 
 �Ϲ����� �迭�� �̿��� ť�� ���� !! 
//	-->  �ѹ� ����Ÿ�� �����ϸ� �ٽ� ���� ����... �Ф� 
//  -->  �迭�� �̿��Ѵٸ� ����ť�� ����Ѵ� !! 
// Queue ���� 
void push(int data)
{
	if (rear >= MAX)
	{
		puts("Queue Overflow!!");
		return;
	}
	Queue[++rear] = data; 
}
void pop()
{
	if (front == rear)
	{
		puts("Queue underflow!!"); 
		return;
	}
	front++;

}
*/
// ����..  �迭�� �̿���  ���� ť�� ���� !! 
int Queue[MAX];

int front = 0, rear = 0; 

void push(int data)
{
	if ((rear + 1) % MAX == front)
		return;
	Queue[rear] = data; 
	rear = (rear + 1) % MAX;
}

int pop()
{
	int data;
	if (front == rear)
		return -1; 
	data = Queue[front];
	front = (front + 1) % MAX;
	return data;
}

void main()
{ 
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear );
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);
	push(60);
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);
	
}
