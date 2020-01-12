// dijkstra�㷨�����·��

#define MAXVEX 9
#define INFINITY 65535

typedef int Patharc[MAXVEX];         // ���ڴ洢���·���±������
typedef int ShortPathTable[MAXVEX];  // ���ڴ洢���������·����Ȩֵ��

void ShortestPath_Dijkstra(MGragh G, int V0, Patharc *P, ShortPathTable *D)
{
	int v, w, k, min;
	int final[MAXVEX];  // final[w] = 1 ��ʾ�Ѿ���ö���V0��Vw�����·��

	// ��ʼ������
	for( v=0; v < G.numVertexes; v++ )
	{
		final[v] = 0;            // ȫ�������ʼ��Ϊδ�ҵ����·��
		(*D)[V] = G.arc[V0][v];  // ����V0�������ߵĶ������Ȩֵ
		(*P)[V] = 0;             // ��ʼ��·������PΪ0
	}
	(*D)[V0] = 0;   // V0��V0��·��Ϊ0
	final[V0] = 1;  // V0��V0����Ҫ·��

	// ��ʼ��ѭ����ÿ�����V0��ĳ��v��������·��
	for( v=1; v < G.numVertexes; v++ )
	{
		min = INFINITY;
		for( w=0; w < G.numVertexes; w++ )
		{
			if( !final[w] && (*D)[w] < min )
			{
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;  // ��Ŀǰ�ҵ�������Ķ�����1

		for( w=0; w < G.numVertexes; w++ )
		{
			// �������v�����·������������·���ĳ��ȶ̵Ļ�������
			if( !final[w] && (min+G.arc[k][w] < (*D)[w]) )
			{
				(*D)[w] = min + G.arc[k][w];   // �޸ĵ�ǰ·������
				(*p)[w] = k;                   // ���ǰ������
			}
		}
	}
}
