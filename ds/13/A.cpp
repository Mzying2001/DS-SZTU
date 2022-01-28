/*
问题 A: DS静态查找之顺序查找
时间限制: 1 Sec  内存限制: 128 MB
提交: 151  解决: 136
[提交][状态][讨论版]
题目描述
给出一个队列和要查找的数值，找出数值在队列中的位置，队列位置从1开始

要求使用带哨兵的顺序查找算法

输入
第一行输入n，表示队列有n个数据
第二行输入n个数据，都是正整数，用空格隔开
第三行输入t，表示有t个要查找的数值
第四行起，输入t个数值，输入t行

输出
每行输出一个要查找的数值在队列的位置，如果查找不成功，输出字符串error

样例输入
8
33 66 22 88 11 27 44 55
3
22
11
99
样例输出
3
5
error
提示
*/

#include <cstdio>
#include <cstring>

int buf[1024];

int main()
{
    memset(buf, 0, sizeof(buf));

    int n, t, count;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", buf + i);
    scanf("%d", &t);

    while (t--)
    {
        int value, index = 0;
        scanf("%d", &value);

        while (buf[index])
        {
            if (value == buf[index++])
            {
                printf("%d\n", index);
                break;
            }
        }

        if (buf[index - 1] != value)
            puts("error");
    }

    return 0;
}