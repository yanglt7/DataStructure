// 连接A、B两个非空循环链表为一个循环链表 
//A 、B 为尾指针 
void Connect(LinkList A, LinkList B)
{
	LinkList A;
	LinkList B;
	
	LinkList p = A->Next; // 保存A链表头结点的位置 
	
	A->next = B->next->next; // A的尾指针指向B的第一个结点 
	A->next = B->next; // B的尾指针指向A的头结点 
	
	free(B->next); // 释放B的头结点
	
	B->next = p;
	
	return B; // 返回新循环链表的尾指针 
}
