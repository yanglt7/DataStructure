#include <stdio.h>

void print()
{
	char a;
	scanf("%c", &a);
	if( a != '#' )
		print();
	if( a != '#' )
		printf("%c", a);
}

int main()
{
	printf("�������ַ��������� # ��Ϊ������־��\n"); 	
	print();
	
	return 0;
}

