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
			//j����
			j = next[j];
		}
	}

//��Ϊǰ׺�ǹ̶��ģ���׺����Ե�
}

//�����Ӵ�T������S��pos���ַ���λ��
//�������ڣ��򷵻�-1
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
	
	printf("������������ ������#��Ϊ������־��\n") ;
	scanf("%c", &c);
	while( c != '#' )
	{
		S[n++] = c;
		S[n] = '\0';
		scanf("%c", &c);
	}	
	S[0] = n-1;
	printf("S[0]=%d", S[0]);	

	printf("�������Ӵ��� ������#��Ϊ������־��\n");
	scanf("%c", &e);
	while( e != '#' )
	{
		T[k++] = e;
		T[k] = '\0';
		scanf("%c", &e);
	}
	T[0] = k-1;	
	printf("T[0]=%d", T[0]);	
	
	printf("�����������п�ʼ����ƥ���λ�ã����ַ�λ��Ϊ1����\n");
	scanf("%d", &pos);

	int result = Index_KMP( S, T, pos ); 
	if( result != -1 )
	{
		printf("�������Ӵ��������ĵ�%d���ַ������ַ���λ��Ϊ1�����״�ƥ��", result);
	}
	else
	{
		printf("��ƥ���Ӵ�\n");	
	}
	
	return 0;
}
