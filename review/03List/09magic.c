// ħ��ʦ�������⣺ 

#include <stdio.h>
#include <stdlib.h>

# define CardNumber 13

typedef struct node
{
	int data;
	struct node *next;
} sqlist, *LinkList;

//��ʼ��ѭ���������ݾ�Ϊ0 
LinkList CreateLinkList()
{
	LinkList head = NULL;
	int i;
	LinkList s,r;
	
	r = head;
	
	for ( i=1; i<=CardNumber; i++ )
	{
		s = (LinkList)malloc(sizeof(sqlist));
		s->data = 0;
		
		if ( head == NULL )
		{
			head = s;
		}
		else
		{
			r->next = s;
		}
		
		r = s;
	}
	
	r->next = head;
	
	return head;
}

// ����˳����� 
void magic(LinkList head)
{
	LinkList p;
	int j;
	int cnt = 2;
	
	p = head;
	p->data = 1;
	
	while(1)
	{
		for ( j=0; j<cnt; j++ )
		{
			p = p->next;
			if ( p->data != 0 )
			{
				j--;
			}
		}
		
		if ( p->data == 0 )
		{
			p->data = cnt;
			cnt++;
			
			if ( cnt == 14 )
			{
				break;
			}
		}
	} 
 } 

int main()
{
	LinkList p;
	int i;
	
	p = CreateLinkList();
	magic(p);
	
	printf("������˳�����У� \n");
	for ( i=0; i<CardNumber; i++ )
	{
		printf("%d ", p->data);
		p = p->next;
	}
	
	return 0;
}
