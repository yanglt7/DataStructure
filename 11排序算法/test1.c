#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
 
void MergeSort(int k[],int n)
{
	int i,next,left_min,left_max,right_min,right_max;
	//开辟一个与原来数组一样大小的空间用来存储用
	int *temp = (int *)malloc(n * sizeof(int));
	//逐级上升，第一次比较2个，第二次比较4个，第三次比较8个。。。
	for(i=1; i<n; i*=2)
	{
		//每次都从0开始，数组的头元素开始
		for(left_min=0; left_min<n-i; left_min = right_max)
		{
			right_min = left_max = left_min + i;
			right_max = left_max + i;
			//右边的下标最大值只能为n
			if(right_max>n)
			{
				right_max = n;
			}
			//next是用来标志temp数组下标的，由于每次数据都有返回到K，
			//故每次开始得重新置零
			next = 0;
			//如果左边的数据还没达到分割线且右边的数组没到达分割线，开始循环
			while(left_min<left_max&&right_min<right_max)
			{
				if(k[left_min] < k[right_min])
				{
					temp[next++] = k[left_min++];
					
				}
				else
				{
					temp[next++] = k[right_min++];
				}
			}
			//上面循环结束的条件有两个，如果是左边的游标尚未到达，那么需要把
			//数组接回去，可能会有疑问，那如果右边的没到达呢，其实模拟一下就可以
			//知道，如果右边没到达，那么说明右边的数据比较大，这时也就不用移动位置了
			
			while(left_min < left_max)
			{
				//如果left_min小于left_max，说明现在左边的数据比较大
				//直接把它们接到数组的min之前就行
				k[--right_min] = k[--left_max];	
			}
			while(next>0)
			{
				//把排好序的那部分数组返回该k
				k[--right_min] = temp[--next];		
			}
		}
	}
}
 
int main(){
	int i,a[10] = {5,2,6,0,3,9,1,7,4,8};
	
	MergeSort(a,10);
	
	printf("排序后的结果是:");
	for(i=0; i<10; i++)
	{
		printf("%d",a[i]);
	}
	
	printf("\n\n");
	
	return 0;
	
}

