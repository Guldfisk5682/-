#pragma once
#include <iostream>
using namespace std;

template <class T>
class Seqqueue
{
public:
	Seqqueue(int size = 20);
	~Seqqueue() { delete[] array; }
	bool addelem(const T val);
	bool delelem(T &val);
	bool getelem(T &val) const;
	bool isempty() const { return rear == front; }
	bool isfull() const { return (rear + 1) % maxsize == front; }
	int length() const { return (rear - front + maxsize) % maxsize; }

private:
	int rear, front;
	T *array;
	int maxsize;
};