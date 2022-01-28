/*
问题 B: DS串应用—最长重复子串
时间限制: 1 Sec  内存限制: 128 MB
提交: 492  解决: 271
[提交][状态][讨论版]
题目描述
求串的最长重复子串长度（子串不重叠）。例如：abcaefabcabc的最长重复子串是串abca，长度为4。

输入
测试次数t

t个测试串

输出
对每个测试串，输出最长重复子串长度，若没有重复子串，输出-1.

样例输入
3
abcaefabcabc
0szu0123szu1
szuabcefg
样例输出
4
3
-1
提示
*/

#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    while (n--)
    {
        std::string str;
        std::cin >> str;

        int ans = -1;

        for (int i = 0; i < str.length(); ++i)
        {
            for (int j = i + 1; j < str.length(); ++j)
            {
                std::string tmp = str.substr(i, j - i);
                if (str.find(tmp, j) != std::string::npos)
                {
                    if (ans == -1 || ans < tmp.length())
                        ans = tmp.length();
                }
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}