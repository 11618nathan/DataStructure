//==============================================================
//  stack ( ����) 
//	 - ���߿� ���� ����Ÿ�� ���� ������ ����  (Last In First Out) 
//	 - ���� ���� ����Ÿ�� ���߿� �����±���  
//	 - �Ա��� 1������ ���������θ� ���� ������ ����  
//	 ex)  �ý� ������, źâ 
//
//==============================================================
// ������ ���� (�迭) 
//==============================================================
#include <stdio.h> 
#define MAX 3

int stack_array[MAX];
int top = -1;         
// ���ÿ� ���� ���� !! 
void push(int data)
{
	if (top >= MAX - 1)
		puts("stack overflow !!");
	else
		stack_array[++top] = data;
}
void pop()
{
	if (top <= -1)
		puts("stack underflow!!");
	else

		top--;
}

void main()
{
	push(10); 
	printf("top : %d \n", stack_array[top]);
	push(20);
	printf("top : %d \n", stack_array[top]);
	push(30);
	printf("top : %d \n", stack_array[top]);
	push(40);
	printf("top : %d \n", stack_array[top]);
	pop();
	printf("top : %d \n", stack_array[top]);
	pop();
	printf("top : %d \n", stack_array[top]);
	pop();
	printf("top : %d \n", stack_array[top]);
	pop();
	printf("top : %d \n", stack_array[top]);

}