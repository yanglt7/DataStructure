#define MAX_TREE_SIZE 100

typedef char ElemType;

//���ӽ��
typedef struct CTNode
{
	int child;  //���ӽ����±�
	struct CTNode *next; //ָ����һ�����ӽ���ָ��
} *ChildPtr;

//��ͷ�ṹ
typedef struct 
{
	ElemType data;  //��������еĽ�������
	int parent;     //���˫�׵��±�
	ChildPtr firstchild;  //ָ���һ�����ӵ�ָ��
} CTBox;

//���ṹ
typedef struct 
{
	CTBox nodes[MAX_TREE_SIZE]; //�������
	int r,n;
};

