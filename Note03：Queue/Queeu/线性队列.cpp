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

	cout << "队列包含：" << S.length() << "个元素" << endl;
	S.delelem(value);
	cout << "出队列后，队列含有：" << S.length() << "个元素" << endl;
	S.getelem(value);
}