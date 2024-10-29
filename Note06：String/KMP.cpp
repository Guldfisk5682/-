#include <iostream>
#include <vector>
using namespace std;

// next�����ʾ���ǣ�ÿ��ƥ��ʧ�ܺ��Ӵ��ڿ�������ƥ����ַ���
// next[i]�Ĵ�С��ʾ�����������ַ���
// ex:ABABC,����AB����ȫ��ͬ��ǰ׺��׺�������������ͬǰ��׺
// substring:ABACABAB
//      next:00101230
// next�е�Ԫ�طֱ��ʾ����next[2],AΪ�ǰ��׺��������1���ַ�

// ����j=next[j-1]
// ������⣺��KMP�У�
//��j��iƥ��ʧ�ܺ��ڵ�ǰj֮ǰѰ�ҡ����Ա�������substring��
// j-1��ʾ�ľ�����j֮ǰ���ж����ܱ�����ƥ����ַ�
void get_next(const string &t, vector<int> &next)
{
    next[0] = 0;
    int j = 0;
    for (int i = 1; i < t.size(); i++)
    {
        while (j > 0 && t[j] != t[i])   //t[j]ָ�����Զ�ǵ�ǰ���ͬǰ׺�����һλ�ַ���
        //��������ƥ���ַ�ʱ�����j=next[j-1]�ܹ�������ǰѰ���µ��ƥ����
        //��Ϊ�ǴӺ���ǰѰ�ң����ܴ��������е���ĩλAB����
            j = next[j - 1];    //��ǰѰ�ң��Ƿ�������t[i]��ƥ���ǰ׺��ֱ��������while���� ֵ=0
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
