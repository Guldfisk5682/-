#include <iostream>
using namespace std;
// 二叉树结点定义
struct Node
{
	int data;			   // 数据域
	Node *lChild, *rChild; // 指针域
};
// 二叉树定义
struct BinTree
{
	Node *root;
};
// 创建空二叉树
void Create(BinTree &T)
{
	T.root = NULL;
}
// 判空
int IsEmpty(BinTree T)
{
	if (T.root == NULL)
		return 1;
	else
		return 0;
}
// 创建排序二叉树
void Create(BinTree &T, int x)
{
	Node *NewNode, *p;
	NewNode = new Node;		// 新结点申请内存
	NewNode->data = x;		// 新结点数据域赋值
	NewNode->lChild = NULL; // 新结点左指针域赋值
	NewNode->rChild = NULL; // 新结点右指针域赋值
	int flag = 0;			// 新结点入树标识,flag=0表示未入树
	if (IsEmpty(T))			// 如果二叉树为空
		T.root = NewNode;
	else // 如果二叉树非空
	{
		p = T.root;	  // 探测指针指向根结点
		while (!flag) // 当新结点未入树
		{
			if (x < p->data)		   // 如果新结点的值小于双亲结点的值
			{						   // 进入左子树
				if (p->lChild == NULL) // 如果左子树为空
				{
					p->lChild = NewNode; // 新结点成为左子树
					flag = 1;			 // 新结点入树
				}
				else			   // 如果左子树非空
					p = p->lChild; // 探测指针向左下移
			}
			else					   // 如果新结点的值大于双亲结点的值
			{						   // 进入右子树
				if (p->rChild == NULL) // 如果右子树为空
				{
					p->rChild = NewNode; // 新结点成为右子树
					flag = 1;			 // 新结点入树
				}
				else
					p = p->rChild; // 探测指针向右下移
			}
		}
	}
}
// 前序遍历
void PreOrder(Node *p)
{
	if (p != NULL)
	{
		cout << p->data << " "; // 访问树根
		PreOrder(p->lChild);	// 遍历左子树
		PreOrder(p->rChild);	// 遍历右子树
	}
}
// 中序遍历
void InOrder(Node *p)
{
	if (p != NULL)
	{
		InOrder(p->lChild);		// 遍历左子树
		cout << p->data << " "; // 访问树根
		InOrder(p->rChild);		// 遍历右子树
	}
}
// 主函数
int main()
{
	BinTree T; // 定义二叉树
	Create(T); // 创建空二叉树
	char c;
	int x;
	printf("输入二叉树结点值(用空格隔开,回车结束)\n");
	while (scanf("%d%c", &x, &c)) // while键盘输入的第一种用法
	{
		Create(T, x); // 创建排序二叉树
		if (c == '\n')
			break;
	}
	cout << "前序遍历为 ";
	PreOrder(T.root);
	cout << endl;
	cout << "中序遍历为 ";
	InOrder(T.root);
	cout << endl;
	return 0;
}