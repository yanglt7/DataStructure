// Kruskal�㷨������С������

int Find(int *parent, int f)
{
	while( parent[f] > 0 )
	{
		f = parent[f];
	}

	return f;
}

void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAGEDGE];  // ����߼�����
	int parent[MAXVEX];   // ����parent���������жϱ�����Ƿ��γɻ�·

	for( i=0; i < G.numVertexes; i++ )
	{
		parent[i] = 0;
	}

	for( i=0; i < G.numEdges; i++ )
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);

		if( n!= m )   // ���n==m�������㣡
		{
			parent[n] = m;  // ���˱ߵĽ�β��������±�Ϊ����parent�����У���ʾ�˶����Ѿ���������������
			printf("(%d, %d) %d ", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}
