/*
问题 C: 冒泡排序
时间限制: 1 Sec  内存限制: 128 MB
提交: 304  解决: 137
[提交][状态][讨论版]
题目描述
给定一个包含从0到n-1各一次的数组，若使用冒泡排序将其排为升序，问其中需要进行多少次交换

输入
测试数据有多组，

每组由两行组成：第一行包含正整数n（n <= 5000）; 下一行包含从0到n-1的n个整数的序列。

输出
对于每组测试数据，

输出交换次数

样例输入
10
1 3 6 9 0 8 5 7 4 2
样例输出
22
提示
*/

#include <cstdio>

int n, cnt, arr[5000];

void bubbleSort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                cnt++;
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);

    while (scanf("%d", &n) != EOF)
    {
        cnt = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", arr + i);
        bubbleSort();
        printf("%d\n", cnt);
    }

    return 0;
}