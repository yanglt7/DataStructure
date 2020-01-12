#include <stdio.h>

void swap(int k[], int low, int high)
{
	int temp;

	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}

int Partition(int k[], int low, int high)
{
	int point;

	int m = low + (high-low)/2;

	if( k[low] > k[high] )
	{
		swap(k, low, high);
	}

	if( k[m] > k[high] )
	{
		swap(k, m, high);
	}

	if( k[m] > k[low] )
	{
		swap(k, m, low);
	}

	// 将low变成中间值
	point = k[low];

	while( low < high )
	{
		while( low < high && k[high] >= point )
		{
			high--;
		}
		k[low] = k[high];

		while( low < high && k[low] <= point )
		{
			low++;
		}
		k[high] = k[low];
	}

	k[low] = point;
}

void QSort(int k[], int low, int high)
{
	int point;

	if( low < high )
	{
		point = Partition(k, low, high);  // 计算基准点，将小于基准点的数放在左边，大的放在右边

		QSort(k, low, point-1);

		QSort(k, point+1, high);
	}
}	

void QuickSort(int k[], int n)
{
	QSort(k, 0, n-1);
} 

int main()
{
	int i;
	int a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	QuickSort(a, 10);

	printf("排序后的结果是： \n");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n");
	
	return 0;
}
