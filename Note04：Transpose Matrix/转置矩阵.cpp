#include <iostream>
#include <vector>
using namespace std;

struct TupNode
{
    int row, col, d; // row 行 col 列
};

struct TSMatrix
{
    int rows, cols, nums;
    vector<TupNode> data;
};

void CreatMat(TSMatrix &t, const vector<vector<int>> &arr)
{
    t.rows = arr.size();
    t.cols = arr[0].size();
    t.nums = 0;

    for (int i = 0; i < t.rows; ++i)
    {
        for (int j = 0; j < t.cols; ++j)
        {
            if (arr[i][j] != 0)
            {
                t.data.push_back({i, j, arr[i][j]});
                t.nums++;
            }
        }
    }
}

void TransposeMat(const TSMatrix &t, TSMatrix &t_trans)
{
    t_trans.rows = t.cols;
    t_trans.cols = t.rows;
    t_trans.nums = t.nums;
    t_trans.data.resize(t.nums);

    vector<int> num(t.cols, 0);
    for (int i = 0; i < t.nums; ++i)
    {
        num[t.data[i].col]++;
    }

    vector<int> position(t.cols, 0);
    for (int i = 1; i < t.cols; ++i)
    {
        position[i] = position[i - 1] + num[i - 1]; // 这里的position作用是为新的data（转置矩阵三元组指定位置）
                                                    //   不是直接为新矩阵本身指定位置！！！！
        // 具体来说，num中的每一个数值都代表在一列有多少需要加入新三元组的非零元素数量
        // position中的数据设计原理：
        // position[0]代表第一列的数据从新三元组的0号位开始填入,position[i]=position[i-1]+num[i-1]是为上一列数据预留空间，每次填充数据后进行position++则可以推进到下一个
        // 位置进行数据填充
    }

    for (int i = 0; i < t.nums; ++i)
    {
        int col = t.data[i].col;
        int pos = position[col];
        t_trans.data[pos] = {col, t.data[i].row, t.data[i].d};
        position[col]++;
    }
    // int col是原矩阵的列数，用于配合position数组来确定新三元组
}

void DispMat(const TSMatrix &t)
{
    cout << "Rows: " << t.rows << ", Cols: " << t.cols << ", Non-zero elements: " << t.nums << endl;
    for (int i = 0; i < t.nums; ++i)
    {
        cout << "Row: " << t.data[i].row << ", Col: " << t.data[i].col << ", Value: " << t.data[i].d << endl;
    }
}

int main()
{
    std::vector<std::vector<int>> arr = {
        {1, 0, 0, 0},
        {0, 2, 0, 0},
        {0, 0, 3, 0}};

    TSMatrix t;
    CreatMat(t, arr);

    TSMatrix t_trans;
    TransposeMat(t, t_trans);

    std::cout << "Original matrix:" << std::endl;
    DispMat(t);

    std::cout << "Transposed matrix:" << std::endl;
    DispMat(t_trans);

    return 0;
}
