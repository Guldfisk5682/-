#include <iostream>
using namespace std;
#include "seqqueue.cpp"

int main()
{
	Seqqueue<int> S;
	int value;
	for (int i = 0; i < 10; i++)
	{
		S.addelem(i);
	}

	cout << "���а�����" << S.length() << "��Ԫ��" << endl;
	S.delelem(value);
	cout << "�����к󣬶��к��У�" << S.length() << "��Ԫ��" << endl;
	S.getelem(value);
}