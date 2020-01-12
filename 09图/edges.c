// 边集数组

#include <stdio.h>

#define VertexNum 4
#define EdgesNum  4


int main()
{
	int i=0, j=0, k=0, n=0, m=0;
	int c;
	int Vertex[VertexNum];
	int Begin[EdgesNum];
	int End[EdgesNum];
	int Weight[EdgesNum];

	// 存储顶点信息
	printf("请输入顶点： ，以-1作为结束标志！\n");
	scanf("%d", &c);
	while( c != -1 )
	{
		Vertex[++i]  = c;
		Vertex[i] = '\0'; 
		scanf("%d", &c);
	}
	
	// 存储边的begin数值
	for( j=0; j < EdgesNum; j++ )
	{
		printf("请输入第 %d 条边的起点下标begin：\n", j);
		scanf("%d", &Begin[j]);
	}

	// 存储边的end数值
	for( k=0; k < EdgesNum; k++ )
	{
		printf("请输入第 %d 条边的终点下标end：\n", k);
		scanf("%d", &End[k]);
	}	

	// 存储边的weight数值
	for( n=0; n < EdgesNum; n++ )
	{
		printf("请输入第 %d 条边的权值weight：\n", n);
		scanf("%d", &Weight[n]);
	}	

	// 打印边集数组
	printf("边集数组信息为： 起点下标 终点下标 权值\n");
	for( m=0; m < EdgesNum; m++ )
	{
		printf("Edges[%d]\t%d\t %d\t %d\n", m, Begin[m], End[m], Weight[m]);
	}

	return 0;
}
