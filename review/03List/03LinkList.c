// 单链表存储结构 
typedef struct Node
{
	ElemType data; // 数据域
	struct Node* Next; // 指针域 
} Node; 
typedef struct Node* LinkList; // 取别名，即 Node*==LinkList 


void getElem(LinkList L, int i, ElemType *e)
{
	int j = 1;
	LinkList p;
	
	p = L->Next;
	
	while ( p && j<i )
	{
		p = p->Next;
		j++;
	}
	
	if ( !p || j>i )
	{
		return ERROR;
	}
	
	*e = p->data;
	
	return OK;
}

void ListInsert(Linklist *L, int i, ElemType *e)
{
	LinkList s, p;
	 
	int j = 1;
	
	p = *L;
	
	while ( p && j<i )
	{
		p = p->Next;
		j++;
	}
	
	if ( !p || j>i )
	{
		return ERROR;
	}
	
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	
	s->Next = p->Next;
	p->Next = s;
	
	return OK;
}

void ListDelete(LinkList *L, int i, ElemType *e)
{
	LinkList p, q;
	p = *L;
	
	int j = 1;
	
	while ( p && j< )
	{
		p = p->Next;
		j++;
	}
	
	if ( !p || j>i )
	{
		return ERROR;
	}
	
	q = p->Next;
	p->Next = q->Next;
	
	*e = q->data;
	free(q);
	
	return OK;
}


void CreateListHead(LinkList *L, int i, ElemType *e)
{
	int j = 1;
	LinkList p;
	
	srand(time(0));
	
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	
	while ( j<i )
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	
	return OK;
}

void CreateListTail(LinkList *L, int i, ElemType *e)
{
	LinkList p, r;
	
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;

	for ( i=0; i < n; i++ )
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		r->Next = p;
		r = p;
	}
	
	r->next = NULL;
}

void ClearList(LinkList L; int i; ElemType e)
{
	LinkList p, q;
	
	p = (*L)->next;
	
	while ( p )
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	(*L)->next = NULL;
	
	return OK;
}
