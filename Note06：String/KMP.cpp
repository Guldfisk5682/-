#include <iostream>
#include <vector>
using namespace std;

// next数组表示的是，每次匹配失败后，子串内可以跳过匹配的字符数
// next[i]的大小表示可以跳过的字符数
// ex:ABABC,两对AB是完全相同的前缀后缀，并且是最长的相同前后缀
// substring:ABACABAB
//      next:00101230
// next中的元素分别表示：在next[2],A为最长前后缀，可跳过1个字符

// 对于j=next[j-1]
// 个人理解：在KMP中：
//当j与i匹配失败后，在当前j之前寻找“可以被跳过的substring”
// j-1表示的就是在j之前，有多少能被跳过匹配的字符
void get_next(const string &t, vector<int> &next)
{
    next[0] = 0;
    int j = 0;
    for (int i = 1; i < t.size(); i++)
    {
        while (j > 0 && t[j] != t[i])   //t[j]指向的永远是当前最长共同前缀的最后一位字符，
        //当遇到不匹配字符时，配合j=next[j-1]能够依次向前寻找新的最长匹配项
        //因为是从后向前寻找，就能处理例子中的最末位AB问题
            j = next[j - 1];    //往前寻找，是否有能与t[i]相匹配的前缀，直到不满足while条件 值=0
        if (t[i] == t[j])
            j++;
        next[i] = j;
    }
}

int KMP_algorithm(const string &s, const string &t)
{
    int n = t.size();
    if (n == 0)
        return 0;

    vector<int> next(n);
    get_next(t, next);
    int i = 0, j = 0;

    while (i < s.size())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
            if (j == t.size())
            {
                return i - j; // Found match, return the index
            }
        }
        else
        {
            if (j > 0)
                j = next[j - 1];
            else
                i++;
        }
    }

    return -1; // No match found
}

int main()
{
    string s = "abcabjabc";
    string t = "abjabc";
    int result = KMP_algorithm(s, t);
    if (result != -1)
        cout << "matching point is: " << result << endl;
    else
        cout << "no matching point" << endl;

    return 0;
}
