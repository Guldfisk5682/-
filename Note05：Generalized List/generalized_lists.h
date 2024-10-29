#pragma once

#include <iostream>

// 广义表节点的结构定义
struct GListNode
{
	bool isAtom; // 是否是原子类型节点

	union
	{

		int data; // 原子类型节点的值

		GListNode *sublist; // 子表类型节点的子表指针
	};

	GListNode *next; // 下一个节点指针
};

class GenTable
{
public:
	GListNode *CreateAtom(const int &value);

	GListNode *CreateSublist(GListNode *sublist);

	void AppendNode(GListNode *&list, GListNode *node);

	void PrintGList(GListNode *list);

	int GetDepth(GListNode *node);

	bool IsAtom(GListNode *node);

private:
	GListNode *head_;
};
