// ��ʽ�洢�ṹ 
typedef struct stackNode
{
	ElemType data; // ���ջ������ 
	struct stackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top; // top ָ�� 
	int cnt; // ջԪ�ؼ����� 
}

//��ջ���� 
Status Push(LinkStack *s, ElemType e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(stackNode));
	
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->cnt++;
	
	return OK;
}

// ��ջ���� 
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
