Status ListDelete(LinkList *L, int i, ELemType *e)
{
	iny j;
	Linklist p,q;

	p = *L;
	j = 1;

	while(p->next && j<i)
	{
		p = p->next;
		++j;
	}

	if (!(p->next) || j>i)
	{
		return ERROR;
	}

	q = p->next;
	p->next = q->next;

	*e = q->data;
	free(q);
	
	return OK;
}
