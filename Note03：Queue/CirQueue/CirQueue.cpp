#include <iostream>
using namespace std;

const int QueueSize = 100;

// 通过取余实现循环队列

template <typename T>
class CirQueue
{
public:
    CirQueue();
    ~CirQueue();
    void EnQueue(T x);
    T DeQueue();
    T GetQueue();
    bool isEmpty();
    bool isFull();

private:
    T data[QueueSize];
    int front, rear;
};

template <typename T>
CirQueue<T>::CirQueue()
{
    rear = front = 0;
}

template <typename T>
CirQueue<T>::~CirQueue()
{
    // 这里不需要做任何操作，因为T可能是基本数据类型，不需要析构
}

// 入队操作
template <typename T>
void CirQueue<T>::EnQueue(T x)
{
    if ((rear + 1) % QueueSize == front)
    {
        throw "上溢";
    }
    rear = (rear + 1) % QueueSize; // 队尾指针在循环意义下加1
    data[rear] = x;                // 在队尾处插入元素
}

// 出队操作
template <typename T>
T CirQueue<T>::DeQueue()
{
    if (rear == front)
    {
        throw "下溢";
    }
    T temp = data[front];            // 读取并返回出队前的队头元素
    front = (front + 1) % QueueSize; // 队头指针在循环意义下加1
    return temp;
}

template <typename T>
T CirQueue<T>::GetQueue()
{
    if (rear == front)
    {
        throw "下溢";
    }
    return data[front]; // 注意不修改队头指针
}

template <typename T>
bool CirQueue<T>::isEmpty()
{
    return front == rear;
}
template <typename T>
bool CirQueue<T>::isFull()
{
    return (rear + 1) % QueueSize == front;
}

int main()
{
    int x;
    CirQueue<int> Q;
    cout << "对5和8执行入队操作，";
    Q.EnQueue(5);
    Q.EnQueue(8);
    cout << "当前队头元素为：" << Q.GetQueue() << endl;

    x = Q.DeQueue();
    cout << "执行一次出队操作，出队元素是：" << x << endl;

    cout << "请输入入队元素：";
    cin >> x;
    Q.EnQueue(x);

    if (Q.isEmpty())
        cout << "队列为空" << endl;
    else
        cout << "队列非空" << endl;
    return 0;
}