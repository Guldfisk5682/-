#include <iostream>
#define MAX 10
struct slist
{
	int *DATA;
	int maxlength;
	int length;
} sqlist;

void changelength(int len, slist &sqlist)
{ // 动态数组
	int *p = sqlist.DATA;
	sqlist.DATA = new int[sizeof(int) * (sqlist.maxlength + len)];
	for (int i = 0; i < sqlist.length; i++)
	{
		sqlist.DATA[i] = p[i];
	}
	sqlist.maxlength = sqlist.maxlength + len;
	delete p;
}

void initlist(slist &sqlist)
{ // 初始化
	sqlist.DATA = new int[MAX];
	sqlist.length = 0;
	sqlist.maxlength = MAX;
}

bool ListInsert(slist &L, int i, int e)
{
	// 顺序表内存空间中不能空（需要一个个相邻存放）
	// 因此i的顺序为1，length+1
	if (i < 1 || i > L.length + 1) // 这里i<1是考虑到实际使用（从1开始计)和代码层面（从0开始）
		return false;
	else
	{
		for (int j = L.length; j >= i; j--)
			L.DATA[j] = L.DATA[j - 1];
		L.DATA[i - 1] = e;

		L.length++;
		return true;
	}
}

// 自己写的插入
// void listinsert(slist &L,int i,int e) {
//	int temp0 = L.DATA[i];
//	L.DATA[i] = e;
//	for (int j= i+1; j < L.length ; j++) {
//		int temp1 = L.DATA[j];
//		L.DATA[j] = temp0;
//		L.DATA[j + 1] = temp1;
//
//	}
//	L.length++;
// }

bool listdelete(slist &L, int &e, int i)
{ // e用引用是为了内存地址相同
	if (i < 1 || i > L.length)
		return false;
	else
	{
		e = L.DATA[i - 1]; // 将被删除的元素赋值给e
		for (int j = i; j < L.length; j++)
			L.DATA[j - 1] = L.DATA[j];
		L.length--;
		return true;
	}
}

int GetElem(slist L, int i)
{ // 按位查找
	return L.DATA[i - 1];
}

int LocateElem(slist L, int e)
{ // 返回元素位序
	for (int i = 0; i < L.length; i++)
		if (L.DATA[i] = e)
			return i + 1;
	return 0;
}

int main()
{
}