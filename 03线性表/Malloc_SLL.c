int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	if(space[0].cur)
	{
		space[0].cur = space[i].cur;//把它的下一个分量用来作为备用
	}

	return i;
}
