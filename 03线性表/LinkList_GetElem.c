Status GetElem(LinkList L, int i, ELemType *e)
{
	iny j;
	LinkList p;

	P = L->next;
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

	*e = p->data;

	return OK;
}
