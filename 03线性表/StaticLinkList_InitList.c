Status InitList(StaticLinkList space)
{
	int i;
	for(i=0; i<MAXSIZE-1; i++)
	{
		space[i].cur = i+1;
	}
	space[MAXSIZE-1].cur = 0;

	return OK;
}
