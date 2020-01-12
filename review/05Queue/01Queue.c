#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct{
	ElemType data;
	struct  QNode *next;
} QNode, *QueuePrt;

typedef struct 
{
	QueuePrt front, rear; 
} LinkQueue;

void InitQueue(LinkQueue *q)
{
	q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
	if( !q->front )
		exit(0);
	q->front->next = NULL;
}

void InsertQueue(LinkQueue *q, ElemType e)
{
	QueuePrt p;
	p = (QueuePrt)malloc(sizeof(QNode));
	if( p == NULL )
		exit(0);
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

void DeleteQueue(LinkQueue *q, ElemType *e)
{
	QueuePrt p;
	if( q->front == q->rear )
		return;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if( q->rear == p )
		q->rear = q->front;
	free(p);
}

void DestroyQueue(LinkQueue *q)
{
	while( q->front )
	{
		q->rear = q->front->next;
		free( q->front );
		q->front = q->rear;
	}
}

int main()
{
	LinkQueue q;
	ElemType c;

	InitQueue(&q);
	
	printf("请输入插入一串字符，以#作为结束标志\n\n");
	scanf("%c", &c);

	while( c != '#' )
	{
		InsertQueue(&q, c);
		scanf("%c", &c);
	}
	printf("\n输出的字符串为：\n");	
	while( q.front != q.rear )
	{
		DeleteQueue(&q, &c);
		printf("%c", c);
	}
	printf("\n");

	return 0;
}

