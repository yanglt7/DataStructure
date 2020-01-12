//折半查找法的迭代实现 2
#include <stdio.h>
#include <stdlib.h>

int getAddr(int str[], int key, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (key == str[mid])
        return mid;

    if (str[mid] < key)
    {
        low = mid + 1;
    }
    else if (str[mid] > key)
    {
        high = mid - 1;
    }

    return getAddr(str, key, low, high);
}

int main()
{
	const int SIZE = 10;
    int c;
    int i = 0;
    int str[SIZE];
    printf("请输入 %d 个数字，并以0作为结束标志！\n", SIZE); 
    scanf("%d", &c);

    while( c != 0 )
    {
        str[i] = c;
        i++;
        scanf("%d", &c);    
    }

    for( i=0; i<SIZE; i++ )
    {
        printf("%d ", str[i]);        
    }

    int n, addr;

	printf("\n请输入要查询的数字：");
	scanf("%d", &n);
    
    addr = getAddr(str, n, 0, SIZE);

    if (-1 != addr)
    {
        printf("查找成功，查询数字%d所在的位置是：%d\n", n, addr+1);
    }
    else
    {
        printf("查找失败");
    }

    return 0;
}

