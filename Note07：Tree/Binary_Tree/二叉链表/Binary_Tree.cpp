#include <iostream>
#include "Binary_Tree.h"
using namespace std;
//n个节点的二叉链表有n+1个NULLPTR

//二叉链表实现

template <class T>
void BinTree<T>::PreOrder(BinNode<T> *bt)
{
    if (bt != NULL)
    {
        cout << bt->data << " ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

template <class T>
BinNode<T> *BinTree<T>::Create()
{
    BinNode<T> *bt;
    char ch;
    cout << "Enter node data (or '#' for NULL): ";
    cin >> ch;

    if (ch == '#')
    {
        bt = NULL; // create empty node
    }
    else if (!isalpha(ch))
    {
        cout << "Invalid input. Only alphabetic characters are allowed." << endl;
        bt = NULL; // Invalid input results in empty node
    }
    else
    {
        bt = new BinNode<T>;
        bt->data = ch;
        cout << "Creating left child of " << bt->data << endl;
        bt->lchild = Create();
        cout << "Creating right child of " << bt->data << endl;
        bt->rchild = Create();
    }

    return bt;
}

template <class T>
void BinTree<T>::Release(BinNode<T> *bt)
{
    if (bt == NULL)
        return;
    else
    {
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}
