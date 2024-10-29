// heap利用完全二叉树双亲，孩子的序号关系
// 每个节点的值都大于或等于，小于或等于左右孩子，分别称为大根堆或者小根堆
#include <iostream>
using namespace std;

const int QueueSize = 100;

template <class DataType>
class PriQueue
{
public:
    PriQueue();
    ~PriQueue();
    void EnQueue(DataType x); // 入队操作
    DataType DeQueue();       // 出队操作
    DataType GetQueue();      // 获取队头元素
    int Empty();              // 判断队列是否为空
private:
    DataType data[QueueSize]; // 存储堆元素的数组
    int rear;                 // 队尾指针，指向当前最后一个元素的下一个位置
};

template <class DataType>
PriQueue<DataType>::PriQueue()
{
    rear = 0; // 初始时，堆为空
}

template <class DataType>
PriQueue<DataType>::~PriQueue()
{
    // 析构函数（无特殊操作）
}

template <class DataType>
DataType PriQueue<DataType>::GetQueue()
{
    if (rear == 0)
        throw "队列为空，无法获取队头";
    return data[1]; // 返回堆顶元素
}

template <class DataType>
int PriQueue<DataType>::Empty()
{
    return rear == 0; // 返回是否为空
}

template <class DataType>
void PriQueue<DataType>::EnQueue(DataType x)
{
    if (rear == QueueSize - 1)
        throw "上溢异常"; // 判断是否队列满
    rear++;               // 新元素即将插入到最后一个位置
    int i = rear;
    while (i > 1 && data[i / 2] < x)
    {                          // 上浮操作，维护大根堆性质
        data[i] = data[i / 2]; // 将父节点下移
        i /= 2;                // 上移到父节点
    }
    data[i] = x; // 将新元素放入合适位置
}

template <class DataType>
DataType PriQueue<DataType>::DeQueue()
{
    if (rear == 0)
        throw "下溢异常";      // 判断队列是否为空
    DataType maxVal = data[1]; // 堆顶元素，即最大值
    data[1] = data[rear];      // 将最后一个元素移到堆顶
    rear--;                    // 元素减少

    int i = 1, j = 2 * i;
    while (j <= rear)
    { // 自上向下调整堆
        if (j < rear && data[j] < data[j + 1])
            j++; // 找到两个孩子中较大的
        if (data[i] >= data[j])
            break;              // 父节点大于等于最大的孩子时，停止
        swap(data[i], data[j]); // 否则交换父节点和孩子节点
        i = j;                  // 继续向下调整
        j = 2 * i;
    }
    return maxVal; // 返回堆顶的最大值
}

int main()
{
    PriQueue<int> p;
    p.EnQueue(30);
    p.EnQueue(22);
    p.EnQueue(18);
    p.EnQueue(32);
    p.EnQueue(36);
    p.EnQueue(45);
    p.EnQueue(40);
    p.EnQueue(50);

    cout << "队头元素是: " << p.GetQueue() << endl;

    p.DeQueue();
    p.DeQueue();

    cout << "出队两个元素后，队头元素是: " << p.GetQueue() << endl;

    return 0;
}
