#include <stdio.h>

typedef char * String;

void get_next( String T, int *next )
{
	int j = 0;
	int i = 1;
	next[1] = 0;

	while( i < T[0] )
	{
		if( 0 == j || T[i] == T[j] )
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			//j回溯
			j = next[j];
		}
	}

//因为前缀是固定的，后缀是相对的
}

int main()
{
	char T[255];
	int next[255];
	int i = 1;
	int n = 1;
	char c;
	
	printf("请输入需要获取next数组的字符串：，并以#作为结束标志!\n");
	scanf("%c", &c);
	
	while( c != '#' )
	{
		T[n++] = c;
		T[n] = '\0';
		scanf("%c", &c);
	}
	T[0] = n;
//	printf("T[0]=%d", T[0]);
	
	get_next( T, next );

	for( i=1; i < T[0]; i++ )
	{
		printf("%d ", next[i]);
	}

	return 0;

}
