#include <iostream>
using namespace std;
// ��������㶨��
struct Node
{
	int data;			   // ������
	Node *lChild, *rChild; // ָ����
};
// ����������
struct BinTree
{
	Node *root;
};
// �����ն�����
void Create(BinTree &T)
{
	T.root = NULL;
}
// �п�
int IsEmpty(BinTree T)
{
	if (T.root == NULL)
		return 1;
	else
		return 0;
}
// �������������
void Create(BinTree &T, int x)
{
	Node *NewNode, *p;
	NewNode = new Node;		// �½�������ڴ�
	NewNode->data = x;		// �½��������ֵ
	NewNode->lChild = NULL; // �½����ָ����ֵ
	NewNode->rChild = NULL; // �½����ָ����ֵ
	int flag = 0;			// �½��������ʶ,flag=0��ʾδ����
	if (IsEmpty(T))			// ���������Ϊ��
		T.root = NewNode;
	else // ����������ǿ�
	{
		p = T.root;	  // ̽��ָ��ָ������
		while (!flag) // ���½��δ����
		{
			if (x < p->data)		   // ����½���ֵС��˫�׽���ֵ
			{						   // ����������
				if (p->lChild == NULL) // ���������Ϊ��
				{
					p->lChild = NewNode; // �½���Ϊ������
					flag = 1;			 // �½������
				}
				else			   // ����������ǿ�
					p = p->lChild; // ̽��ָ����������
			}
			else					   // ����½���ֵ����˫�׽���ֵ
			{						   // ����������
				if (p->rChild == NULL) // ���������Ϊ��
				{
					p->rChild = NewNode; // �½���Ϊ������
					flag = 1;			 // �½������
				}
				else
					p = p->rChild; // ̽��ָ����������
			}
		}
	}
}
// ǰ�����
void PreOrder(Node *p)
{
	if (p != NULL)
	{
		cout << p->data << " "; // ��������
		PreOrder(p->lChild);	// ����������
		PreOrder(p->rChild);	// ����������
	}
}
// �������
void InOrder(Node *p)
{
	if (p != NULL)
	{
		InOrder(p->lChild);		// ����������
		cout << p->data << " "; // ��������
		InOrder(p->rChild);		// ����������
	}
}
// ������
int main()
{
	BinTree T; // ���������
	Create(T); // �����ն�����
	char c;
	int x;
	printf("������������ֵ(�ÿո����,�س�����)\n");
	while (scanf("%d%c", &x, &c)) // while��������ĵ�һ���÷�
	{
		Create(T, x); // �������������
		if (c == '\n')
			break;
	}
	cout << "ǰ�����Ϊ ";
	PreOrder(T.root);
	cout << endl;
	cout << "�������Ϊ ";
	InOrder(T.root);
	cout << endl;
	return 0;
}