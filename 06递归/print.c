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
	printf("请输入字符串，并以 # 作为结束标志！\n"); 	
	print();
	
	return 0;
}

