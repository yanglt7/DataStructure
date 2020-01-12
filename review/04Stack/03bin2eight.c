#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE  100
#define STACKINCREMENT 10

typedef char ElemType;

typedef struct 
{
	ElemType *base;
	ElemType *top;
	ElemType stackSize;
} sqStack;

void InitStack(sqStack *s)
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if ( !s->base )
		exit(0);
	
	s->top = s->base;
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
	ElemType c, e;
	sqStack s, p;
	int slen, plen, i;
	int sum = 0;
	
	InitStack(&s);
	InitStack(&p);
	
	printf("请输入需要转换的二进制数，并以#表示结束：\n");
	scanf("%c", &c);
	
	while ( c!= '#' )
	{
		Push(&s, c);
		scanf("%c", &c);
	}
	
	getchar(); // 把 '\n' 从缓冲区去掉 
	
	slen = StackLen(s);
	printf("二进制栈的当前容量是：%d\n", slen);
	
	int cnt = 0;
	int num = slen/3;
	int j = 0;
	
	for ( i=0; i<slen; i++ )
	{
		j = i%3;
		int l = slen%3;
		
		if ( num > 0 )
		{
			Pop(&s, &c);
			sum = sum + (c-48) * pow(2, j);
			cnt++;
			if ( cnt == 3 )
			{
				num --;
				Push(&p, sum);
				sum = 0;
				cnt = 0;
			}
		}
		else
		{
			Pop(&s, &c);
			sum = sum + (c-48) * pow(2, j);
			cnt++;
			if ( cnt==l )
			{
				Push(&p, sum);
			}
		}
	}
	
	plen = StackLen(p);
	printf("八进制栈的当前容量是：%d\n", slen);
	printf("转化为八进制数是：");
	
	int k;
	for ( k=0; k<plen; k++ )
	{
		Pop(&p, &sum);
		printf("%d", sum);
	}
	
	return 0;
}
