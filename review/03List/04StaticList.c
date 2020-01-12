// 获得空闲分量的下标 
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	if(space[0].cur)
	{
		space[0].cur = space[i].cur;//把它的下一个分量用来作为备用
	}

	return i;
}

//在静态链表L中第i=2个元素之前插入新的数据元素e
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int j, k, l;

	k = MAXSIZE-1;  // 数组的最后一个元素 
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
			k = L[k].cur;  // 最后一个元素的游标指向第一个元素 
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
		
		return OK;
	}

	return ERROR;
}



//删除在L中的第i个数据元素
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

//将下标为k的空闲结点回收到备用链表
void Free_SLL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

//返回L中数据元素个数
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

