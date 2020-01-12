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

	// i=2*s：左孩子； 2*s+1: 右孩子 
	for( i=2*s; i <= n; i*=2 )
	{	
		count++;
		if( i < n && k[i] < k[i+1] )  // 左孩子小于右孩子
		{
			i++;  // 使得i指向最大的孩子的下标 
		}

		if( temp >= k[i] )  // temp临时存放当前需要调整的双亲。如果大于孩子，则退出循环
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
	
	// 从下至上，从右至左，层序遍历 
	for( i=n/2; i > 0; i-- )
	{
		HeapAdjust(k, i, n); // 构建大顶堆的函数。 k:数组 i:当前双亲结点； n:长度
	} 

	for( i=n; i > 1; i-- )
	{
		swap(k, 1, i);  // 调整，将第一个元素和最后一个元素进行互换，i是变化的 
		HeapAdjust(k, 1, i-1);  // 重新调整                                                                                                                                                                                                        
	}
}

int main()
{
	int i;
	int a[10] = {-1, 5, 2, 6, 0, 3, 9, 1, 7, 4};

	HeapSort(a, 9);

	printf("总共执行 %d 次比较! \n", count);
	printf("排序后的结果是： ");
	for( i=1; i < 10; i++ )
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}
