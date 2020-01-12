// n个人围圈报数，报m出列，最后剩下的是几号？ 

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

node *create(int n)
{
	node *p = NULL, *head;
	head = (node *)malloc(sizeof(node));
	p = head;
	node *s;
	int i = 1;
	
	if ( 0 != n )
	{
		while ( i<=n )
		{
			s = (node *)malloc(sizeof(node));
			s->data = i++;
			p->next = s;
			p = s;
		}
		s->next = head->next;
	}
}

int main()
{
	int n = 41;
	int m = 3;
	int i;
	node *p = create(n);
	node *temp;
	
	m %= n;
	//printf("%d", m); // 一开始 m=3
	//printf("%d\n", p->data); // 一开始 p->data=n=41  
	
	while ( p != p->next ) 
	{
		for ( i=1; i<m; i++ )
		{
			p = p->next;
		}
		printf("%d->", p->next->data);
		temp = p->next;
		p->next = temp->next;
		free(temp);
		p = p->next;  // 第一次：p=2, temp=3, p->next=4, p=4 ...
	}
	
	printf("%d\n", p->data);
	//printf("%d\n", p->next->data);
	
	return 0;
}
