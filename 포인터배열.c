//==================================================
//  ������ �迭 : �迭�� ���ҷ� �����͸� ���� �迭 !! 
//================================================== 
// 1) �����迭 :  ũ�� ���� !! 
// 2) �����迭 : �Ҵ�� ���Ҵ�ÿ� �ӵ����� ( �����ս� )  
// 3) ������ �迭 :  ���� +  ���� �� �������� ���ϴ� �迭 !! 
//==================================================
//		[	][	][	][	][	] 
//		  |	
//		[   ]
//		[   ]
//==================================================
//   C����� ������ �迭 == JAVA����� ��ü �迭 
//==================================================
// Person[]  people = new Person[5]; 
//==================================================
//==============================================================
/*
#include <stdio.h> 
void main()
{
	double PI = 3.14;
	double * pArr[5]; 
	printf("%d\n", sizeof(pArr)); //?? 

	pArr[0] = &PI;
	pArr[1] = (double*)calloc(1, sizeof(double)); 
	pArr[2] = (double*)calloc(1, sizeof(double));
	pArr[3] = (double*)calloc(1, sizeof(double));
	pArr[4] = (double*)calloc(1, sizeof(double));

}
*///==============================================================
// ������ �迭�� ����ü�� ��� !! 
//==============================================================
#include <stdio.h> 
#include <malloc.h>

#pragma warning(disable : 4996)
//==============================================================
typedef struct Student
{
	int sno;		  // �й� 
	char name[20];// �̸� 
}STUDENT;
//==============================================================
typedef struct lib
{
	STUDENT * Seat[3][3]; // 2���� �迭 
	int  stuCount; 
}LIB;
//==============================================================
//  ������ �ڸ� ���� �ý��� !! 
//==============================================================
void showLib( LIB GguLib )
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			if (GguLib.Seat[i][j] == NULL)
				printf("[ ���ڸ� ]");
			else
				printf("[ %d ]", GguLib.Seat[i][j]->sno);
		}
		puts("");
	}
} 
// ������ �ʱ�ȭ 
void initLib(LIB GguLib)
{
	int i, j;
	for ( i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			GguLib.Seat[i][j] = NULL;
		}
	}
}
void inputSeat(LIB * GguLib) // �¼� Ȯ�� !!
{
	showLib(*GguLib);
	int x, y; 
	printf("�¼� ���� ( ����, ����) :"); 
	scanf("%d %d", &x, &y);
	
	GguLib->Seat[x][y] = (LIB*)malloc(sizeof(LIB));

	printf("�й� : ");
	scanf("%d", &GguLib->Seat[x][y]->sno);
	getchar();
	//fflush(stdin);
	printf("�̸� :"); 
	gets(GguLib->Seat[x][y]->name); 

}


void main()
{
	LIB GguLib;

	memset(&GguLib, 0, sizeof(LIB));

	initLib(GguLib);
	showLib( GguLib );
	inputSeat(&GguLib);
	showLib(GguLib);
	
}

