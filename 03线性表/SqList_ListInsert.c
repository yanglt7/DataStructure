//初始条件，顺序线性表L已存在，1<=i<=ListLength(L).
//操作结果：在L中第i个位置之前插入新的数据元素e，L长度+1.

Status ListInsert（SqList *L, int i, ElemType e)
{
	int k;
	
	if (L->length == MAXSIZE)
	{
		return ERROR;
	}
	if (i<1 || i>L->length+1)
	{
		return ERROR;
	}
	if (i<=L->length)
	{
		for(k=L->length-1;k>=i-1;k--) {
			L->data[k+1] = L->data[k];
		}
	}
	
	L->data[i-1] = e;
	L->Length++;
	
	return OK;
 } 
