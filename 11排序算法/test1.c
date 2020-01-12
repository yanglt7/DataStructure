#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
 
void MergeSort(int k[],int n)
{
	int i,next,left_min,left_max,right_min,right_max;
	//����һ����ԭ������һ����С�Ŀռ������洢��
	int *temp = (int *)malloc(n * sizeof(int));
	//����������һ�αȽ�2�����ڶ��αȽ�4���������αȽ�8��������
	for(i=1; i<n; i*=2)
	{
		//ÿ�ζ���0��ʼ�������ͷԪ�ؿ�ʼ
		for(left_min=0; left_min<n-i; left_min = right_max)
		{
			right_min = left_max = left_min + i;
			right_max = left_max + i;
			//�ұߵ��±����ֵֻ��Ϊn
			if(right_max>n)
			{
				right_max = n;
			}
			//next��������־temp�����±�ģ�����ÿ�����ݶ��з��ص�K��
			//��ÿ�ο�ʼ����������
			next = 0;
			//�����ߵ����ݻ�û�ﵽ�ָ������ұߵ�����û����ָ��ߣ���ʼѭ��
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
			//����ѭ���������������������������ߵ��α���δ�����ô��Ҫ��
			//����ӻ�ȥ�����ܻ������ʣ�������ұߵ�û�����أ���ʵģ��һ�¾Ϳ���
			//֪��������ұ�û�����ô˵���ұߵ����ݱȽϴ���ʱҲ�Ͳ����ƶ�λ����
			
			while(left_min < left_max)
			{
				//���left_minС��left_max��˵��������ߵ����ݱȽϴ�
				//ֱ�Ӱ����ǽӵ������min֮ǰ����
				k[--right_min] = k[--left_max];	
			}
			while(next>0)
			{
				//���ź�����ǲ������鷵�ظ�k
				k[--right_min] = temp[--next];		
			}
		}
	}
}
 
int main(){
	int i,a[10] = {5,2,6,0,3,9,1,7,4,8};
	
	MergeSort(a,10);
	
	printf("�����Ľ����:");
	for(i=0; i<10; i++)
	{
		printf("%d",a[i]);
	}
	
	printf("\n\n");
	
	return 0;
	
}

