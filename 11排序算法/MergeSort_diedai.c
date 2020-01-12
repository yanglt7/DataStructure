// 迭代实现

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

void MergeSort(int k[], int n)
{
	 int i, next, left_min, left_max, right_min, right_max;	

	 // 申请空间存放数组
	 int *temp = (int *)malloc(n * sizeof(int));

	 // 逐级递增比较
	 for( i=1; i < n; i*=2 ) // 步长i
	 {
	 	for( left_min=0; left_min < n-i; left_min = right_max )
	 	{
	 		right_min = left_max = left_min + i;
	 		right_max = left_max + i;

	 		// 右边的下标最大值只能为n，防止越界
	 		if( right_max > n )
	 		{
	 			right_max = n;
	 		}

	 		// temp数组的下标，由于每次数据都有返回到k，因此每次都需重新置零
	 		next = 0;

	 		// 如果左边的数据还没有到分割线且右边的数据也没有到分割线，则循环
	 		while( left_min < left_max && right_min < right_max )
	 		{
	 			if( k[left_min] < k[right_min] )
	 			{
	 				temp[next++] = k[left_min++]; // 存放较小者
	 			}
	 			else 
	 			{
	 				temp[next++] = k[right_min++];
	 			}
	 		}
	 		// 如果左边的游标没有到达分割线，则需要把数组接回去
	 		// 如果右边的游标没有到达分割线，则说明右边的数据比较大，不需要移动位置

	 		while( left_min < left_max )
	 		{
	 			k[--right_min] = k[--left_max];
	 		}

	 		while( next > 0 )
	 		{
	 			// 将排好序的数组返回给k
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

	printf("排序后的结果是： \n");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n");
	
	return 0;
}
