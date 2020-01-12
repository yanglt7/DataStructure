// 邻接矩阵（无向图）

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

	printf("请输入顶点： ，以-1作为结束标志！\n");
	scanf("%d", &c);
	while( c != -1 )
	{
		Vertex[++i] = c;
		Vertex[i] = '\0';
		scanf("%d", &c);
	}

	printf("请输入顶点之间边的关系： 1表示两个顶点之间有边，0表示两个顶点之间无边。\n");
	for( i=0; i < M; i++ )
	{
		for( j=0; j < N; j++ )
		{
			printf("%d 和 %d 之间的关系为: ", i, j);
			scanf("%d", &a[i][j]);
			printf("%d\n", a[i][j]);
		}
	}

	printf("邻接矩阵（无向图）为： \n");
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
