#include <iostream>
using namespace std;

template <class T>
class doublestack
{
private:
	T *vector;
	int top[2], bottom[2];
	int maxsize;

public:
	doublestack(int size = 100);
	bool isempty(int i) const;
	bool isfull() const;
	bool push(int i, T elem);
	bool pop(int i, T &elem);
	bool getelem(int i, T &elem);
	void printstack() const;
};