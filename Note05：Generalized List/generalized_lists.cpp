#include "generalized_lists.h"
#include <iostream>
// 模版类/结构体实现如果涉及到模板类/结构体的返回类型或参数类型
// 必须指定模板参数。例如，Gnode<T>* create_atom(const T& value);
// Getdepth内部逻辑：A->B->C->D
// 递归到底层原子节点，return=1，D->maxdepth=1；随后return maxdepth+1 C->maxdepth=2;以此类推，A->maxdepth=4

GListNode *GenTable::CreateAtom(const int &value)
{
	GListNode *node = new GListNode;

	node->isAtom = true;
	node->data = value;
	node->next = nullptr;

	return node;
}

GListNode *GenTable::CreateSublist(GListNode *sublist)
{
	GListNode *node = new GListNode;

	node->isAtom = false;
	node->sublist = sublist;
	node->next = nullptr;

	return node;
}

void GenTable::AppendNode(GListNode *&list, GListNode *node)
{
	if (list == nullptr)
		list = node;
	else
	{
		GListNode *p = list;

		while (p->next)
			p = p->next;

		p->next = node;
	}
}

void GenTable::PrintGList(GListNode *list)
{
	if (list == nullptr)
	{
		std::cout << "空表" << std::endl;
		return;
	}

	std::cout << "(";

	GListNode *p = list;

	while (p != nullptr)
	{

		if (p->isAtom)
			std::cout << p->data;
		else
			PrintGList(p->sublist);

		if (p->next != nullptr)
			std::cout << ", ";

		p = p->next;
	}
	std::cout << ")";
}

int GenTable::GetDepth(GListNode *node)
{
	// 空表的深度为0
	if (node == nullptr)
		return 0;

	if (node->isAtom && node->next == nullptr)
		// 原子的深度为1
		return 1;
	else if (node->isAtom)
		return GetDepth(node->next);

	int maxDepth = 0;

	// 遍历子表，并计算子表的深度
	GListNode *sublist = node->sublist;

	while (sublist != nullptr)
	{
		int currDepth = GetDepth(sublist);
		if (currDepth > maxDepth)
			maxDepth = currDepth;

		sublist = sublist->next;
	}

	// 子表的最大深度加1
	return maxDepth + 1;
}

bool GenTable::IsAtom(GListNode *node)
{
	return node != nullptr && node->isAtom;
}
