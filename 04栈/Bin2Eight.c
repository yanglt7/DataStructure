#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT    10

typedef char ElemType;
typedef struct 
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if ( ! s->base )
		exit(0);

	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e)
{
	if( s->top - s->base >= s->stackSize )
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if ( ! s->base )
			exit(0);
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
	return (s.top - s.base);
}

int main()
{
	ElemType c,e;
	sqStack s, p;
	int len, len2, i, sum = 0;

	InitStack(&s);
	InitStack(&p);

	printf("请输入二进制数，输入#符号表示结束！\n");
	scanf("%c", &c);
	while ( c != '#' )
	{
		Push(&s, c);
		scanf("%c", &c);
	}

	getchar(); //把'\n'从缓冲区去掉

	len = StackLen(s);
	printf("栈的当前容量是：%d\n", len);
	
	int count = 0;
	int num = len/3;
	int j = 0;
	for (i=0; i<len; i++)
	{
		j = i%3;
		int l = len%3;
		
		if ( num > 0 )
		{	
			Pop(&s, &c);
			sum = sum + (c-48) * pow(2, j);
			count++;
			if ( count == 3 )
			{
				num--;
				Push(&p, sum);
				sum = 0;
				count = 0;
			}
		}
		else 
		{ 
			Pop(&s, &c);
			sum = sum + (c-48) * pow(2, j);
			count++; 
			if ( count == l )
			{
				Push(&p, sum);
			}
		}
	}
		
	len2 = StackLen(p);
	printf("八进制栈的当前容量是：%d\n", len2);	 
	printf("转换为八进制数是：");
	
	int k;
	for ( k=0; k<len2; k++ )	
	{
		Pop(&p, &sum);
		printf("%d", sum);
	}
		
	printf("\n");
	
	return 0;
}
