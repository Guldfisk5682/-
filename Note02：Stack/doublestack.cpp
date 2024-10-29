#include <iostream>
using namespace std;
#include "doublestack.h"

template <class T>
bool doublestack<T>::isempty(int i) const
{
	if (i < 1 || i > 2)
	{
		cout << "The data is not in the range" << endl;
		return false;
	}
	else
	{
		return (top[i - 1] == bottom[i - 1]);
	}
}

template <class T>
doublestack<T>::doublestack(int size)
{
	maxsize = size;
	top[0] = -1;
	bottom[0] = -1;
	top[1] = maxsize;
	bottom[1] = maxsize;
}

template <class T>
bool doublestack<T>::isfull() const
{
	return (top[0] + 1 == top[1]); // 两个top不能重合，这是两个部分的栈
}

template <class T>
bool doublestack<T>::push(int i, T elem)
{
	if (isfull)
	{
		cout << "overflow" << endl;
		return false;
	}
	else
	{
		if (i == 1)
		{
			vector[++top[0]] = elem;
			return true;
		}
		else if (i == 2)
		{
			vector[--top[1]] = elem;
			return true;
		}
		else
		{
			cout << "The data is not in the range" << endl;
			return false;
		}
	}
}

template <class T>
bool doublestack<T>::pop(int i, T &elem)
{
	if (i < 1 || i > 2)
	{
		cout << "The data is not in the range" << endl;
		return false;
	}
	if (isempty(i))
	{
		cout << "no data" << endl;
		return false;
	}
	if (i == 1)
	{
		elem = vector[top[0]--];
		return true;
	}
	if (i == 2)
	{
		elem = vector[top[1]++];
		return true;
	}
}

template <class T>
bool doublestack<T>::getelem(int i, T &elem)
{
	if (i < 1 || i > 2)
	{
		cout << "The data is not in the range" << endl;
		return false;
	}
	if (isempty(i))
	{
		cout << "no data" << endl;
		return false;
	}
	if (i == 1)
	{
		elem = vector[top[0]];
		return true;
	}
	if (i == 2)
	{
		elem = vector[top[1]];
		return true;
	}
}

template <class T>
void doublestack<T>::printstack() const
{
	int i = bottom[0];
	cout << "The first stack：" << endl;
	while (i < top[0])
	{
		cout << vector[i] << endl;
	}

	i = top[1];
	cout << "The second stsck：" << endl;
	while (i < bottom[1])
	{
		cout << vector[i] << endl;
		i++;
	}
	cout << endl;
}