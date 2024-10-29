#include <iostream>
using namespace std;

struct linklist
{
	int value;
	struct linklist *next;
} List;

void uselinklist();

int main()
{
	uselinklist();
	system("pause");
}

// 头节点指针(head)：
//
// 初始化：链表的头节点通常是一个空的占位节点，它的存在使得我们可以在不改变头节点的情况下，直接对链表进行操作。head 指针指向这个头节点，并且初始时 head->next 被设置为 NULL，表示链表为空。
// 操作便利：由于 head 是一个指针，它允许在添加新节点时直接修改 head->next，而不需要复制整个节点结构。
// 避免复制：如果 head 不是指针而是具体的 linklist 对象，那么每次对头节点的修改都需要复制整个结构体，这在大型数据结构中是低效的。
// 遍历指针(p)：
//
// 动态访问：p 作为一个指针，用于在链表中动态地向前或向后遍历。它可以根据需要指向链表中的任意节点，使得对链表的遍历和操作更加灵活。
// 操作任意节点：在链表的插入、删除或其他操作中，通常需要一个指针来引用当前操作的节点。p 指针可以在这些操作中被赋予新节点的地址，从而对链表进行修改。

linklist *headappend()
{ // 头插法
	linklist *head = new linklist;
	head->next = NULL;
	linklist *p;
	int x;
	cin >> x;
	while (x != -1)
	{
		p = new linklist;
		p->next = head->next;
		p->value = x;
		head->next = p;
		cin >> x;
	}
	return head;
}

linklist *tailappend()
{ // 尾插法
	linklist *head = new linklist;
	head->next = NULL;

	int x;
	linklist *tail = head;
	cout << "请输入链表所需值" << endl;
	cin >> x;
	while (x != -1)
	{
		linklist *p = new linklist;
		p->value = x;
		p->next = NULL;
		tail->next = p;
		tail = p;
		cout << "请输入链表所需值" << endl;
		cin >> x;
	}
	return head;
}

bool linkinsert(linklist *L, int i, int e)
{
	if (i < 1)
		return false;
	linklist *p = new linklist;
	p = L;
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	linklist *temp = new linklist;
	temp->value = e;
	temp->next = p->next;
	p->next = temp;
	delete p;
	return true;
}

// 指定节点前插操作思路				、、、、、、、、、、、、、、、重要
// bool linkinert2(linklist* p, int e) {
//	linklist* s = new linklist;	//申请一个新节点
//	s->next = p->next;
//	p->next = s;
//	s->value = p->value;
//	p->value = e;				//通过增加后继节点，实现数据的插入！！！
// }

void linkdelete(linklist *L, int i)
{ // 删除
	linklist *p = new linklist;
	p = L;
	for (int j = 0; j < i - 1; j++)
	{
		p = p->next;
	}
	if (p->next != NULL)
	{
		linklist *q = p->next;
		p->next = q->next;
		delete q;
	}
	return;
}

// 按位查找，返回第i个元素
linklist *GetElem(linklist *L, int i)
{
	int j = 1;
	linklist *p;
	p = L->next; // 不算头结点，从第一个有有效数据的节点开始
	if (i < 1)
		return NULL;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

// linklist* GetElem(linklist* L, int i) {		//头结点认为是第一个节点i=0为头结点
//	if (i < 0)
//		return NULL;
//	linklist* p;
//	int j = 0;
//	p = L;
//	while (p != NULL && j < i) {
//		p = p->next;
//		j++;
//	}
//	return p;
// }

linklist *LocateElem(linklist *L, int e)
{
	linklist *p = L;
	while (p != NULL && p->value != e)
	{
		p = p->next;
	}
	return p;
}

void printlist(linklist *L)
{
	int i = 1;
	linklist *p = L->next;
	while (p != NULL)
	{
		cout << i << "节点存储值为：" << p->value << endl;
		p = p->next;
		i++;
	}
}

void uselinklist()
{
	linklist *L = tailappend();
	printlist(L);
	int m;
	cout << "是否需要插入新值？（需要输入1，否则0）" << endl;
	cin >> m;
	int i, e;
	if (m)
	{
		cout << "请输入需要插入的位置以及值大小" << endl;
		cin >> i >> e;
		int check = linkinsert(L, i, e);

		if (check)
		{
			cout << "输入需要删除的数据元素位置" << endl;
			int d;
			cin >> d;
			linkdelete(L, d);
		}
		else
		{
			cout << "插入值或位置非法，请检查输入" << endl;
			return;
		}
	}
	else
	{
		cout << "输入需要删除的数据元素位置" << endl;
		int d;
		cin >> d;
		linkdelete(L, d);
	}
}