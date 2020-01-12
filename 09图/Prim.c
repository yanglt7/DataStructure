// Prim�㷨������С������

void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];  // ������ض����±�
	int lowcost[MAXVEX];  // ������ض����ߵ�Ȩֵ

	lowcost[0] = 0;  // V0��Ϊ��С�������ĸ���ʼ������ȨֵΪ0
	adjvex[0] = 0;  // V0��һ������

	// ��ʼ������
	for( i=0; i < G.numVertexes; i++ )
	{
		lowcost[i] = G.arc[0][i];  // ���ڽӾ����0������Ȩֵ�ȼ�������
		adjvex[i] = 0;  // ��ʼ��ȫ����ΪV0���±�
	}

	// ����������С�������Ĺ���
	for( i=0; i < G.numVertexes; i++ )
	{
		min = INFINITY; // ��ʼ����СȨֵΪ65535�Ȳ�������ֵ
		j = 1;
		k = 0;

		// ����ȫ������
		while( j < G.numVertexes )
		{
			// �ҳ�lowcost�����Ѵ洢����СȨֵ
			if( lowcost[j] != 0 && lowcost[j] < min )
			{
				min = lowcost[j];
				k = j;  // �����ֵ���СȨֵ���±����k���Դ�ʹ��
			}
			j++;
		}

		// ��ӡ��ǰ�������Ȩֵ��С�ı�
		printf("(%d, %d)", adjvex[k], k);
		lowcost[k] = 0;  // ����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ�������񣬽�����һ������ı���

		// �ڽӾ���k���������ȫ������
		for( j=1; j < G.numVertexes; j++ )
		{
			if( lowcost[j] != 0 && G.arc[k][j] < lowcost[j] )
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}

}
