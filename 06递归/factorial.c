#include <stdio.h>

int factorial(n)
{
	if( 0 == n )
		return 1;
	else
		return n*factorial(n-1);
}

int main()
{
	int n = 0;
	printf("��������Ҫ����׳˵����� n �� ");
	scanf("%d", &n);
	printf("%d\n", factorial(n));
	
	return 0; 
}
