#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_INIT_SIZE 30
#define STACKINCREMENT 10
#define MAXBUFFER 20

typedef char ElemType;
typedef struct 
{
	ElemType *base;
	ElemType *top;
	int stackSize;
} sqStack;

void InitStack(sqStack *s)
{
	s->top = s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if ( !s->top )
		exit(0);
	
	// s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e)
{
	if ( s->top - s->base >= s->stackSize )
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if ( !s->base )
			exit(0);
		
		s->top = s->base + s->stackSize;
		s->stackSize = s->stackSize + STACKINCREMENT;
	}
	
	*(s->top) = e;
	s->top++;
}

void Pop(sqStack *s, ElemType *e)
{
	if ( s->top == s->base )
		return;
	
	*e = *--(s->top);
}

int StackLen(sqStack s)
{
	return ( s.top - s.base );
}

int main()
{
	sqStack s;
	char c, e;
	
	InitStack(&s);
	
	printf("请输入中缀表达式，并以#作为结束标志：\n");
	scanf("%c", &c);
	
	while ( c != '#' )
	{
		while ( isdigit(c) )
		{
			printf("%c", c);
			scanf("%c", &c);
			if ( !isdigit(c) )
			{
				printf(" ");
			}
		}
		if ( '(' == c || '*' == c || '/' == c )
		{
			Push(&s, c);
		}
		else if ( ')' == c )
		{
			Pop(&s, &e);
			while ( '(' != e )
			{
				printf("%c ", e);
				Pop(&s, &e);
			}
		}
		else if ( '+' == c || '-' == c )
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
					if ( '(' == e )
					{
						Push(&s, e);
					}
					else 
					{
						printf("%c ", e);
					}
				} while ( '(' != e && StackLen(s) );
				Push(&s, c);
			}
		}
		else if ( '#' == c )
		{
			break;
		}
		else 
		{
			printf("\n输入格式错误！\n");
			return -1;
		}
		scanf("%c", &c);
	}
	
	while ( StackLen(s) )
	{
		Pop(&s, &e);
		printf("%c ", e);
	}
	
	return 0;
}
