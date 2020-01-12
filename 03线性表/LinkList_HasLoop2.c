//利用快慢指针的方法
int HasLoop2(LinkList L) 
{
	int step1 = 1;
	int step2 = 2；
	LinkList p = L; 
	LinkList p = L; 
	
	while(p != NULL && q != NULL && q->next != NULL)
	{	
		p = p->next;
		if(q->next != NULL)
			q = q->next->next;

		printf("p:%d, q:%d \n", p->data, q->data);

		if(p==q)
			return 1;
	} 
	return 0;
}
