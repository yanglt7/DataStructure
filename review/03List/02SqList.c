// 线性表顺序存储的结构代码 
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct 
{
	ElemType data[MAXSIZE];
	int length; //线性表当前长度 
} SqList;


typedef int Status;

// Status 是函数的类型，其值是函数结果状态代码，如OK等
// 初始条件：顺序线性表L已经存在， 1<=i<=ListLength(L)
// 操作结果：用 e 返回 L 中第 i 个数据元素的值 

Status GetElem(SqList L, int i, ElemType *e)
{
	if ( L.length==0 || i<1 || i>L.length )
	{
		return ERROR;
	}
	*e = L.data[i-1];
	
	return OK;
}


// 初始条件：顺序线性表L已经存在，1<=i<=ListLength(L)
// 操作结果：在L中第i个位置之前插入新的数据元素e，L长度+1

Status ListInsert(SqList *L, int i, ELemType e)
{
	int k;
	
	if ( L->Length == MAXSIZE ) // 顺序线性表已经满了 
	{
		return ERROR;
	}
	if ( i<1 || i > L->Length+1 ) // 当i不在范围内
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
	
	L->data[i-1] = e; // 将新元素插入
	L->Length++; 
	
	return OK;
}


// 初始条件：顺序线性表已经存在，1<=i<=ListLength;
// 操作结果：删除L的第i个数据元素，并用e返回其值。 

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
