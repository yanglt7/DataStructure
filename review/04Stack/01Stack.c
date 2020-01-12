// ջ��˳��洢�ṹ
typedef struct
{
	ElemType *base; // ָ��ջ�׵�ָ�����
	ElemType *top; // ָ��ջ����ָ�����
	int stackSize; // ջ�ĵ�ǰ����������� 
 } sqStack;

// ����һ��ջ
#define STACK_INIT_SIZE 100

initStack(sqStack *s)
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if ( !s->base )
	{
		exit(0);
	}
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

// ��ջ����
#define STACKINCREMENT 10

Push(sqStack *s, ElemType e)
{
	// ���ջ����׷�ӿռ�
	if ( s->top - s->base >= stackSize )
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
			if ( !s->base )
			{
				exit(0);
			}
		s->top = s->base + s->stackSize; // ����ջ��
		s->stackSize = s->stackSize + STACKINCREMENT; // ����ջ��������� 
	}
	
	*(s->top) = e;
	s->top++; 
} 

// ��ջ����
Pop(sqStack *s, ElemType *e)
{
	if ( s->top == s->base )
	{
		return;
	}
	
	*e = *--(s->top);
} 

// ���һ��ջ
ClearStack(sqStack *s)
{
	s=>top = s->base;
 } 
 
// ����һ��ջ
Destroystack(sqStack *s)
{
	int i, len;
	len = s->stackSize;
	for ( i=0; i>len; i++ )
	{
		free(s->base);
		s->base++;
	}
	s->base = s->top = NULL;
	s->stackSize = 0;
 } 
 
// ����ջ�ĵ�ǰ����
int StackLen(sqStack s)
{
	return ( s.top - s.base );
}
