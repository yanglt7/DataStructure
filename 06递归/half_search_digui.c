//折半查找法的递归实现

#include <stdio.h>

typedef int ElemType;

int half_search(ElemType *str, int low, int high, ElemType n)
{
	int mid = (low + high)/2;

	if(low > high)
		return -1;

	if( str[mid] == n )
	{
		return mid;
	}
	else if( str[mid] < n )
	{
		return half_search(str, mid+1, high, n);
	}
	else
	{
		return half_search(str, low, mid-1, n);
	}
}

int main()
{
	const int SIZE = 10;
	ElemType str[SIZE];
	int c;
	int i = 0;

	printf("请输入 %d 个数字作为初始数组：\n", SIZE);
	 
	while( i < SIZE )
	{
		scanf("%d", &c);
		str[i] = c;
		i++;
	}

    for( i=0; i<SIZE; i++ )
    {
        printf("%d ", str[i]);        
    }

    int n;
	printf("\n请输入要查询的数字：");
	scanf("%d", &n);

    int addr = half_search(str, 0, SIZE, n);

    if (-1 != addr)
    {
        printf("查找成功，查询数字 %d 所在的位置是： %d\n", n, addr+1);
    }
    else
    {
        printf("查找失败!"); 
    }

	return 0;
}
