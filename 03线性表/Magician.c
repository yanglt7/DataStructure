#include <stdio.h>
#include <stdlib.h>

#define CardNumber 13

typedef struct node
{
	int data;
	struct node *next;
} sqlist, *linklist;

linklist CreateLinkList()
{
	linklist head = NULL;
	linklist s, r;
	int i;

	r = head;

	for(i=1; i<=CardNumber; i++)
	{
		s = (linklist)malloc(sizeof(sqlist));
		s->data = 0;

		if(head == NULL)
			head = s;
		else 
			r->next = s;

		r = s;
	}
	r->next = head;

	return head;
}

//����˳�����
void Magician(linklist head)
{
	linklist p;
	int j;
	int countnumber = 2;

	p = head;
	p->data = 1; //��һ���Ʒ�1

	while(1)
	{
		for(j=0; j<countnumber; j++)
		{
			p = p->next;
			if(p->data != 0) //��λ�����ƵĻ�������һ��λ��
			{
				p->next;
				j--;
			}
		}

		if(p->data == 0)
		{
			p->data = countnumber;
			countnumber++;

			if(countnumber == 14)
				break;
		}
	}
}

int main()
{
	linklist p;
	int i;

	p = CreateLinkList();
	Magician(p);

	printf("������˳�����У� \n");
	for(i=0; i<CardNumber; i++)
	{
		printf("����%d ", p->data);
		p = p->next;
	}
	return 0;
}


