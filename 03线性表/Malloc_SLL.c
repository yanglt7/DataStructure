int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	if(space[0].cur)
	{
		space[0].cur = space[i].cur;//��������һ������������Ϊ����
	}

	return i;
}
