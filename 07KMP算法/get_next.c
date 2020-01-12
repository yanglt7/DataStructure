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
	char str[255] = " ababaaaba";
	int next[255];
	int i = 1;

	str[0] = 9;

	get_next( str, next );

	for( i=1; i < 10; i++ )
	{
		printf("%d ", next[i]);
	}

	return 0;

}
