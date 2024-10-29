// ���ཻ�����ǶԼ��ϵ�һ�ֻ��֣��Ӽ�֮��û�н�������������Ϊ���Һͺϲ�����������Ϊ���飬��˳�Ϊ���鼯
// ÿ���Ӽ���ʾΪһ����
// ���Ҳ���������������Ԫ�صĸ��ڵ㣬�ϲ��������������ϲ�
// ���鼯ֻ������ЩԪ�ع���ͬһ��������˿��Խ�һ������Ϊ��һ�������ڵ������
// ��Ͳ�ֻ�漰ĳ�ڵ�˫�ף���˿�����˫�ױ�ʾ���洢

#include <iostream>
using namespace std;

struct ElemType
{
    char data;  // �ٶ����鼯��Ԫ��Ϊ�ַ���
    int parent; // �α꣬��Ԫ�ص�˫���������е��±�
};

const int MaxSize = 100; // ���輯�����100��Ԫ��

class UnionFind
{
public:
    UnionFind(char ch[], int n); // ���캯����ÿ��Ԫ�ع���һ���Ӽ�
    ~UnionFind();                // ��������
    int Find(char x);            // ����Ԫ��x���������ĸ����
    void Union(char x, char y);  // �ϲ�Ԫ��x��y�����Ӽ�
private:
    ElemType elem[MaxSize]; // ˫�ױ�ʾ���洢
    int length;             // ���ϵ�Ԫ�ظ���
};

UnionFind::UnionFind(char ch[], int n)
{
    length = n;
    for (int i = 0; i < length; i++)
    {
        elem[i].parent = -1;  // ��ʼ��ʱ��ÿ��Ԫ���Ƕ����ļ���
        elem[i].data = ch[i]; // ����Ԫ�ص��ַ�ֵ
    }
}

UnionFind::~UnionFind()
{
    // ������������ǰû����Ҫ�ر��ͷŵ���Դ
}

int UnionFind::Find(char x)
{
    // ����x���ڼ��ϵĸ���ͬʱ����·��ѹ��
    int i;
    for (i = 0; i < length; i++)
    {
        if (elem[i].data == x)
            break; // �ҵ�Ԫ��x������i
    }
    if (i == length)
        return -1; // ����Ҳ���������-1

    // ·��ѹ���Ĳ��ҹ���
    int root = i;
    while (elem[root].parent != -1)
    {
        root = elem[root].parent; // �ҵ����ڵ�
    }

    // ·��ѹ��������;���нڵ�ֱ�����ӵ����ڵ�
    while (i != root)
    {
        int temp = elem[i].parent;
        elem[i].parent = root;
        i = temp;
    }

    return root;
}

void UnionFind::Union(char x, char y)
{
    // �ϲ�x��y���ڵ������Ӽ�
    int vex1 = Find(x);
    int vex2 = Find(y);
    if (vex1 != -1 && vex2 != -1 && vex1 != vex2)
    {
        elem[vex2].parent = vex1; // ��y�ĸ����ҵ�x�ĸ������
    }
}

int main()
{
    char str[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int flag[6];
    UnionFind UF{str, 6};

    // �ϲ�����
    UF.Union('a', 'b');
    UF.Union('a', 'c');
    UF.Union('d', 'e');

    // ���ÿ��Ԫ�������ļ��ϸ��ڵ�
    for (int i = 0; i < 6; i++)
    {
        flag[i] = UF.Find(str[i]);
        cout << flag[i] << ": " << str[i] << endl;
    }

    return 0;
}
