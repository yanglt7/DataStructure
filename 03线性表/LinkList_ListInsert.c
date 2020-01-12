Status ListInsert(LinkList *L, int i, ELemType e)
{
	iny j;
	LinkList p;

	P = *L;
	j = 1;

	while(p && j<i)
	{
	p = p->next;
	++j;
	}

	if (!p || j>i) 
	{
		return ERROR;
	}

	s = (LinkList)malloc(sizeof(Node));
	s->data = e;

	s->next = p->next;
	p->next = s;

	return OK;
}
