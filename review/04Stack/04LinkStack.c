// 链式存储结构 
typedef struct stackNode
{
	ElemType data; // 存放栈顶数据 
	struct stackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top; // top 指针 
	int cnt; // 栈元素计数器 
}

//进栈操作 
Status Push(LinkStack *s, ElemType e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(stackNode));
	
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->cnt++;
	
	return OK;
}

// 出栈操作 
Status Pop(LinkStack *s, ElemType *e)
{
	LinkStackPtr p;
	if ( StackEmpty(*s) )
		return ERROR;
			
	*e = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->cnt--;
	
	return OK;
}
