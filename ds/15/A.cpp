/*
问题 A: DS排序--希尔排序
时间限制: 1 Sec  内存限制: 128 MB
提交: 239  解决: 140
[提交][状态][讨论版]
题目描述
给出一个数据序列，使用希尔排序算法进行降序排序。

间隔gap使用序列长度循环除2直到1

输入
第一行输入t，表示有t个测试示例
第二行输入n，表示第一个示例有n个数据(n>1)
第三行输入n个数据，都是正整数，数据之间用空格隔开
以此类推

输出
对每组测试数据，输出每趟排序结果。不同组测试数据间用空行分隔。

样例输入
2
6
111 22 6 444 333 55
8
77 555 33 1 444 77 666 2222
样例输出
444 333 55 111 22 6
444 333 111 55 22 6

444 555 666 2222 77 77 33 1
666 2222 444 555 77 77 33 1
2222 666 555 444 77 77 33 1
提示

*/

#include <cstdio>

int t, n, arr[1024];

void printArr()
{
    for (int i = 0; i < n; i++)
        printf(" %d" + !i, arr[i]);
    putchar('\n');
}

void shellSort()
{
    int gap = n;
    int index, value;
    while (gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            index = i - gap;
            value = arr[i];
            while (index >= 0 && arr[index] < value)
            {
                arr[index + gap] = arr[index];
                index -= gap;
            }
            arr[index + gap] = value;
        }
        printArr();
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", arr + i);
        shellSort();
        putchar('\n');
    }

    return 0;
}