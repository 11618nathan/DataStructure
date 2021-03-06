//==================================================
//  연결리스트  
//==================================================
//	 - 동적인 자료구조 
//	 - 데이타 저장공간이 필요할때마다 그때그때 생성 
//   - 저장될 데이타의 크기를 예측할수 없을 경우 사용 !! 
//    ex) 워드프로세서,  그림판, 등의 에디터 프로그램 
//	 장점 :  크기를 예측할수 없는 데이타를 저장가능 
//			 삽입 삭제가 쉬움.. 
//	 사용예 1)  데이타 저장공간에 제약을 받지 않는다..  
//	 워드 프로세서 : 데이타의 양을 측정이 불가능  -> 
//	 사용예 2) 중간에서의 삽입삭제가 빈번하게 일어나는경우 !! 
//   운영체제의 프로세스 관리 : 프로세시의 생성 소멸을 예측 불가 !
//==================================================
// 용어 :  노드(node) : 데이타 + 링크를 갖는 메모리 블럭 !! 
// [    ] 데이타 :  저장될 값  
// [    ] 링크   :  노드의 포인터 (주소값 ) 
//  해드(head) :  리스트의 시작 노드  
//  테일(tail) : 리스트의 마지막 노드 
//==================================================
//==================================================
// 연결리스트의 종류 !
// 1) 단일 연결리스트 :  노드가 다음노드를 가르키는 링크를 1개 갖고 있는 리스트 !!
//	[  10  ]	    [ 20   ]    [  30  ]
//  [       ] --->  [      ] -->[       ]
// 2) 이중 연결리스트 
//==================================================
//	[  10  ]	    [ 20   ]    [  30  ]
//  [       ] --->  [      ] -->[       ]
//  [       ] <---  [      ] <--[       ]
//==================================================
// 단일 연결리스트 코드 (head, tail 더미노드) 
//==================================================
#include <stdio.h> 
//==================================================
typedef struct node
{
	int data;				 // 데이타 저장소 !! 
	struct node * next; // 다음 노드를 가르키는 포인터 !! 
}NODE;
//==================================================
NODE * head; 
NODE * tail; 
//==================================================
void initList() // 리스트 초기화 
{  // 1) 노드 생성 
	head = (NODE*)malloc(sizeof(NODE)); 
	tail = (NODE*)malloc(sizeof(NODE)); 
  // 링크 연결 !! 
	head->next = tail; 
	tail->next = NULL;	// tail; 

}
//===================================================
//  find :  검색함수구현 ..
//  매개변수 : key값 !! 
//	리턴 :  key값에 해당하는 노드의 포인터를 리턴 !! 
//===================================================
NODE * find( int key )
{	
	NODE * p = head->next;  // 

	// 연결스트의 처음에서부터 마지막까지 순회하는 코드 !! 
	while (p != tail)
	{ 
		if (p->data == key)
			return p; // 노드의 포인터를 리턴 !! 
		else 
			p = p->next;
	}
	return NULL;
}


// 단일 연결리스트의 삽입 연산 !! 
void insert( NODE * where  ,  int value ) // 중간에 삽입 !! 
{ // 1) 노드 생성 !! 
	NODE * newNode = (NODE*)malloc(sizeof(NODE)); 
	newNode->data = value; 
	//2) 링크 변경  
	newNode->next = where->next;
	where->next = newNode;
}
void push_front(int value )  // 리스트의 맨앞에 삽입 
{

}
void push_back(int value ) // 리스트의 맨뒤에 삽입 
{
}
// 단일 연결리스트의 삭제 연산 !! 

void erase(int key) //key에 해당하는 노드를 삭제 !! 
{
	NODE * p = head->next; 
	NODE * s = head;
	while (p != tail)
	{
		if (p->data == key) //  찾았다 !! 
		{
			s->next = p->next;
			free(p);
			return;
		}
		else
		{
			s = p;
			p = p->next;
		}
	}
}



void show()
{
	NODE * p = head->next;  // head다음 노드부터 
	while (p != tail)	// tail앞의 노드 까지...
	{	
		printf(" %d -->", p->data);
		p = p->next;		// 다음 노드로 이동 !! 
	}
	puts("");
}


void main()
{
	initList();
	insert(head, 10);
	show();
	
	insert( find(10) , 20 );
	show();

	NODE * Where = find(10); 
	if (Where != NULL)
	{
		insert(Where, 30);
		show();
	}
}