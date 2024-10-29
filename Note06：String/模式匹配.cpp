#include <iostream>
#include <string>
#include <vector>
using namespace std;

int BF_algorithm(char S[], char T[])
{
    int start = 0;
    int i = 0, j = 0;

    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            start++;
            i = start;
            j = 0;
        }
    }

    // If we completed matching T, return the start + 1 (1-based index)
    if (T[j] == '\0')
    {
        return start + 1; // 1-based index
    }
    else
    {
        return 0; // No match found
    }
}

// KMP算法
// 前缀表：
void get_Next(string s, int next[]) // 这个函数对字符串s进行预处理得到next数组
{
    int j = 0;
    next[0] = 0; // 初始化
    for (int i = 1; i < s.size(); i++)
    { // i指针指向的是后缀末尾，j指针指向的是前缀末尾
        while (j > 0 && s[i] != s[j])
            j = next[j - 1]; // 前后缀不相同，去找j前一位的最长相等前后缀
        if (s[i] == s[j])
            j++;     // 前后缀相同，j指针后移
        next[i] = j; // 更新next数组
    }
}
// 关于指针回溯求next的理解
//  每次求next【i】，可看作前缀与后缀的一次匹配，在该过程中就可以用上之前所求的next，若匹配失败，则像模式串与父串匹配一样，将指针移到next【j-1】上。
//  求next过程实际上是dp（动态规划），只与前一个状态有关：
//  若不匹配，一直往前退到0或匹配为止
//  若匹配，则将之前的结果传递：
//  因为之前的结果不为0时，前后缀有相等的部分，所以j所指的实际是与当前值相等的前缀，可视为将前缀从前面拖了过来，就不必将指针从前缀开始匹配了，所以之前的结果是可以传递的。

// KMP匹配查找:
int strSTR(string s, string t) // 这个函数是从s中找到t，如果存在返回t出现的位置，如果不存在返回-1
{
    if (t.size() == 0)
        return 0;
    const int m = t.size();
    int next[m];
    get_Next(t, next);
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (j > 0 && s[i] != t[j])
            j = next[j - 1];
        if (s[i] == t[j])
            j++;
        if (j == t.size())
            return i - t.size() + 1;
    }
    return -1;
}

int main()
{
    char array1[] = "Welcome to the programming world!";
    char array2[] = "programming";

    int result = BF_algorithm(array1, array2);

    // int result = strSTR(array1, array2);

    if (result == 0)
    {
        cout << "Cannot match" << endl;
    }
    else
    {
        cout << "The matching point is: " << result << endl;
    }

    system("pause");
    return 0;
}
