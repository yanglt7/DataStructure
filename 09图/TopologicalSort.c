// ���������㷨

// �߱�������
typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode
{
	int in;  // �������
	int data;
	EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
} GraphAdjList, *GraphAdjList;

// ���������㷨
// ��GL�޻�·������������������в�����OK�����򷵻�ERROR
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;     // ����ջָ���±�����
	int count = 0;   // ����ͳ���������ĸ���
	int *stack;      // ���ڴ洢���Ϊ0�Ķ���

	stack = (int *)malloc(GL->numVertexes * sizeof(int));

	for( i=0; i < GL->numVertexes; i++ )
	{
		if( 0 == GL->adjList[i].in )
		{
			stack[++top] = i;  // ����Ϊ0�Ķ����±���ջ
		}
	}

	while( 0 != top )
	{
		gettop = stack[top--];  // ��ջ
		printf("%d -> ", GL->adjList[gettop].data);
		count++;

		for( e=GL->adjList[gettop].firstedge; e; e=e->next )
		{
			k =  e->adjvex;
			// ע�⣺�±����if�����Ƿ������������Ҫ��
			// ��k�Ŷ����ڽӵ�����Ϊ-1����Ϊ����ǰ���Ѿ�����
			// �����ж�-1������Ƿ�Ϊ0�����Ϊ0��Ҳ��ջ
			if( !(--GL->adjList[k].in) )
			{
				stack[++top] = k;
			}
		}
	}

	if( count < GL->numVertexes )  //���countС�ڶ�������˵�����ڻ�
	{
		return ERROR;
	}
	else
	{
		return OK;
	}

	return 0;
}
