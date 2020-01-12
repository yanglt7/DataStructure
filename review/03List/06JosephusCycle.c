// n����ΧȦ��������m���У����ʣ�µ��Ǽ��ţ� 

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
	//printf("%d", m); // һ��ʼ m=3
	//printf("%d\n", p->data); // һ��ʼ p->data=n=41  
	
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
		p = p->next;  // ��һ�Σ�p=2, temp=3, p->next=4, p=4 ...
	}
	
	printf("%d\n", p->data);
	//printf("%d\n", p->next->data);
	
	return 0;
}
