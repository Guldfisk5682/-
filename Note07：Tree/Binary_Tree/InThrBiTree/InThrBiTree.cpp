//在2n个指针域中只有n-1个指针存储孩子结点，剩余n+1个可用于存储序列遍历中的前驱和后继结点
//指向前驱和后继的指针称为线索，即线索二叉树
//tag值意义:0表示child指向该结点孩子，1表示child指向该结点前驱
//pre始终指向刚刚访问过的结点


#include <iostream> 
using namespace std;

template <class DataType>
struct ThrNode {
    DataType data;
    int ltag, rtag;  // ltag = 1: left child is a thread, rtag = 1: right child is a thread
    ThrNode *lchild, *rchild;
};

template <class DataType>
class InThrBiTree {
public:
    InThrBiTree(); // Constructor to build the threaded binary tree
    ~InThrBiTree(); // Destructor to release memory
    ThrNode<DataType>* Next(ThrNode<DataType>* p); // Find the in-order successor of node p
    void InOrder(); // In-order traversal of the threaded binary tree
private:
    ThrNode<DataType>* Create(); // Helper function to create binary tree
    void ThrBiTree(ThrNode<DataType>* bt, ThrNode<DataType>*& pre); // Helper function to establish threads
    void Release(ThrNode<DataType>* bt); // Helper function to release nodes

    ThrNode<DataType>* root; // Pointer to the root of the tree
};

// Destructor: releases all nodes
template <class DataType>
InThrBiTree<DataType>::~InThrBiTree() {
    Release(root);
}

// Recursive function to release all nodes in the tree
template <class DataType>
void InThrBiTree<DataType>::Release(ThrNode<DataType>* bt) {
    if (bt == nullptr) return;
    Release(bt->lchild); // Release left subtree
    Release(bt->rchild); // Release right subtree
    delete bt;           // Release root node
}

// Constructor: builds the binary tree and threads it
template <class DataType>
InThrBiTree<DataType>::InThrBiTree() {
    root = Create(); // Build the tree
    ThrNode<DataType>* pre = nullptr; // Initialize predecessor as nullptr
    ThrBiTree(root, pre); // Create threads
}

// Function to create the binary tree based on user input (pre-order traversal)
template <class DataType>
ThrNode<DataType>* InThrBiTree<DataType>::Create() {
    char ch;
    cout << "请输入扩展二叉树的前序遍历序列，每次输入一个字符:";
    cin >> ch; // Input character data for the node
    if (ch == '#') return nullptr; // End of a branch
    else {
        ThrNode<DataType>* bt = new ThrNode<DataType>;
        bt->data = ch;
        bt->ltag = bt->rtag = 0; // Initialize tags as 0 (meaning normal child pointers)
        bt->lchild = Create(); // Recursively create left subtree
        bt->rchild = Create(); // Recursively create right subtree
        return bt;
    }
}

// Function to create in-order threads in the binary tree
template <class DataType>
void InThrBiTree<DataType>::ThrBiTree(ThrNode<DataType>* bt, ThrNode<DataType>*& pre) {
    if (bt == nullptr) return;
    // Left subtree
    ThrBiTree(bt->lchild, pre);

    // Process the current node
    if (bt->lchild == nullptr) { // Handle left thread
        bt->ltag = 1;
        bt->lchild = pre; // Set left child as predecessor
    }
    if (pre != nullptr && pre->rchild == nullptr) { // Handle right thread of the predecessor
        pre->rtag = 1;
        pre->rchild = bt; // Set right child of predecessor as current node
    }

    // Update predecessor to current node
    pre = bt;

    // Right subtree
    ThrBiTree(bt->rchild, pre);
}

// Function to find the in-order successor of node p
template <class DataType>
ThrNode<DataType>* InThrBiTree<DataType>::Next(ThrNode<DataType>* p) {
    ThrNode<DataType>* q = nullptr;
    if (p->rtag == 1) {
        q = p->rchild; // If rtag is 1, directly return the right child (threaded successor)
    } else {
        q = p->rchild; // Move to right child
        while (q != nullptr && q->ltag == 0) {
            q = q->lchild; // Find the left-most node
        }
    }
    return q;
}

// In-order traversal of the threaded binary tree
template <class DataType>
void InThrBiTree<DataType>::InOrder() {
    if (root == nullptr) return; // If tree is empty, return
    ThrNode<DataType>* p = root;
    while (p->ltag == 0) // Find the left-most node in in-order
        p = p->lchild;

    // Traverse the tree using the threads
    while (p != nullptr) {
        cout << p->data << " "; // Visit the node
        p = Next(p); // Move to the next in-order node
    }
}

// Main function to demonstrate the usage
int main() {
    InThrBiTree<char> T; // Create a threaded binary tree of type char
    cout << "中序遍历序列是: ";
    T.InOrder(); // Perform in-order traversal
    return 0;
}
