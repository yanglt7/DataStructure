// ����ʵ��

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

void MergeSort(int k[], int n)
{
	 int i, next, left_min, left_max, right_min, right_max;	

	 // ����ռ�������
	 int *temp = (int *)malloc(n * sizeof(int));

	 // �𼶵����Ƚ�
	 for( i=1; i < n; i*=2 ) // ����i
	 {
	 	for( left_min=0; left_min < n-i; left_min = right_max )
	 	{
	 		right_min = left_max = left_min + i;
	 		right_max = left_max + i;

	 		// �ұߵ��±����ֵֻ��Ϊn����ֹԽ��
	 		if( right_max > n )
	 		{
	 			right_max = n;
	 		}

	 		// temp������±꣬����ÿ�����ݶ��з��ص�k�����ÿ�ζ�����������
	 		next = 0;

	 		// �����ߵ����ݻ�û�е��ָ������ұߵ�����Ҳû�е��ָ��ߣ���ѭ��
	 		while( left_min < left_max && right_min < right_max )
	 		{
	 			if( k[left_min] < k[right_min] )
	 			{
	 				temp[next++] = k[left_min++]; // ��Ž�С��
	 			}
	 			else 
	 			{
	 				temp[next++] = k[right_min++];
	 			}
	 		}
	 		// �����ߵ��α�û�е���ָ��ߣ�����Ҫ������ӻ�ȥ
	 		// ����ұߵ��α�û�е���ָ��ߣ���˵���ұߵ����ݱȽϴ󣬲���Ҫ�ƶ�λ��

	 		while( left_min < left_max )
	 		{
	 			k[--right_min] = k[--left_max];
	 		}

	 		while( next > 0 )
	 		{
	 			// ���ź�������鷵�ظ�k
	 			 k[--right_min] = temp[--next];
	 		}
	 	}
	 }
} 

int main()
{
	int i;
	int a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	MergeSort(a, 10);

	printf("�����Ľ���ǣ� \n");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n");
	
	return 0;
}
