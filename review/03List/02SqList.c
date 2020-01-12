// ���Ա�˳��洢�Ľṹ���� 
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct 
{
	ElemType data[MAXSIZE];
	int length; //���Ա�ǰ���� 
} SqList;


typedef int Status;

// Status �Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��
// ��ʼ������˳�����Ա�L�Ѿ����ڣ� 1<=i<=ListLength(L)
// ����������� e ���� L �е� i ������Ԫ�ص�ֵ 

Status GetElem(SqList L, int i, ElemType *e)
{
	if ( L.length==0 || i<1 || i>L.length )
	{
		return ERROR;
	}
	*e = L.data[i-1];
	
	return OK;
}


// ��ʼ������˳�����Ա�L�Ѿ����ڣ�1<=i<=ListLength(L)
// �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L����+1

Status ListInsert(SqList *L, int i, ELemType e)
{
	int k;
	
	if ( L->Length == MAXSIZE ) // ˳�����Ա��Ѿ����� 
	{
		return ERROR;
	}
	if ( i<1 || i > L->Length+1 ) // ��i���ڷ�Χ��
	{
		return ERROR;
	}
	if ( i <= L->Length )
	{
		for ( k=L->Length-1; k>i-1; k-- )
		{
			L->data[k+1] = L->data[k];
		}
	}
	
	L->data[i-1] = e; // ����Ԫ�ز���
	L->Length++; 
	
	return OK;
}


// ��ʼ������˳�����Ա��Ѿ����ڣ�1<=i<=ListLength;
// ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ�� 

Status ListDelete(SqList *L, int i; ElemType *e)
{
	int k;
	
	if ( L->Length == 0 )
	{
		return ERROR;
	}
	if ( i<1 || i>L->Length )
	{
		return ERROR;
	}
	
	*e = L->data[i-1];
	
	if ( i < L->Length )
	{
		for ( k=i; k<L->Length; k++ )
		{
			L->data[k-1] = L->data[k];
		}
	}
	
	L->Length--;
	
	return OK;
}
