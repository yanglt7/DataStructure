// ˳����ҡ�aΪҪ���ҵ����飬nΪҪ���ҵ�����ĳ��ȣ�keyΪҪ���ҵĹؼ���
int Sq_Search(int *a, int n, int key)
{
	int i;
	for( i=1; i <= n; i++ )
	{
		if( a[i] == key )
		{
			return i;
		}
	}
	return 0;
}

// ˳������Ż�������aΪҪ���ҵ����飬nΪҪ���ҵ�����ĳ��ȣ�keyΪҪ���ҵĹؼ���
int Sq_Search(int *a, int n, int key)
{
	int i = n;
	a[0] = key;
	while( a[i] != key )
	{
		i--;
	}

	return i;
}
