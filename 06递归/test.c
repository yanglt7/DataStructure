#include <stdio.h>
#include <stdlib.h>

int bin_serach(int str[], int n, int key)
{
    int low, mid, high;

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high)/2;
        if (str[mid] == key)
        {
            return mid;
        }
        else if (str[mid] < key)
        {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}

int main()
{
	const int SIZE = 10;
    int c;
    int i = 0;
    int str[SIZE];
    
	printf("������ %d ��������Ϊ��ʼ���飺\n", SIZE);
	 
	while( i < SIZE )
	{
		scanf("%d", &c);
		str[i] = c;
		i++;
	}
	
	printf("\n"); 
    for( i=0; i<SIZE; i++ )
    {
        printf("%d ", str[i]);        
    }

    int n, addr;

    printf("\n������Ҫ��ѯ�����֣�");
    scanf("%d", &n);

    addr = bin_serach(str, SIZE, n);

    if (-1 != addr)
    {
        printf("���ҳɹ�����ѯ���� %d ���ڵ�λ���ǣ� %d\n", n, addr+1);
    }
    else
    {
        printf("����ʧ��!");
    }

    return 0;
}
