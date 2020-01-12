// 顺序查找。a为要查找的数组，n为要查找的数组的长度，key为要查找的关键字
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

// 顺序查找优化方案，a为要查找的数组，n为要查找的数组的长度，key为要查找的关键字
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
