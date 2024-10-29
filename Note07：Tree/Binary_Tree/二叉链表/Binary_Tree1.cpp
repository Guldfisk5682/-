#include <iostream>
using namespace std;

struct Node
{
	char data;
	Node *lchild, *rchild;
};

struct BinaryTree
{
public:
	Node *Tree;
	void creattree(const char data, Node *left, Node *right)
	{
		Node *Newnode = new Node;
		Newnode->data = data;
		Newnode->lchild = left;
		Newnode->rchild = right;
		Tree = Newnode;
	}
};

void PrintBT(Node *T)
{
	if (T != NULL)
	{
		cout << T->data << " ";
		PrintBT(T->lchild);
		PrintBT(T->rchild);
	}
}

int main()
{
	BinaryTree A, B, C, D, E;
	E.creattree('E', NULL, NULL);
	D.creattree('D', E.Tree, NULL);
	C.creattree('C', D.Tree, NULL);
	B.creattree('B', NULL, NULL);
	A.creattree('A', C.Tree, B.Tree);
	PrintBT(A.Tree);
	system("pause");
	return 0;
}