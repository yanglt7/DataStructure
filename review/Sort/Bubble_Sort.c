#include <stdio.h>

#define MAXSIZE 10

typedef struct
{
	int r[MAXSIZE+1];
	int length;
} SqList;
 
void swap(SqList *L, int i, int j)
{
	int temp;
	temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = L->r[i];
}

void Bubble_Sort(SqList *L)
{
	int i, j;
	int flag=1;
	
	for ( i=1; i < L->length-1 && flag; i++ )
	{
		flag = 0;
		for ( j = L->length-1; j >= i; j-- )
		{
			if ( L->r[j] > L->r[j+1] )
			{
				swap(L, j, j+1);
				flag = 1;
			}
		}
	}
}

int main()
{	
	SqList L[] = {0, 1, 9, 2, 5, 8, 3, 7, 4, 6};
	Bubble_Sort(L);

	int k;
	for ( k=1; k < sizeof(L)/sizeof(L[0]); k++ )
	{
		printf("%d\t", L[k]);
	} 
	
	return 0;
}
