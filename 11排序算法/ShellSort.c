#include <stdio.h>

void ShellSort(int k[], int n)
{
	int i, j, temp;
	int gap = n;
	
	do
	{
		gap /= 3;
		
		for( i=gap; i < n; i++ )
		{
			if( k[i] < k[i-gap] )
			{
				temp = k[i];

				for( j=i-gap; k[j] > temp; j-=gap )
				{
					k[j+gap] = k[j];
				}

				k[j+gap] = temp;
			}
		}		
	} while(gap > 0);
}

int main()
{
	int i;
	int a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	ShellSort(a, 10);

	printf("排序后的结果是： \n");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n");
	
	return 0;
}
