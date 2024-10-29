// heap������ȫ������˫�ף����ӵ���Ź�ϵ
// ÿ���ڵ��ֵ�����ڻ���ڣ�С�ڻ�������Һ��ӣ��ֱ��Ϊ����ѻ���С����
#include <iostream>
using namespace std;

const int QueueSize = 100;

template <class DataType>
class PriQueue
{
public:
    PriQueue();
    ~PriQueue();
    void EnQueue(DataType x); // ��Ӳ���
    DataType DeQueue();       // ���Ӳ���
    DataType GetQueue();      // ��ȡ��ͷԪ��
    int Empty();              // �ж϶����Ƿ�Ϊ��
private:
    DataType data[QueueSize]; // �洢��Ԫ�ص�����
    int rear;                 // ��βָ�룬ָ��ǰ���һ��Ԫ�ص���һ��λ��
};

template <class DataType>
PriQueue<DataType>::PriQueue()
{
    rear = 0; // ��ʼʱ����Ϊ��
}

template <class DataType>
PriQueue<DataType>::~PriQueue()
{
    // ���������������������
}

template <class DataType>
DataType PriQueue<DataType>::GetQueue()
{
    if (rear == 0)
        throw "����Ϊ�գ��޷���ȡ��ͷ";
    return data[1]; // ���ضѶ�Ԫ��
}

template <class DataType>
int PriQueue<DataType>::Empty()
{
    return rear == 0; // �����Ƿ�Ϊ��
}

template <class DataType>
void PriQueue<DataType>::EnQueue(DataType x)
{
    if (rear == QueueSize - 1)
        throw "�����쳣"; // �ж��Ƿ������
    rear++;               // ��Ԫ�ؼ������뵽���һ��λ��
    int i = rear;
    while (i > 1 && data[i / 2] < x)
    {                          // �ϸ�������ά�����������
        data[i] = data[i / 2]; // �����ڵ�����
        i /= 2;                // ���Ƶ����ڵ�
    }
    data[i] = x; // ����Ԫ�ط������λ��
}

template <class DataType>
DataType PriQueue<DataType>::DeQueue()
{
    if (rear == 0)
        throw "�����쳣";      // �ж϶����Ƿ�Ϊ��
    DataType maxVal = data[1]; // �Ѷ�Ԫ�أ������ֵ
    data[1] = data[rear];      // �����һ��Ԫ���Ƶ��Ѷ�
    rear--;                    // Ԫ�ؼ���

    int i = 1, j = 2 * i;
    while (j <= rear)
    { // �������µ�����
        if (j < rear && data[j] < data[j + 1])
            j++; // �ҵ����������нϴ��
        if (data[i] >= data[j])
            break;              // ���ڵ���ڵ������ĺ���ʱ��ֹͣ
        swap(data[i], data[j]); // ���򽻻����ڵ�ͺ��ӽڵ�
        i = j;                  // �������µ���
        j = 2 * i;
    }
    return maxVal; // ���ضѶ������ֵ
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

    cout << "��ͷԪ����: " << p.GetQueue() << endl;

    p.DeQueue();
    p.DeQueue();

    cout << "��������Ԫ�غ󣬶�ͷԪ����: " << p.GetQueue() << endl;

    return 0;
}
