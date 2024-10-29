//二叉链表实现头文件

template <class T>
struct BinNode
{
    BinNode<T> *lchild, *rchild;
    T data;
};

template <class T>
class BinTree
{
public:
    BinTree() { root = Create(); }
    ~BinTree() { Release(root); }
    void PreOrder() { PreOrder(root); }

private:
    BinNode<T> *root;
    BinNode<T> *Create();          //构造函数调用
    void Release(BinNode<T> *bt);  //析构函数调用
    void PreOrder(BinNode<T> *bt); //前序遍历调用
};
