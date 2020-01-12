#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_INIT_SIZE 30
#define STACKINCREMENT 10
#define MAXBUFFER 20

typedef double ElemTypes;
typedef char ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackSize;
} sqStack;

typedef struct
{
	ElemTypes *base;
	ElemTypes *top;
	int stackSize;
} sqStacks;

void InitStack(sqStack *s)
{
	s->top = s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if ( !s->base )
	{
		exit(0);
	}
	s->base = s->top;
	s->stackSize = STACK_INIT_SIZE;
}

void InitStacks(sqStacks *s)
{
	s->top = s->base = (ElemTypes *)malloc(STACK_INIT_SIZE * sizeof(ElemTypes));
	if ( !s->base )
	{
		exit(0);
	}
	s->base = s->top;
	s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e)
{ 
	if ( s->top - s->base >= s->stackSize )
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if ( !s->base )
		{
			exit(0);
		}
	}

	*(s->top) = e;
	s->top++;
}

void Pushs(sqStacks *s, ElemTypes e)
{ 
	if ( s->top - s->base >= s->stackSize )
	{
		s->base = (ElemTypes *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemTypes));
		if ( !s->base )
		{
			exit(0);
		}
	}

	*(s->top) = e;
	s->top++;
}

void Pop(sqStack *s, ElemType *e)
{
	if( s->base == s->top )
	{
		return;
	}

	*e = *--(s->top);
}

void Popp(sqStack *s, ElemType *e)
{
	if( s->base == s->top )
	{
		return;
	}

	*e = *(s->base);
	s->base++;
}

void Pops(sqStacks *s, ElemTypes *e)
{
	if( s->base == s->top )
	{
		return;
	}

	*e = *--(s->top);
}

int StackLen(sqStack s)
{
	return (s.top - s.base);
}

int StackLens(sqStacks s)
{
	return (s.top - s.base);
}

int main()
{
 	sqStack s, p;
 	sqStacks q;
	char c, e;
 	double d, f;

    char str[MAXBUFFER];

	InitStack( &s );
	InitStack( &p );
	InitStacks( &q );

 	int i = 0;

	printf("请输入中缀表达式，以#作为结束标志： ");
	scanf("%c", &c);

	while( c != '#' )
	{
		while( c >= '0' && c <= '9' )
		{
			printf("%c", c);
			Push(&p, c);
			scanf("%c", &c);
			if( c < '0' || c > '9')
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
				Push(&p, e);
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
						Push(&p, e);
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
		Push(&p, e);
	}

 	// printf("请按逆波兰表达式输入待计算数据，数据与运算符之间用空格隔开，以#作为结束标志： \n");
 	// scanf("%c", &c);
 	Popp(&p, &c);
 	printf("p0:%c ", c);
 	while ( StackLen(p) )
 	{
        while ( c >= '0' && c <= '9' ) 
        {
            str[i++] = c;
            str[i] = '\0';
            d = atof(str); 
 			
 			Pushs(&q, d);
            printf("d=%f", d) ;
	
   		    i = 0;
   		    break;
        }

 		switch( c )
 		{
 			case '+':
 				Pops(&q, &f);
 				Pops(&q, &d);
 				Pushs(&q, d+f);
 				printf("d+f=%f ", d+f);
 				break;
 			case '-':
 				Pops(&q, &f);
 				Pops(&q, &d);
 				Pushs(&q, d-f);
 				printf("d-f=%f ", d-f);
 				break;
 			case '*':
 				Pops(&q, &f);
 				Pops(&q, &d);
 				Pushs(&q, d*f);
 				printf("d*f=%f ", d*f);
 				break;
 			case '/':
 				Pops(&q, &f);
 				Pops(&q, &d);
 				if ( f != 0 )
 				{
 					Pushs(&q, d/f);
 					printf("d/f=%f ", d/f);
 				}
 				else
 				{
 					printf("出错：除数为零！\n");
 					return -1;
 				}
 				break;
 		}

 		// scanf("%c", &c);
 		Popp(&p, &c);
 		printf("p1:%c ", c);
 	} 
 	

 	Pops(&q, &d);
 	printf("\n最终的计算结果为： %f\n", d);

 	return 0;
 }
