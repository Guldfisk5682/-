// 不相交集合是对集合的一种划分，子集之间没有交集，基本操作为查找和合并，基本操作为并查，因此称为并查集
// 每个子集表示为一棵树
// 查找操作给出给出待查元素的根节点，合并操作将两棵树合并
// 并查集只关心哪些元素归属同一颗树，因此可以将一棵树作为另一棵树根节点的子树
// 查和并只涉及某节点双亲，因此可以用双亲表示法存储

#include <iostream>
using namespace std;

struct ElemType
{
    char data;  // 假定并查集的元素为字符型
    int parent; // 游标，该元素的双亲在数组中的下标
};

const int MaxSize = 100; // 假设集合最多100个元素

class UnionFind
{
public:
    UnionFind(char ch[], int n); // 构造函数，每个元素构成一个子集
    ~UnionFind();                // 析构函数
    int Find(char x);            // 查找元素x所在子树的根结点
    void Union(char x, char y);  // 合并元素x和y所在子集
private:
    ElemType elem[MaxSize]; // 双亲表示法存储
    int length;             // 集合的元素个数
};

UnionFind::UnionFind(char ch[], int n)
{
    length = n;
    for (int i = 0; i < length; i++)
    {
        elem[i].parent = -1;  // 初始化时，每个元素是独立的集合
        elem[i].data = ch[i]; // 设置元素的字符值
    }
}

UnionFind::~UnionFind()
{
    // 析构函数，当前没有需要特别释放的资源
}

int UnionFind::Find(char x)
{
    // 查找x所在集合的根，同时进行路径压缩
    int i;
    for (i = 0; i < length; i++)
    {
        if (elem[i].data == x)
            break; // 找到元素x的索引i
    }
    if (i == length)
        return -1; // 如果找不到，返回-1

    // 路径压缩的查找过程
    int root = i;
    while (elem[root].parent != -1)
    {
        root = elem[root].parent; // 找到根节点
    }

    // 路径压缩，将沿途所有节点直接连接到根节点
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
    // 合并x和y所在的两个子集
    int vex1 = Find(x);
    int vex2 = Find(y);
    if (vex1 != -1 && vex2 != -1 && vex1 != vex2)
    {
        elem[vex2].parent = vex1; // 将y的根结点挂到x的根结点上
    }
}

int main()
{
    char str[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int flag[6];
    UnionFind UF{str, 6};

    // 合并集合
    UF.Union('a', 'b');
    UF.Union('a', 'c');
    UF.Union('d', 'e');

    // 输出每个元素所属的集合根节点
    for (int i = 0; i < 6; i++)
    {
        flag[i] = UF.Find(str[i]);
        cout << flag[i] << ": " << str[i] << endl;
    }

    return 0;
}
