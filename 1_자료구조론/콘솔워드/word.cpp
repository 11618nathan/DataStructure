//==============================================================
// �ܼ� ���� ���α׷�
//==============================================================
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//==============================================================
typedef struct node
{
	char word[20];	// ���ڿ� !! 
	struct node * next; 
	struct node * prev; 
}NODE;

NODE * head, *tail;

void insertList(NODE * Where, NODE * newNode)
{
	newNode->next = Where->next;
	newNode->prev = Where;
	Where->next->prev = newNode;
	Where->next = newNode;
}
//==============================================================
void show()
{
	NODE *p;
	printf("[Result] ");
	for (p = head->next; p != tail; p = p->next)
	{
		printf("%s ", p->word);
	}
	puts("");
}

//==============================================================
void  insertWord(char * word)  //insert��ɽ� �ܾ� �߰� !! 
{
	NODE * newNode = (NODE*)malloc(sizeof(NODE)); 
	strcpy(newNode->word, word); // ���ڿ� ���� !! 
	insertList(tail->prev, newNode);

}

//  ����Ʈ �ʱ�ȭ  head->tail  
void init()
{
	head = (NODE*)calloc(1, sizeof(NODE));
	tail = (NODE*)calloc(1, sizeof(NODE));
	head->next = tail;
	head->prev = head;
	tail->prev = head;
	tail->next = tail;
	//  head      tail
	//	[    ] --> [    ]
	//  [    ] <-- [    ]
}
void main()
{
	char cmd[32] = {0}; // ��ɾ� 
	init();
	while (1)
	{ 
		gets_s(cmd); 
		if (strncmp("insert", cmd, 6) == 0)
		{ 
			insertWord(cmd + 7); 
			show();
		}
		else if( )
	}
}