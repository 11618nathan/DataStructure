
#include <stdio.h>

void main()
{
	// char�迭�� �̿��� ���ڿ� �Է�
	int i;
	char name[32];
	char id[12] = "11618nathan";

	printf("��  ��: ");

	// �迭 &�ʿ�X
	scanf("%s", name);

	// null���� ����(\0) - Ư������(escape sequence) �ڵ� ����
	printf("��  ��: %s \n", name);

	// �迭 ũ��
	printf("id �迭�� ũ��: %d \n", sizeof(id));

	// ��  ���� ������
	printf("������: %c \n", id[12]);

	// ��  ���� ������
	printf("������: %d \n", id[12]);
}
