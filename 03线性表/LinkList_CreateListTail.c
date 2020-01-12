void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;

	srand(time(0));

	*L = (LinkList)malloc(sizeof(Node));
	r = *L;

	for(i=0; i<n; i++) 
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = rand()%100+1;
		r->next = p;
		r = p;
	}
	
	r->next = NULL;
}
