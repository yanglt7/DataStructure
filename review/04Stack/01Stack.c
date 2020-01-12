// 栈的顺序存储结构
typedef struct
{
	ElemType *base; // 指向栈底的指针变量
	ElemType *top; // 指向栈顶的指针变量
	int stackSize; // 栈的当前可用最大容量 
 } sqStack;

// 创建一个栈
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

// 入栈操作
#define STACKINCREMENT 10

Push(sqStack *s, ElemType e)
{
	// 如果栈满，追加空间
	if ( s->top - s->base >= stackSize )
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
			if ( !s->base )
			{
				exit(0);
			}
		s->top = s->base + s->stackSize; // 设置栈顶
		s->stackSize = s->stackSize + STACKINCREMENT; // 设置栈的最大容量 
	}
	
	*(s->top) = e;
	s->top++; 
} 

// 出栈操作
Pop(sqStack *s, ElemType *e)
{
	if ( s->top == s->base )
	{
		return;
	}
	
	*e = *--(s->top);
} 

// 清空一个栈
ClearStack(sqStack *s)
{
	s=>top = s->base;
 } 
 
// 销毁一个栈
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
 
// 计算栈的当前容量
int StackLen(sqStack s)
{
	return ( s.top - s.base );
}
