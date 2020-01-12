// 判断单链表是否有环 

//比较步数的方法
int HasLoop1(LinkList L) 
{
	LinkList cur1 = L; //定义结点 cur1
	int pos1 = 0; // cur2 的步数
	
	while(cur1)
	{	//cur1 结点存在
		LinkList cur2 = L; //定义结点 cur2
		int pos2 = 0; // cur2 的步数
		while(cur2)
		{	//cur2 结点不为空
			if(cur2 == cur1)
			{	//当cur1和cur2到达相同结点时，走过的步数一样，说明没有环
				if(pos1 == pos2)
					break;
				else
				{
					printf("环的位置在第%d个结点处\n", pos2);
					return 1; //有环并返回1
				}
			}
			cur2 = cur2->next; //如果发现没有环，继续下一个结点
			pos2++;	//cur2步数递增
		}
		cur1 = cur1->next; //cur1继续向后一个结点
		pos1++; //cur1步数递增
	} 
	return 0;
}

// 快慢指针的方法

int HasLoop2(LinkList L)
{
	int step1 = 0;
	int step2 = 0;
	LinkLint p = L;
	LinkLint q = L;
	
	while ( p != NULL && q!=NULL && q->next != NULL )
	{
		p = p->next;
		if ( q->next != NULL )
		{
			q = q->next->next;
		}
		
		printf("p:%d, q:%d \n", p->data, q->data );
		
		if ( p==q )
		{
			return 1;
		}
	}
	return 0;
} 

