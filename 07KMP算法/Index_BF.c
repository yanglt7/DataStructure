#include <stdio.h>

typedef char *String;

//�����Ӵ�T������S�ĵ�pos���ַ���(����pos��λ��)��һ�γ��ֵ�λ��
//�������ڣ��򷵻�-1
//����BF�㷨�������λ��ȫ���Դ�1��ʼ����Ϊ׼������T�ǿգ�1<=pos<=T[0]
int Index_BF( String S, String T , int pos )
{
	int i = pos;  //������ǰ�����Ƚϵ�λ�ã���ʼΪpos
	int j = 1;   //�Ӵ���ǰ�����Ƚϵ�λ�ã���ʼΪ1
	
	while( i <= S[0] && j <= T[0] )
	{
		if( S[i] == T[j] )   //�����ǰ�ַ���ͬ����������±Ƚ�
		{   
			i++;
			j++;
		}
		else   //�����ǰ�ַ���ͬ����i��j���ˣ����½���ƥ��
		{   
			i = i-j+2;
			j = 1;
		}
	}
 
	if( j > T[0] )
	{
		return i - T[0];
	}		
	else
	{
		return -1;
	}
		
}

int main()
{
	char S[255];
	char T[255];
	char c, e;
	int n = 1;
	int k = 0;

	int pos;
	
	printf("������������ ������#��Ϊ������־��\n"); 
	scanf("%c", &c);
	while( c != '#' )
	{
		S[n++] = c;
		S[n] = '\0';
		scanf("%c", &c);

	}
	S[0] = n-1;	
	
	printf("�������Ӵ��� ������#��Ϊ������־��\n");
	scanf("%c", &e);
	while( e != '#' )
	{
		T[k++] = e;
		T[k] = '\0';
		scanf("%c", &e);
	}
	T[0] = k-1;	
			
	printf("�����������п�ʼ����ƥ���λ�ã����ַ�λ��Ϊ1����\n");
	scanf("%d", &pos);

	int result = Index_BF( S, T, pos );
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

