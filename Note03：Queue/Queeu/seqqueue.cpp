#include "seqqueue.h"
#include <iostream>
using namespace std;

template <class T>
Seqqueue<T>::Seqqueue(int size) : front(0), rear(0), maxsize(size)
{
	array = new T[maxsize];
}

template <class T>
bool Seqqueue<T>::addelem(const T val)
{
	if (isfull())
		return false;
	array[rear] = val;
	rear = (rear + 1) % maxsize;
	return true;
}

template <class T>
bool Seqqueue<T>::delelem(T &val)
{
	if (isempty())
		return false;
	val = array[front];
	front = (front + 1) % maxsize;
	return true;
}

template <class T>
bool Seqqueue<T>::getelem(T &val) const
{
	if (isempty())
		return false;
	val = array[front];
	return true;
}
