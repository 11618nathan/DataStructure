//=================================================
//  ���� ���Ḯ��Ʈ ( Double Linked List)
//=================================================
//	->  ���� ���Ḯ��Ʈ�� ���� ��忡 ���� �����͸��� ���´� !! (���⼺) 
//	->  ���� ����� ��ũ --> next 
//	->  ���� ����� ��ũ --> prev 
//  ->  ����⼺  -->  ������  :  ������ !!   
//	->  ���� ���� ���Ǵ� ���Ḯ��Ʈ�� ���� !! 
//================================================= 
/*
	[����Ÿ]     [����Ÿ]    [����Ÿ]     [����Ÿ]
	[      ] -->[      ] -->[      ] -->[      ] 
	[      ] <--[      ] <--[      ] <--[      ]
*/
//=================================================
//  ���� ���� ����Ʈ ��� !! 
/*
	struct Node 
	{
		int data; 
		Node * next; 
		Node * prev;	
	}
*/
//=================================================
#include <stdio.h> 
#include <malloc.h> 
#include <stdlib.h>	


//=================================================
//  ���� ����Ʈ ���� ( head,  tail ���� ��� ������� ���� )
//=================================================
typedef struct node
{
	int data; 
	struct node * next;	 // ���� ��� 
	struct node * prev; // ���� ��� 
}NODE;
//=================================================
// head , tail ������ ���� ���� !! 
NODE * head = NULL; 
NODE * tail   = NULL;	

void insert(NODE * Where, int value);

//=================================================
//  ����Ʈ �ʱ�ȭ !! 
//=================================================
void init()
{	// ��� ���� !! 
	head = (NODE*)malloc(sizeof(NODE));
	tail = (NODE*)malloc(sizeof(NODE)); 
	// ��ũ ���� !! 
	head->next = tail;
	head->prev = head; 
	tail->prev = head; 
	tail->next = tail;
}
//=================================================
// ����Ʈ ���� �Լ� !! 
//=================================================
void push_front( int value) //  ����Ʈ�� �Ǿտ� ���� !! 
{
	insert(head, value);
}
void push_back(int value) // ����Ʈ�� �ǵڿ� ���� !! 
{
	insert(tail->prev, value);
} 
void insert(NODE * Where, int value) // Where��� �ڿ� value�� ����  
{
	NODE * newNode = (NODE*)malloc(sizeof(NODE)); // ��� ���� !
	newNode->data = value; 
	// ��ũ���� !! 
	newNode->next = Where->next; 
	newNode->prev = Where; 
	Where->next->prev = newNode; 
	Where->next = newNode;

}
//=================================================
// ����Ʈ ���� �Լ� !! 
//=================================================
void erase(NODE * Where) //  �߰����� ���� !! 
{
	// ��ũ ����!! 
	Where->next->prev = Where->prev;
	Where->prev->next = Where->next;
	free(Where); // ��� ���� 
}
void pop_front() // �տ��� ���� !! 
{
	if(head->next != tail)
		erase(head->next);
}
void pop_back() // �ڿ��� ���� !! 
{
	if (tail->prev != head)
		erase(tail->prev);
} 


void show()
{
	NODE * p = head->next;  // head���� ������ 
	while (p != tail)	// tail���� ��� ����...
	{
		printf(" %d -->", p->data);
		p = p->next;		// ���� ���� �̵� !! 
	}
	puts("");
}
//===================================================
//  find :  �˻��Լ����� ..
//  �Ű����� : key�� !! 
//	���� :  key���� �ش��ϴ� ����� �����͸� ���� !! 
//===================================================
NODE * find(int key)
{
	NODE * p = head->next;  // 

							// ���ὺƮ�� ó���������� ���������� ��ȸ�ϴ� �ڵ� !! 
	while (p != tail)
	{
		if (p->data == key)
			return p; // ����� �����͸� ���� !! 
		else
			p = p->next;
	}
	return NULL;
}


void main() 
{
	init(); 
	push_back(10);
	show();
	push_back(20);
	show();
	push_back(30);
	show();
	push_front(40);
	show();
	insert( find(20), 4885  ); 
	show();
	erase(find(4885));
	show();
	pop_front();
	show();
	pop_back();
	show();
}