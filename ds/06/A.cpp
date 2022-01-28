/*
问题 A: 串应用- 计算一个串的最长的真前后缀
时间限制: 1 Sec  内存限制: 128 MB
提交: 422  解决: 293
[提交][状态][讨论版]
题目描述
给定一个串，如ABCDAB，则 ABCDAB的真前缀有：{ A, AB,ABC, ABCD, ABCDA } ABCDAB的真后缀有：{ B, AB,DAB, CDAB, BCDAB } 因此，该串的真前缀和真后缀中最长的相等串为AB，我们称之为该串的“最长的真前后缀”。 试实现一个函数string matched_Prefix_Postfix(string str)，得到输入串str的最长的真前后缀。若不存在最长的真前后缀则输出empty
输入
第1行：串的个数 n 第2行到第n+1行：n个字符串
输出
n个最长的真前后缀，若不存在最长的真前后缀则输出empty。
样例输入
6
a
ab
abc
abcd
abcda
abcdab
样例输出
empty
empty
empty
empty
a
ab
提示
*/

#include <cstdio>
#include <cstring>

char buf[1024];

int pattern_equal(char *a, char *b, int len)
{
    while (len--)
    {
        if (*a++ != *b++)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        scanf("%s", buf);
        int len = strlen(buf);

        int flag = 1;
        if (len > 1)
        {
            for (int i = len - 1; i > 0; --i)
            {
                if (pattern_equal(buf, buf + len - i, i))
                {
                    buf[i] = 0;
                    puts(buf);
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
            puts("empty");
    }

    return 0;
}