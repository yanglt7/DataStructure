// ��ÿ��з������±� 
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	if(space[0].cur)
	{
		space[0].cur = space[i].cur;//��������һ������������Ϊ����
	}

	return i;
}

//�ھ�̬����L�е�i=2��Ԫ��֮ǰ�����µ�����Ԫ��e
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int j, k, l;

	k = MAXSIZE-1;  // ��������һ��Ԫ�� 
	if(i<1 || i>ListLength(L)+1)
	{
		return ERROR;
	}
         
	j = Malloc_SLL(L);
	if(j)
	{
		L[j].data = e;
		for(l=1; l<=i-1; l++)
		{
			k = L[k].cur;  // ���һ��Ԫ�ص��α�ָ���һ��Ԫ�� 
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
		
		return OK;
	}

	return ERROR;
}



//ɾ����L�еĵ�i������Ԫ��
Status ListDelete(StaticLinkList L, int i)
{
	int j, k;

	k = MAXSIZE-1;

	if(i<1 || i>ListLength(L))
	{
		return ERROR;
	}

	for(j=1; j<=i-1; j++)
	{
		k = L[k].cur;
	}

	j = L[k].cur;
	L[k].cur = L[j].cur;

	Free_SLL(L,j);

	return OK;
}

//���±�Ϊk�Ŀ��н����յ���������
void Free_SLL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

//����L������Ԫ�ظ���
int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE-1].cur;

	while(i)
	{
		i = L[i].cur;
		j++
	}

	return j;
} 

