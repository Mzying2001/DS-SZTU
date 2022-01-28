/*
问题 E: 可重叠子串 (Ver. I)
时间限制: 1 Sec  内存限制: 128 MB
提交: 185  解决: 97
[提交][状态][讨论版]
题目描述
给定一个字符串（模式串）和一些待查找的字符串，求每个待查找字符串在模式串中出现的次数（可重叠）

输入
测试数据有多组（测试组数 <= 5），

第一行包括一个字符串P，长度不超过105，且非空串

第二行包括一个整数N，代表待查找的字符串数量 (1 <= N <= 5)

接下来的N行，每一行包括一个待查找的字符串，其长度不超过50，且非空串

输出
对于每组测试数据，

输出每个待查找字符串出现的次数，

具体输出见样例

样例输入
aabbcc
3
aa
bb
cc
ababab
1
aba
样例输出
aa:1
bb:1
cc:1
aba:2
提示
*/

// #include <iostream>
// #include <string>

// int *GetKmpNextArr(std::string &pattern)
// {
//     int *next = new int[pattern.length()];
//     *next = 0;
//     for (int i = 1, j = 0; i < pattern.length(); i++)
//     {
//         while (j > 1 && pattern[i] != pattern[j])
//             j = next[j - 1];
//         if (pattern[i] == pattern[j])
//             j++;
//         next[i] = j;
//     }
//     return next;
// }

// int KmpCount(std::string &str, std::string &pattern)
// {
//     int *next = GetKmpNextArr(pattern);
//     int count = 0;
//     for (int i = 0, j = 0; i < str.length(); i++)
//     {
//         while (j > 0 && str[i] != pattern[j])
//             j = next[j - 1];
//         if (str[i] == pattern[j] && ++j == pattern.length())
//         {
//             count++;
//             j = next[j - 1];
//         }
//     }
//     delete next;
//     return count;
// }

// int main()
// {
//     // freopen("in.txt", "r", stdin);

//     std::string str, pattern;
//     while (std::cin >> str)
//     {
//         int n;
//         std::cin >> n;
//         while (n--)
//         {
//             std::cin >> pattern;
//             std::cout << pattern << ":" << KmpCount(str, pattern) << std::endl;
//         }
//     }
//     return 0;
// }

#include <iostream>

using namespace std;

string op[100000];

int main()
{
    // freopen("in.txt", "r", stdin);

    string mode, str;
    int num, t, k, i, u, f, j;
    while (cin >> mode)
    {
        cin >> t;
        while (t--)
        {
            cin >> str;
            k = mode.length();
            f = str.length();
            num = 0;
            int num1;
            j = 0;
            int e = 0;
            for (i = 0; i < k; i++)
            {
                if (i + f <= k)
                    op[e++] = mode.substr(i, f);
            }
            num = 0;
            for (i = 0; i < e; i++)
            {
                if (op[i] == str)
                    num++;
            }
            cout << str << ":" << num << endl;
        }
    }
    return 0;
}
