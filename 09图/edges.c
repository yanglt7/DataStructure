// �߼�����

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

	// �洢������Ϣ
	printf("�����붥�㣺 ����-1��Ϊ������־��\n");
	scanf("%d", &c);
	while( c != -1 )
	{
		Vertex[++i]  = c;
		Vertex[i] = '\0'; 
		scanf("%d", &c);
	}
	
	// �洢�ߵ�begin��ֵ
	for( j=0; j < EdgesNum; j++ )
	{
		printf("������� %d ���ߵ�����±�begin��\n", j);
		scanf("%d", &Begin[j]);
	}

	// �洢�ߵ�end��ֵ
	for( k=0; k < EdgesNum; k++ )
	{
		printf("������� %d ���ߵ��յ��±�end��\n", k);
		scanf("%d", &End[k]);
	}	

	// �洢�ߵ�weight��ֵ
	for( n=0; n < EdgesNum; n++ )
	{
		printf("������� %d ���ߵ�Ȩֵweight��\n", n);
		scanf("%d", &Weight[n]);
	}	

	// ��ӡ�߼�����
	printf("�߼�������ϢΪ�� ����±� �յ��±� Ȩֵ\n");
	for( m=0; m < EdgesNum; m++ )
	{
		printf("Edges[%d]\t%d\t %d\t %d\n", m, Begin[m], End[m], Weight[m]);
	}

	return 0;
}
