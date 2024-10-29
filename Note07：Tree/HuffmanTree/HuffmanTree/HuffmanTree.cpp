#include <bits/stdc++.h>
using namespace std;

struct HuffmanTree
{
	int weight; //权值
	int lChild; //左孩子
	int rChild; //右孩子
	int parent; //双亲结点
};

HuffmanTree *huffmanTree = NULL;
void createHuffmanTree(int[], int);
void creatHuffmanCode(int);

int main()
{
	int n;
	int w[1000];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	int m = 2 * n - 1;
	huffmanTree = new HuffmanTree[m + 1];
	createHuffmanTree(w, n);
	creatHuffmanCode(n);
}

//找到两个最小的权值（这里为了方便大家理解，就分开找两个最小值了）
void select(HuffmanTree huffmanTree[], int n, int &s1, int &s2)
{
	int min;
	//遍历全部的结点，找出一个单结点
	for (int i = 1; i <= n; i++)
	{
		if (huffmanTree[i].parent == 0)
		{
			min = i;
			break;
		}
	}
	//继续遍历全部结点，找出权值最小的单结点
	for (int i = 1; i <= n; i++)
	{
		if (huffmanTree[i].parent == 0)
		{
			if (huffmanTree[i].weight < huffmanTree[min].weight)
			{
				min = i;
			}
		}
	}
	s1 = min;
	//进行和上面相同的操作，找到第二小的结点
	for (int i = 1; i <= n; i++)
	{
		if (huffmanTree[i].parent == 0 && i != s1)
		{
			min = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (huffmanTree[i].parent == 0 && i != s1)
		{
			if (huffmanTree[i].weight < huffmanTree[min].weight)
			{
				min = i;
			}
		}
	}
	s2 = min;
}

//构建哈夫曼树
void createHuffmanTree(int w[], int n)
{
	int s1;
	int s2;
	int m = 2 * n - 1;
	// 1--n号空间存放叶子结点，初始化结点
	for (int i = 1; i <= n; i++)
	{
		//其中叶子结点的权值是w[n]数组保存
		huffmanTree[i].weight = w[i];
		huffmanTree[i].lChild = 0;
		huffmanTree[i].rChild = 0;
		huffmanTree[i].parent = 0;
	}
	//对于其它的结点即非叶子结点
	for (int i = n + 1; i <= m; i++)
	{
		huffmanTree[i].weight = w[i];
		huffmanTree[i].lChild = 0;
		huffmanTree[i].rChild = 0;
		huffmanTree[i].parent = 0;
	}

	//创建非叶子结点，构建哈夫曼树
	for (int i = n + 1; i <= m; i++)
	{
		//找到权值最小的两个结点，分别赋值给s1和s2
		select(huffmanTree, i - 1, s1, s2);
		huffmanTree[s1].parent = i;
		huffmanTree[s2].parent = i;
		huffmanTree[i].lChild = s1;
		huffmanTree[i].rChild = s2;
		huffmanTree[i].weight = huffmanTree[s1].weight + huffmanTree[s2].weight;
	}
}

//从n个叶子结点到根求哈弗曼编码
void creatHuffmanCode(int n)
{
	string *huffmanCode = new string[n + 1]; //创建一个储存编码的数组
	for (int i = 1; i <= n; i++)
	{
		string cd = "";
		//这里我们从叶子结点开始向上遍历
		for (int c = i, p = huffmanTree[i].parent; p != 0; c = p, p = huffmanTree[p].parent)
		{
			if (huffmanTree[p].lChild == c)
			{
				cd = "0" + cd; //如果该结点是双亲结点的左孩子，则在编码前加‘0’
			}
			else
			{
				cd = "1" + cd; //如果该结点是双亲结点的右孩子，则在编码前加‘1’
			}
		}
		huffmanCode[i] = cd;
	}
	//输出编码
	for (int i = 1; i <= n; i++)
	{
		cout << huffmanTree[i].weight << " " << huffmanCode[i] << endl;
	}
}
