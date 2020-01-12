#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 100

typedef struct {
	int adjvex; //�ñߵ���һ�������λ�� 
	struct ArcNode *nextarc; //ָ����һ���� 
} ArcNode;

typedef struct{
	int data; // �����ֵ 
	ArcNode *firstarc; // ָ���һ�������ö���ıߵ�ָ�� 
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct{
	AdjList vertices; //�������� 
	int vexnum, arcnum;
} ALGraph;

//��λ���� 
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

	printf("�ֱ����붥������ͱߵ���Ŀ��\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("�ֱ������������ֵ��\n");

	for( i=0; i < G.vexnum; i++ )
	{
		scanf("%d", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;  //��ʼ�� 
	} 
	printf("�ֱ���������ߵ��������㣺\n");

	for( k=0; k < G.arcnum; k++ )
	{
		scanf("%d%d", &v1, &v2);

		//��λ 
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		//����һ�����
		p = (ArcNode*)malloc(sizeof(ArcNode)); 
		//��ֵ
		p->adjvex = j;
		p->nextarc = NULL; 
		//���ӽ��
		p->nextarc = G.vertices[i].firstarc; 
		G.vertices[i].firstarc = p;

		q = (ArcNode*)malloc(sizeof(ArcNode));
		q->adjvex = i;
		q->nextarc = NULL;
		q->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = q;
	}
}

//����ڽӱ� 
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

