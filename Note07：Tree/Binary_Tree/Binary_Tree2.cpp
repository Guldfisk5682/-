#include <iostream>
using namespace std;
#define MaxSize 100 // 顺序栈的最大容量

//二叉树的遍历

// 结点定义
struct Node
{
	char data;			   // 数据域
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
// 树判空
int IsEmpty(BinTree T)
{
	if (T.root == NULL)
		return 1;
	else
		return 0;
}
// 广义表创建二叉树
void Create(char GenList[], BinTree &T)
{
	Node *stack[MaxSize], *NewNode, *p; // 简易结点顺序栈,新结点,探测指针
	int top = -1;						// 置栈空
	int k, i = 0;						// k=1链接左子树,k=2链接右子树,i广义表字符下标
	char ch;
	do
	{
		ch = GenList[i]; // 读取广义表第i个字符
		switch (ch)
		{
		case '(':					// 读到左括号
			stack[++top] = NewNode; // 新结点入栈
			k = 1;
			break;
		case ')': // 读到右括号
			top--;
			break; // 栈顶结点出栈
		case ',':  // 读到逗号
			k = 2;
			break;
		default:					// 读到字符
			NewNode = new Node;		// 新结点申请内存
			NewNode->data = ch;		// 新结点数据域赋值
			NewNode->lChild = NULL; // 新结点左指针域赋值
			NewNode->rChild = NULL; // 新结点右指针域赋值
			if (IsEmpty(T))			// 如果树为空
				T.root = NewNode;	// 新结点作为根结点
			if (k == 1)
			{
				p = stack[top];		 // 获取栈顶结点
				p->lChild = NewNode; // 让栈顶结点左孩子指向新结点
			}
			else if (k == 2)
			{
				p = stack[top];		 // 获取栈顶结点
				p->rChild = NewNode; // 让栈顶结点左孩子指向新结点
			}
		}
		i++;					  // i增1
	} while (GenList[i] != '\0'); // 逐一读完整个广义表
}
// 非递归前序遍历算法
void PreOrder(Node *p)
{
	Node *stack[MaxSize];  // 简易结点顺序栈
	int top = -1;		   // 置栈空
	while (p || top != -1) // 当p结点所指非空或栈非空时
	{
		if (p) // 如果p所指结点非空
		{
			cout << p->data;  // 输出p的值
			stack[++top] = p; // p所指结点入栈
			p = p->lChild;	  // p向左下移
		}
		else // 如果p结点所指结点为空
		{
			p = stack[top--]; // p指向栈顶结点,栈顶结点出栈
			p = p->rChild;	  // p向右下移
		}
	}
}
// 非递归中序遍历算法
void InOrder(Node *p)
{
	Node *stack[MaxSize];  // 简易结点顺序栈
	int top = -1;		   // 置栈空
	while (p || top != -1) // 当p结点所指非空或栈非空时
	{
		if (p) // 如果p所指结点非空
		{
			stack[++top] = p; // p所指结点入栈
			p = p->lChild;	  // p向左下移
		}
		else // 如果p所指结点为空
		{
			p = stack[top--]; // p指向栈顶结点,栈顶结点出栈
			cout << p->data;  // 输出p的值
			p = p->rChild;	  // p向右下移
		}
	}
}
// 主函数
int main()
{
	char GenList[] = "A(B(C(,E),D(F,G)))"; // 定义广义表
	BinTree T;							   // 定义二叉树
	Create(T);							   // 创建空二叉树
	Create(GenList, T);					   // 创建二叉树
	cout << "前序遍历为 ";
	PreOrder(T.root);
	cout << endl;
	cout << "中序遍历为 ";
	InOrder(T.root);
	cout << endl;
	system("pause");
	return 0;
}

// 前序遍历
// void PreOrder(Node* p)
//{
//	if (p != NULL)
//	{
//		cout << p->data;//访问树根
//		PreOrder(p->lChild);//遍历左子树
//		PreOrder(p->rChild); //遍历右子树
//	}
// }

// 中序遍历
// 左子树—树根—右子树，即沿树的左子树一直往下，直到无法前进时后退到双亲结点，而后再沿右子树一直往下。如果右子树也走完了就退回上层的左结点，重复左、中、右的顺序遍历。
// void InOrder(Node* p)
//{
//	if (p != NULL)
//	{
//		InOrder(p->lChild); //遍历左子树
//		cout << p->data; //访问树根
//		InOrder(p->rChild);//遍历右子树
//	}
// }

// 后序遍历的顺序为：左子树—右子树—树根。后序遍历和前序遍历相反，它是把左、右子树的结点都处理完才处理树根。
// void PostOrder(Node* p)
//{
//	if (p != NULL)
//	{
//		PostOrder(p->lChild);//遍历左子树
//		PostOrder(p->rChild); //遍历右子树
//		cout << p->data; //访问树根
//	}
// }
