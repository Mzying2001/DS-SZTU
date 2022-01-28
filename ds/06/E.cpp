/*
问题 E: DS串应用--KMP算法
时间限制: 1 Sec  内存限制: 128 MB
提交: 268  解决: 229
[提交][状态][讨论版]
题目描述
学习KMP算法，给出主串和模式串，求模式串在主串的位置

算法框架如下，仅供参考





输入
第一个输入t，表示有t个实例

第二行输入第1个实例的主串，第三行输入第1个实例的模式串

以此类推

输出
第一行输出第1个实例的模式串的next值

第二行输出第1个实例的匹配位置，位置从1开始计算，如果匹配成功输出位置，匹配失败输出0

以此类推

样例输入
3
qwertyuiop
tyu
aabbccdd
ccc
aaaabababac
abac
样例输出
-1 0 0 
5
-1 0 1 
0
-1 0 0 1 
8
提示
 为什么next值和课本的不一样？？？


*/

#include <iostream>

using namespace std;

void get_next(string &t, int *next)
{
    int i = 0, j = -1;
    next[i] = j;
    while (i < (int)t.length())
    {
        if (j == -1 || t[i] == t[j])
        {
            ++i, ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int Kmp(string &s, string &t)
{
    int i = 0, j = 0;
    int *next = new int[t.length() + 1];
    get_next(t, next);

    for (int i = 0; i < t.length(); i++)
        cout << next[i] << " ";
    cout << endl;

    while (i < (int)s.length() && j < (int)t.length())
    {
        if (j == -1 || s[i] == t[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j == (int)t.length())
    {
        return i - j + 1;
    }
    else
        return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        string t;
        cin >> str >> t;
        cout << Kmp(str, t) << endl;
    }
}