// ����A��B�����ǿ�ѭ������Ϊһ��ѭ������ 
//A ��B Ϊβָ�� 
void Connect(LinkList A, LinkList B)
{
	LinkList A;
	LinkList B;
	
	LinkList p = A->Next; // ����A����ͷ����λ�� 
	
	A->next = B->next->next; // A��βָ��ָ��B�ĵ�һ����� 
	A->next = B->next; // B��βָ��ָ��A��ͷ��� 
	
	free(B->next); // �ͷ�B��ͷ���
	
	B->next = p;
	
	return B; // ������ѭ�������βָ�� 
}
