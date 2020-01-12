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
	char c;
	double d, e;
	int i = 0;
	
	InitStack(&s);
	
	char str[MAXBUFFER];
	
	printf("请输入逆波兰表达式，并以#表示结束！\n");
	scanf("%c", &c);
	
	while ( c != '#' )
	{
				
		while ( isdigit(c) || c == '.' )
		{
			str[i++] = c;
			str[i] = '\0'; 
			if ( i >= MAXBUFFER )
			{
				printf("\n出错，单个数据过大！\n");
				return -1;
			} 
			scanf("%c", &c);
			if ( c== ' ' )
			{
				d = atof(str);
				Push(&s, d);
				i = 0;
				break;
			}
		}
		
		switch (c)
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
				if ( e != 0 )
				{
					Push(&s, d/e);
				}
				else
				{
					printf("\n出错，除数为零！\n"); 
				}
				break;
		}
		
		scanf("%c", &c);
	}
	
	Pop(&s, &d);
	printf("\n计算结果为：%f\n", d);
	
	return 0;
}
