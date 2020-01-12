#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_INIT_SIZE 30
#define STACKINCREMENT 10
#define MAXBUFFER 20

typedef double ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackSize;
} sqStack;

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

void Pop(sqStack *s, ElemType *e)
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

 int main()
 {
 	sqStack s;
 	char c;
 	double d, e;
 	int i = 0;

 	char str[MAXBUFFER];

 	InitStack( &s );

 	printf("请按逆波兰表达式输入待计算数据，数据与运算符之间用空格隔开，以#作为结束标志： \n");
 	scanf("%c", &c);

 	while ( c != '#' )
 	{
 		while ( isdigit(c) || c == '.' ) //用于过滤数字
 		{
 	 		str[i++] = c;
	 		str[i] = '\0';
	 		if ( i >= 10 )
	 		{
	 			printf("出错：输入的单个数据过大！\n");
	 			return -1;
	 		}
	 		scanf("%c", &c);
	 		if ( c == ' ')
	 		{
	 			d = atof(str); //将字符串转换为浮点数
	 			Push(&s, d);
	 			i = 0;
	 			break;
	 		}		
 		}

 		switch( c )
 		{
 			case '+':
 				Pop(&s, &e);
 				Pop(&s, &d);
 				Push(&s, d+e);
 				break;
 			case '-':
 				Pop(&s, &e);
 				Pop(&s, &d);
 				Push(&s, d-e);
 				break;
 			case '*':
 				Pop(&s, &e);
 				Pop(&s, &d);
 				Push(&s, d*e);
 				break;
 			case '/':
 				Pop(&s, &e);
 				Pop(&s, &d);
 				if ( e != 0)
 				{
 					Push(&s, d/e);
 				}
 				else
 				{
 					printf("出错：除数为零！\n");
 					return -1;
 				}
 				break;
 		}

 		scanf("%c", &c);
 	}

 	Pop(&s, &d);
 	printf("\n最终的计算结果为： %f\n", d);

 	return 0;
 }
