#include <stdio.h>

int Fib(int i)
{
	if( i < 2 )
		return i == 0 ? 0 : 1;
	return Fib(i-1) + Fib(i-2);
}

int main()
{
	int i = 0;
	printf("请输入需要打印的斐波那契列数： "); 
	scanf("%d", &i);
	printf("%d ", Fib(i)); 
	
	return 0;
} 


