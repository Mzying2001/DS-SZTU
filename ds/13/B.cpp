/*
问题 B: DS静态查找之折半查找
时间限制: 1 Sec  内存限制: 128 MB
提交: 146  解决: 135
[提交][状态][讨论版]
题目描述
给出一个队列和要查找的数值，找出数值在队列中的位置，队列位置从1开始

要求使用折半查找算法

输入
第一行输入n，表示队列有n个数据
第二行输入n个数据，都是正整数，用空格隔开
第三行输入t，表示有t个要查找的数值
第四行起，输入t个数值，输入t行

输出
每行输出一个要查找的数值在队列的位置，如果查找不成功，输出字符串error

样例输入
8
11 22 33 44 55 66 77 88
3
22
88
99
样例输出
2
8
error
提示
*/

#include <cstdio>

int arr[1024];

int main()
{
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    scanf("%d", &t);

    while (t--)
    {
        int target;
        scanf("%d", &target);

        int l = 0, h = n - 1, i = -1;
        while (h >= l)
        {
            int m = l + (h - l) / 2;
            int val = arr[m];
            if (val == target)
            {
                i = m;
                break;
            }
            else if (val > target)
            {
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        if (i == -1)
        {
            puts("error");
        }
        else
        {
            printf("%d\n", i + 1);
        }
    }

    return 0;
}