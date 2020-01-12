#include <stdio.h>

int count = 0;

void swap(int k[], int i, int j)
{
	int temp;

	temp = k[i];
	k[i] = k[j];
	k[j] = temp;
}

void HeapAdjust(int k[], int s, int n)
{
	int i, temp;

	temp = k[s];

	// i=2*s�����ӣ� 2*s+1: �Һ��� 
	for( i=2*s; i <= n; i*=2 )
	{	
		count++;
		if( i < n && k[i] < k[i+1] )  // ����С���Һ���
		{
			i++;  // ʹ��iָ�����ĺ��ӵ��±� 
		}

		if( temp >= k[i] )  // temp��ʱ��ŵ�ǰ��Ҫ������˫�ס�������ں��ӣ����˳�ѭ��
		{
			break;
		}

		k[s] = k[i];
		s = i;
	} 

	k[s] = temp;
}

void HeapSort(int k[], int n)
{
	int i;
	
	// �������ϣ��������󣬲������ 
	for( i=n/2; i > 0; i-- )
	{
		HeapAdjust(k, i, n); // �����󶥶ѵĺ����� k:���� i:��ǰ˫�׽�㣻 n:����
	} 

	for( i=n; i > 1; i-- )
	{
		swap(k, 1, i);  // ����������һ��Ԫ�غ����һ��Ԫ�ؽ��л�����i�Ǳ仯�� 
		HeapAdjust(k, 1, i-1);  // ���µ���                                                                                                                                                                                                        
	}
}

int main()
{
	int i;
	int a[10] = {-1, 5, 2, 6, 0, 3, 9, 1, 7, 4};

	HeapSort(a, 9);

	printf("�ܹ�ִ�� %d �αȽ�! \n", count);
	printf("�����Ľ���ǣ� ");
	for( i=1; i < 10; i++ )
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}
