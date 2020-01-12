#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 100

typedef struct {
	int adjvex; //该边的另一个顶点的位置 
	struct ArcNode *nextarc; //指向下一条边 
} ArcNode;

typedef struct{
	int data; // 顶点的值 
	ArcNode *firstarc; // 指向第一条依附该顶点的边的指针 
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct{
	AdjList vertices; //顶点数组 
	int vexnum, arcnum;
} ALGraph;

//定位函数 
int LocateVex(ALGraph G, int v)
{
	int i=0;
	
	for( i=0; i < G.vexnum; i++ )
	{
		if( v == G.vertices[i].data ) 
			return i;
	} 
}

void CreateUDG( ALGraph G )
{
	ArcNode *p,*q;
	int i, j, k, v1, v2;

	printf("分别输入顶点个数和边的数目：\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("分别输入各个顶点值：\n");

	for( i=0; i < G.vexnum; i++ )
	{
		scanf("%d", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;  //初始化 
	} 
	printf("分别输入各条边的两个顶点：\n");

	for( k=0; k < G.arcnum; k++ )
	{
		scanf("%d%d", &v1, &v2);

		//定位 
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		//申请一个结点
		p = (ArcNode*)malloc(sizeof(ArcNode)); 
		//赋值
		p->adjvex = j;
		p->nextarc = NULL; 
		//连接结点
		p->nextarc = G.vertices[i].firstarc; 
		G.vertices[i].firstarc = p;

		q = (ArcNode*)malloc(sizeof(ArcNode));
		q->adjvex = i;
		q->nextarc = NULL;
		q->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = q;
	}
}

//输出邻接表 
void PrintUDG(ALGraph G)
{
    int i, j;
	for( i=0; i < G.vexnum; i++ )
	{
		printf("%d:", i);
		ArcNode *p;
		p = G.vertices[i].firstarc;
		
		while( p != NULL )
		{
			printf("->%d", p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
}

int main()
{
	ALGraph G;
	CreateUDG(G);
	PrintUDG(G);
	
	return 0;
}

