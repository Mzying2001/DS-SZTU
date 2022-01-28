/*
问题 D: DS串应用--串替换
时间限制: 1 Sec  内存限制: 128 MB
提交: 323  解决: 244
[提交][状态][讨论版]
题目描述
给出主串、模式串、替换串，用KMP算法找出模式串在主串的位置，然后用替换串的字符替换掉模式串

本题只考虑一处替换的情况，如果你想做的完美一些，能够实现多处替换那

可能需要考虑模式串和替换串长度不一致的情况

输入
第一个输入t，表示有t个实例

第二行输入第1个实例的主串，第三行输入第1个实例的模式串，第四行输入第1个实例的替换串

以此类推

输出
第一行输出第1个实例的主串

第二行输出第1个实例的主串替换后结果，如果没有发生替换就输出主串原来的内容。

以此类推

样例输入
3
aabbccdd
bb
ff
aaabbbccc
ddd
eee
abcdef
abc
ccccc
样例输出
aabbccdd
aaffccdd
aaabbbccc
aaabbbccc
abcdef
cccccdef
提示
*/

#include <cstdio>
#include <cstring>

char str[1024];
char pattern[1024];
char replace[1024];
int next[1024];

inline void set_next(int len)
{
    next[0] = 0;
    for (int i = 1, j = 0; i < len; ++i)
    {
        while (j > 1 && pattern[i] != pattern[j])
            j = next[j - 1];
        if (pattern[i] == pattern[j])
            ++j;
        next[i] = j;
    }
}

int kmp_search(int str_len, int pattern_len)
{
    set_next(pattern_len);
    for (int i = 0, j = 0; i < str_len; ++i)
    {
        while (j > 0 && str[i] != pattern[j])
            j = next[j - 1];
        if (str[i] == pattern[j] && ++j == pattern_len)
            return i - j + 1;
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%s%s%s", str, pattern, replace);
        int str_len = strlen(str);
        int pattern_len = strlen(pattern);
        int index = kmp_search(str_len, pattern_len);

        puts(str);

        if (index == -1)
            puts(str);
        else
        {
            str[index] = 0;
            printf("%s%s%s\n", str, replace, str + index + pattern_len);
        }
    }

    return 0;
}