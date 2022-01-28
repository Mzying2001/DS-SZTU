/*
问题 F: DS内排—堆排序
时间限制: 1 Sec  内存限制: 128 MB
提交: 158  解决: 124
[提交][状态][讨论版]
题目描述
给定一组数据，使用堆排序完成数据的降序排序。（建小顶堆)。

输入
数据个数n，n个整数数据

输出
初始创建的小顶堆序列

每趟交换、筛选后的数据序列，输出格式见样例

样例输入
8 34 23 677 2 1 453 3 7

样例输出
8 1 2 3 7 23 453 677 34
8 2 7 3 34 23 453 677 1
8 3 7 453 34 23 677 2 1
8 7 23 453 34 677 3 2 1
8 23 34 453 677 7 3 2 1
8 34 677 453 23 7 3 2 1
8 453 677 34 23 7 3 2 1
8 677 453 34 23 7 3 2 1
提示
*/

#include <cstdio>

int n, arr[1024];

void printArr()
{
    printf("%d", n);
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
    putchar('\n');
}

void adjustHeap(int i, int len)
{
    int tmp = arr[i];
    for (int k = i * 2 + 1; k < len; k = k * 2 + 1)
    {
        if (k + 1 < len && arr[k] > arr[k + 1])
            k++;
        if (arr[k] < tmp)
        {
            arr[i] = arr[k];
            i = k;
        }
        else
            break;
    }
    arr[i] = tmp;
}

void heapSort()
{
    for (int i = n / 2 - 1; i >= 0; i--)
        adjustHeap(i, n);
    printArr();

    for (int j = n - 1; j > 0; j--)
    {
        int tmp = arr[j];
        arr[j] = arr[0];
        arr[0] = tmp;
        adjustHeap(0, j);
        printArr();
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    heapSort();
    putchar('\n');

    return 0;
}