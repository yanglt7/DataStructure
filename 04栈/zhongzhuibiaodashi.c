#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;
typedef struct 
{
	ElemType *base;
	ElemType *top;
	int stackSize;
} sqStack;

//初始化一个栈 
InitStack(sqStack *s) 
{
	s->top = s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType)); //动态分配内存 
	if( !s->base ) //如果内存分配失败，则退出 
		exit(0);

	s->top = s->base; //初始化栈顶和栈底指针相同 
	s->stackSize = STACK_INIT_SIZE;
}

//入栈操作 
Push(sqStack *s, ElemType e) 
{
	if( s->top - s->base >= STACK_INIT_SIZE ) //如果栈内元素已满，则追加内存 
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if( !s->base )
			exit(0);
	}

	*(s->top) = e;
	s->top++;
}

//出栈操作 
Pop(sqStack *s, ElemType *e)
{
	if( s->base == s->top ) //如果栈空，则直接返回 
		return;

	*e = *--(s->top);
}

//计算栈的长度 
int StackLen(sqStack s)
{
	return (s.top - s.base); //内存地址相减为长度 
}

int main()
{
	sqStack s;
	char c, e;

	InitStack( &s );

	printf("请输入中缀表达式，以#作为结束标志： ");
	scanf("%c", &c);

	while( c != '#' )
	{
		while( c >= '0' && c <= '9' ) //过滤数字 
		{
			printf("%c", c);
			scanf("%c", &c);
			if( c < '0' || c > '9') //使大于9的数字能够连续输出 
			{
				printf(" ");
			}
		}
		if( ')' == c )
		{
			Pop(&s, &e);
			while( '(' != e )
			{
				printf("%c ", e);
				Pop(&s, &e);
			}
		} 
		else if( '+' == c || '-' == c )
		{
			if ( !StackLen(s) )
			{
				Push(&s, c);
			}
			else 
			{
				do
				{
					Pop(&s, &e);
					if( '(' == e )
					{
						Push(&s, e);
					}
					else
					{
						printf("%c ", e);
					}
				}while( StackLen(s) && '(' !=e );
				Push(&s, c);
			}
		}
		else if( '(' ==c || '*' == c || '/' == c )
		{
			Push(&s, c);
		}
		else if( '#' == c )
		{
			break;
		}
		else
		{
			printf("\n出错：输入格式错误！\n");
			return -1;
		}
		scanf("%c", &c);
	} 
	
	while( StackLen(s) )
	{
		Pop(&s, &e);
		printf("%c ", e);
	}

	return 0;
}
