#include <stdio.h>

typedef char *String;

//返回子串T在主串S的第pos个字符后(含第pos个位置)第一次出现的位置
//若不存在，则返回-1
//采用BF算法，这里的位置全部以从1开始计算为准，其中T非空，1<=pos<=T[0]
int Index_BF( String S, String T , int pos )
{
	int i = pos;  //主串当前正待比较的位置，初始为pos
	int j = 1;   //子串当前正待比较的位置，初始为1
	
	while( i <= S[0] && j <= T[0] )
	{
		if( S[i] == T[j] )   //如果当前字符相同，则继续向下比较
		{   
			i++;
			j++;
		}
		else   //如果当前字符不同，则i和j回退，重新进行匹配
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
	
	printf("请输入主串： ，并以#作为结束标志！\n"); 
	scanf("%c", &c);
	while( c != '#' )
	{
		S[n++] = c;
		S[n] = '\0';
		scanf("%c", &c);

	}
	S[0] = n-1;	
	
	printf("请输入子串： ，并以#作为结束标志！\n");
	scanf("%c", &e);
	while( e != '#' )
	{
		T[k++] = e;
		T[k] = '\0';
		scanf("%c", &e);
	}
	T[0] = k-1;	
			
	printf("请输入主串中开始进行匹配的位置（首字符位置为1）：\n");
	scanf("%d", &pos);

	int result = Index_BF( S, T, pos );
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

