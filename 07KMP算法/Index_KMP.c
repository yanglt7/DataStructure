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
			if( T[i] != T[j] )
			{
				next[i] = j;
			}
			else 
			{
				next[i] = next[j];
			}
		}
		else
		{
			//j回溯
			j = next[j];
		}
	}

//因为前缀是固定的，后缀是相对的
}

//返回子串T在主串S第pos个字符的位置
//若不存在，则返回-1
int Index_KMP( String S, String T, int pos )
{
	int i = pos;
	int j = 1;
	int next[255];

	get_next( T, next );

	while( i <= S[0] && j <= T[0] )
	{
		if( 0 == j || S[i] == T[j] )
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	if( j > T[0] )
	{
		return i - T[0];
		printf("%d ", i - T[0]);
	}
	else
	{
		return -1;
	} 
	
}

int main()
{
	char S[255] ;
	char T[255] ;
	int next[255];
	int n = 1;
	int k = 0;
	int pos;
	char c,e;
	
	printf("请输入主串： ，并以#作为结束标志！\n") ;
	scanf("%c", &c);
	while( c != '#' )
	{
		S[n++] = c;
		S[n] = '\0';
		scanf("%c", &c);
	}	
	S[0] = n-1;
	printf("S[0]=%d", S[0]);	

	printf("请输入子串： ，并以#作为结束标志！\n");
	scanf("%c", &e);
	while( e != '#' )
	{
		T[k++] = e;
		T[k] = '\0';
		scanf("%c", &e);
	}
	T[0] = k-1;	
	printf("T[0]=%d", T[0]);	
	
	printf("请输入主串中开始进行匹配的位置（首字符位置为1）：\n");
	scanf("%d", &pos);

	int result = Index_KMP( S, T, pos ); 
	if( result != -1 )
	{
		printf("主串与子串在主串的第%d个字符（首字符的位置为1）处首次匹配", result);
	}
	else
	{
		printf("无匹配子串\n");	
	}
	
	return 0;
}
