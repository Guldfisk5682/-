#include <iostream>
#include "generalized_lists.h"
using namespace std;

//不作为考试考察点，但理解本结构对于后续树的学习有帮助

int main()
{
	GenTable table;

	GListNode *list = nullptr;

	GListNode *sublist = table.CreateSublist(table.CreateAtom(1));
	table.AppendNode(sublist->sublist, table.CreateAtom(5));

	GListNode *templist = table.CreateSublist(table.CreateAtom(6));
	table.AppendNode(templist->sublist, sublist);

	table.AppendNode(list, table.CreateAtom(2));
	table.AppendNode(list, table.CreateAtom(3));
	table.AppendNode(list, templist);
	table.AppendNode(list, table.CreateAtom(4));

	table.PrintGList(list);
	cout << endl;

	cout << "Depth：" << table.GetDepth(list) << endl;

	system("pause");
	return 0;
}
