// �ڽӾ�������ͼ��

#include <stdio.h>

#define n 4
#define M 4
#define N 4

int main()
{
	int i=0, j=0, k=0;
	int c;
	int Vertex[n];
	int a[M][N];

	printf("�����붥�㣺 ����-1��Ϊ������־��\n");
	scanf("%d", &c);
	while( c != -1 )
	{
		Vertex[++i] = c;
		Vertex[i] = '\0';
		scanf("%d", &c);
	}

	printf("�����붥��֮��ߵĹ�ϵ�� 1��ʾ��������֮���бߣ�0��ʾ��������֮���ޱߡ�\n");
	for( i=0; i < M; i++ )
	{
		for( j=0; j < N; j++ )
		{
			printf("%d �� %d ֮��Ĺ�ϵΪ: ", i, j);
			scanf("%d", &a[i][j]);
			printf("%d\n", a[i][j]);
		}
	}

	printf("�ڽӾ�������ͼ��Ϊ�� \n");
	for( i=0; i < M; i++ )
	{
		for( j=0; j < N; j++ )
		{
			printf("%d\t", a[i][j]);
			k++;
		}
	
		if( k%4 == 0 )
		{
			printf("\n");
		}
	}
	
	return 0;

}
