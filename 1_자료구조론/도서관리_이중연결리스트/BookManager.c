#include <stdio.h>
#include <malloc.h> 
//===================================================
// ����ü ���� 
//===================================================
typedef struct book
{
	char title[256];		// ���� 
	char writer[20];	    // ���� 
}BOOK;
//===================================================
typedef struct node
{
	BOOK bookinfo; 
	struct node * next; 
	struct node * prev;
}NODE;
//===================================================
// ���� ���� ���� !! 
NODE * head, *tail;
//===================================================
// �Լ� ����� !! 
//===================================================
void init();	//  ����Ʈ �ʱ�ȭ  head->tail   
void BookInput(); // ���� �Է� !! 
void BookShow();	// ���� ��� 
//===================================================
void main()
{
	int input = 0; 
	init(); // head,  tail �ʱ�ȭ !! 
	while (1)
	{
		puts(" �������� ���α׷�  v 1.0 ");
		puts("1. ���� �Է�");
		puts("2. ���� ���"); 
		puts("0. ����"); 
		scanf("%d", &input);

		switch (input)
		{
		case 1:  BookInput();      break;
		case 2:  BookShow();   	break;
		case 3:  exit(0);             break;
		}
	}

}

// ���� �Է� �Լ� 
void BookInput( )
{
	NODE * newNode = (NODE*)malloc(sizeof(NODE)); 
	// ���� ���� �Է� !! 
	getchar();
	printf("���� �̸� :");
	gets(newNode->bookinfo.title); 
	printf("���� : ");
	gets(newNode->bookinfo.writer); 
	// �Ǿտ� �����ϰ� ����...  
	newNode->next = head->next;
	newNode->prev = head;
	head->next->prev = newNode;
	head->next = newNode; 
	// �ǵڿ� ���� !! 
/*	newNode->prev = tail->prev;
	newNode->next = tail;
	tail->prev->next = newNode;
	tail->prev = newNode; 
*/
}
// ���� ��ü ��� �Լ� !! 
void BookShow()
{
	NODE * p = head->next; 
	while (p != tail)
	{
		printf("���� : %s  ���� : %s\n", p->bookinfo.title, 
											p->bookinfo.writer);
		p = p->next;
	}
}
//  ����Ʈ �ʱ�ȭ  head->tail  
void init()
{
	head = (NODE*)calloc(1, sizeof(NODE)); 
	tail  = (NODE*)calloc(1, sizeof(NODE));
	head->next = tail;
	head->prev = head; 
	tail->prev = head;
	tail->next = tail;	
	//  head      tail
	//	[    ] --> [    ]
	//  [    ] <-- [    ]
}