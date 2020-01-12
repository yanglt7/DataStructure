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

//��ʼ��һ��ջ 
InitStack(sqStack *s) 
{
	s->top = s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType)); //��̬�����ڴ� 
	if( !s->base ) //����ڴ����ʧ�ܣ����˳� 
		exit(0);

	s->top = s->base; //��ʼ��ջ����ջ��ָ����ͬ 
	s->stackSize = STACK_INIT_SIZE;
}

//��ջ���� 
Push(sqStack *s, ElemType e) 
{
	if( s->top - s->base >= STACK_INIT_SIZE ) //���ջ��Ԫ����������׷���ڴ� 
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if( !s->base )
			exit(0);
	}

	*(s->top) = e;
	s->top++;
}

//��ջ���� 
Pop(sqStack *s, ElemType *e)
{
	if( s->base == s->top ) //���ջ�գ���ֱ�ӷ��� 
		return;

	*e = *--(s->top);
}

//����ջ�ĳ��� 
int StackLen(sqStack s)
{
	return (s.top - s.base); //�ڴ��ַ���Ϊ���� 
}

int main()
{
	sqStack s;
	char c, e;

	InitStack( &s );

	printf("��������׺���ʽ����#��Ϊ������־�� ");
	scanf("%c", &c);

	while( c != '#' )
	{
		while( c >= '0' && c <= '9' ) //�������� 
		{
			printf("%c", c);
			scanf("%c", &c);
			if( c < '0' || c > '9') //ʹ����9�������ܹ�������� 
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
			printf("\n���������ʽ����\n");
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
