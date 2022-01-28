/*
问题 B: DS内排—直插排序
时间限制: 1 Sec  内存限制: 128 MB
提交: 147  解决: 131
[提交][状态][讨论版]
题目描述
给定一组数据，使用直插排序完成数据的升序排序。

--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
输入
数据个数n，n个数据

输出
直插排序的每一趟排序结果

样例输入
7 34 23 677 2 1 453 3
样例输出
23 34 677 2 1 453 3
23 34 677 2 1 453 3
2 23 34 677 1 453 3
1 2 23 34 677 453 3
1 2 23 34 453 677 3
1 2 3 23 34 453 677
提示
*/

#include <cstdio>

int n, arr[1024];

void printArr()
{
    for (int i = 0; i < n; i++)
        printf(" %d" + !i, arr[i]);
    putchar('\n');
}

void insertSort()
{
    int index, value;
    for (int i = 1; i < n; i++)
    {
        index = i - 1;
        value = arr[i];
        while (index >= 0 && arr[index] > value)
        {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = value;
        printArr();
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    insertSort();

    return 0;
}