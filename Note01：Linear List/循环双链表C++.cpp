#include <iostream>
using namespace std;

class Linklist;

class Node
{
private:
	int DATA;
	Node *next;
	Node *prior;

public:
	friend class Linklist;
	Node() : next(NULL), prior(NULL) { DATA = 0; }
};

class Linklist
{
private:
	Node *head;
	int length;

public:
	Linklist()
	{
		head = new Node;
		head->next = head;
		head->prior = head;
		head->DATA = 0;
		length = 0;
	}

	void createlinklist();
	void deletelinklist(int i);
	void insertlinklist(int i, int e);
	void printlist();
};

void Linklist::createlinklist()
{ // 尾插法
	Node *r = head;
	int x;
	cout << "请输入第一个值的大小" << endl;
	cin >> x;
	while (x != -1)
	{

		Node *p = new Node;
		p->DATA = x;
		p->next = head;
		head->prior = p;
		p->prior = r;
		r->next = p;
		r = p;

		cout << "请输入下一个值大小" << endl;
		cin >> x;
		length++;
	}
}

void Linklist::deletelinklist(int i)
{ // 按位删除
	if (head == NULL || length < 0 || i < 1 || i > length)
		return;
	Node *p = head;
	Node *temp;
	for (int j = 1; j < i - 1; j++)
	{
		p = p->next;
	}

	temp = p->next;
	p->next = temp->next;
	if (temp->next != head)
		temp->next->prior = p;
	else
		head->prior = p;
	delete temp;
	length--;
}

void Linklist::insertlinklist(int j, int e)
{ // 在i插入e
	if (j < 1 || j >= length)
		cout << "输入位置有误" << endl;
	return;

	Node *temp = new Node;
	temp->DATA = e;
	if (length == 0 || j == 0)
	{
		temp->next = head->next;
		temp->prior = head;
		head->prior = temp;
		head->next = temp;
	}

	else
	{
		Node *p = head->next;
		for (int i = 1; i < j - 1; i++)
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next->prior = temp;
		temp->prior = p;
		p->next = temp;
	}
	length++;
}

void Linklist::printlist()
{
	Node *p = head->next;
	int i = 1;
	while (p != head)
	{

		cout << "第" << i << "位的数据DATA值为：" << p->DATA << endl;
		p = p->next;
		i++;
	}
}

int main()
{
	Linklist L;
	L.createlinklist();
	L.printlist();
	int i, e;
	cout << "请输入想要插入的值的位置与大小" << endl;
	cin >> i;
	cin >> e;
	L.insertlinklist(i, e);
	L.printlist();
}