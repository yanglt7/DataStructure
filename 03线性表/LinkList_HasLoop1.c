//�Ƚϲ����ķ���
int HasLoop1(LinkList L) 
{
	LinkList cur1 = L; //������ cur1
	int pos1 = 0; // cur2 �Ĳ���
	
	while(cur1)
	{	//cur1 ������
		LinkList cur2 = L; //������ cur2
		int pos2 = 0; // cur2 �Ĳ���
		while(cur2)
		{	//cur2 ��㲻Ϊ��
			if(cur2 == cur1)
			{	//��cur1��cur2������ͬ���ʱ���߹��Ĳ���һ����˵��û�л�
				if(pos1 == pos2)
					break;
				else
				{
					printf("����λ���ڵ�%d����㴦\n", pos2);
					return 1; //�л�������1
				}
			}
			cur2 = cur2->next; //�������û�л���������һ�����
			pos2++;	//cur2��������
		}
		cur1 = cur1->next; //cur1�������һ�����
		pos1++; //cur1��������
	} 
	return 0;
}
