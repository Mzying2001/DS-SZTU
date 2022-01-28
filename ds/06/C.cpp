/*
问题 C: 子串循环问题 (Ver. I)
时间限制: 1 Sec  内存限制: 128 MB
提交: 440  解决: 234
[提交][状态][讨论版]
题目描述
给定一个字符串，求需要添加至少几个字符到字符串末尾才能使得整个字符串串由某一个不为本身的子串循环构成？
如"abca"，添加"bc"后构成"abcabc"，其由子串"abc"循环构成;也可以添加"abca"后构成"abcaabca"，其由子串"abca"循环构成，相比之下"bc"只有2个字符，添加的字符量最少。

输入
第一行包括一个整数T(1 <= T <= 100)，代表测试组数

每组测试数据包括一行字符串，其长度范围为 [3, 104]

输出
对于每组测试数据

输出一个整数N，代表添加的最小字符数量

样例输入
5
aaa
abca
abcdefg
abcabcabca
qweaqwec
样例输出
0
2
7
2
8
提示
*/

#include <cstdio>

char str[10001];
int next[10000];

int set_next()
{
    *next = 0;
    int i = 1;
    for (int j = 0; str[i]; ++i)
    {
        while (j > 0 && str[i] != str[j])
            j = next[j - 1];
        if (str[i] == str[j])
            ++j;
        next[i] = j;
    }
    return i;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%s", str);
        int len = set_next();
        int tmp = len - next[len - 1];
        printf("%d\n", (!(len % tmp) && len != tmp) ? 0 : tmp - len % tmp);
    }

    return 0;
}