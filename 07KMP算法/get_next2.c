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
			//j����
			j = next[j];
		}
	}

//��Ϊǰ׺�ǹ̶��ģ���׺����Ե�
}

int main()
{
	char T[255];
	int next[255];
	int i = 1;
	int n = 1;
	char c;
	
	printf("��������Ҫ��ȡnext������ַ�����������#��Ϊ������־!\n");
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
