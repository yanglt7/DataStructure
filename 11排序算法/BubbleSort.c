#include <stdio.h>

void BubbleSort(int k[], int n)
{
	int i, j, temp, count1=0, count2=0;

	for( i=0; i < n-1; i++ )
	{
		for( j=i+1; j < n; j++ )
		{
			count1++;
			if( k[i] > k[j] )
			{
				count2++;
				temp = k[j];
				k[j] = k[i];
				k[i] = temp;
			}
		}
	}
	
	printf("�ܹ�������%d�αȽϣ�������%d���ƶ���\n", count1, count2);
}

int main()
{
	int i;
	int a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	BubbleSort(a, 10);

	printf("�����Ľ���ǣ� \n");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n");
	
	return 0;
}
