#include <iostream>
using namespace std;
#define MaxSize 100 // ˳��ջ���������

//�������ı���

// ��㶨��
struct Node
{
	char data;			   // ������
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
// ���п�
int IsEmpty(BinTree T)
{
	if (T.root == NULL)
		return 1;
	else
		return 0;
}
// �������������
void Create(char GenList[], BinTree &T)
{
	Node *stack[MaxSize], *NewNode, *p; // ���׽��˳��ջ,�½��,̽��ָ��
	int top = -1;						// ��ջ��
	int k, i = 0;						// k=1����������,k=2����������,i������ַ��±�
	char ch;
	do
	{
		ch = GenList[i]; // ��ȡ������i���ַ�
		switch (ch)
		{
		case '(':					// ����������
			stack[++top] = NewNode; // �½����ջ
			k = 1;
			break;
		case ')': // ����������
			top--;
			break; // ջ������ջ
		case ',':  // ��������
			k = 2;
			break;
		default:					// �����ַ�
			NewNode = new Node;		// �½�������ڴ�
			NewNode->data = ch;		// �½��������ֵ
			NewNode->lChild = NULL; // �½����ָ����ֵ
			NewNode->rChild = NULL; // �½����ָ����ֵ
			if (IsEmpty(T))			// �����Ϊ��
				T.root = NewNode;	// �½����Ϊ�����
			if (k == 1)
			{
				p = stack[top];		 // ��ȡջ�����
				p->lChild = NewNode; // ��ջ���������ָ���½��
			}
			else if (k == 2)
			{
				p = stack[top];		 // ��ȡջ�����
				p->rChild = NewNode; // ��ջ���������ָ���½��
			}
		}
		i++;					  // i��1
	} while (GenList[i] != '\0'); // ��һ�������������
}
// �ǵݹ�ǰ������㷨
void PreOrder(Node *p)
{
	Node *stack[MaxSize];  // ���׽��˳��ջ
	int top = -1;		   // ��ջ��
	while (p || top != -1) // ��p�����ָ�ǿջ�ջ�ǿ�ʱ
	{
		if (p) // ���p��ָ���ǿ�
		{
			cout << p->data;  // ���p��ֵ
			stack[++top] = p; // p��ָ�����ջ
			p = p->lChild;	  // p��������
		}
		else // ���p�����ָ���Ϊ��
		{
			p = stack[top--]; // pָ��ջ�����,ջ������ջ
			p = p->rChild;	  // p��������
		}
	}
}
// �ǵݹ���������㷨
void InOrder(Node *p)
{
	Node *stack[MaxSize];  // ���׽��˳��ջ
	int top = -1;		   // ��ջ��
	while (p || top != -1) // ��p�����ָ�ǿջ�ջ�ǿ�ʱ
	{
		if (p) // ���p��ָ���ǿ�
		{
			stack[++top] = p; // p��ָ�����ջ
			p = p->lChild;	  // p��������
		}
		else // ���p��ָ���Ϊ��
		{
			p = stack[top--]; // pָ��ջ�����,ջ������ջ
			cout << p->data;  // ���p��ֵ
			p = p->rChild;	  // p��������
		}
	}
}
// ������
int main()
{
	char GenList[] = "A(B(C(,E),D(F,G)))"; // ��������
	BinTree T;							   // ���������
	Create(T);							   // �����ն�����
	Create(GenList, T);					   // ����������
	cout << "ǰ�����Ϊ ";
	PreOrder(T.root);
	cout << endl;
	cout << "�������Ϊ ";
	InOrder(T.root);
	cout << endl;
	system("pause");
	return 0;
}

// ǰ�����
// void PreOrder(Node* p)
//{
//	if (p != NULL)
//	{
//		cout << p->data;//��������
//		PreOrder(p->lChild);//����������
//		PreOrder(p->rChild); //����������
//	}
// }

// �������
// ������������������������������������һֱ���£�ֱ���޷�ǰ��ʱ���˵�˫�׽�㣬��������������һֱ���¡����������Ҳ�����˾��˻��ϲ�����㣬�ظ����С��ҵ�˳�������
// void InOrder(Node* p)
//{
//	if (p != NULL)
//	{
//		InOrder(p->lChild); //����������
//		cout << p->data; //��������
//		InOrder(p->rChild);//����������
//	}
// }

// ���������˳��Ϊ���������������������������������ǰ������෴�����ǰ����������Ľ�㶼������Ŵ���������
// void PostOrder(Node* p)
//{
//	if (p != NULL)
//	{
//		PostOrder(p->lChild);//����������
//		PostOrder(p->rChild); //����������
//		cout << p->data; //��������
//	}
// }
