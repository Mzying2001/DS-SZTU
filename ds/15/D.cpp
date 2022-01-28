/*
问题 D: DS排序—快速排序
时间限制: 1 Sec  内存限制: 128 MB
提交: 200  解决: 124
[提交][状态][讨论版]
题目描述
输入一组数据，用快速排序进行升序排序。

输入
测试次数t

每组测试数据为：

数据个数n，n个数字

输出
对每组测试数据，输出快速排序每趟排好的数字及位置（位置从1开始）。不同组测试数据的输出以空行分隔。

样例输入
2
6 111 22 6 444 333 55
8 77 555 33 1 444 77 10 200
样例输出
111 4
55 3
6 1
22 2
333 5
444 6

77 4
10 2
1 1
33 3
444 7
200 6
77 5
555 8
提示
*/

// #include <cstdio>

// int t, n, arr[1024], flag[1024];

// void quickSort(int left, int right)
// {
//     if (left >= right)
//     {
//         if (!flag[left])
//             printf("%d %d\n", arr[left], left + 1);
//         return;
//     }

//     int l = left, r = right, p = arr[l];
//     while (l < r)
//     {
//         while (l < r && arr[r] >= p)
//             r--;
//         if (l < r)
//             arr[l++] = arr[r];
//         while (l < r && arr[l] <= p)
//             l++;
//         if (l < r)
//             arr[r--] = arr[l];
//     }

//     flag[l] = 1;
//     printf("%d %d\n", p, l + 1);

//     arr[l] = p;
//     quickSort(left, l - 1);
//     quickSort(l + 1, right);
// }

// int main()
// {
//     // freopen("in.txt", "r", stdin);

//     scanf("%d", &t);
//     while (t--)
//     {
//         scanf("%d", &n);
//         for (int i = 0; i < n; i++)
//         {
//             scanf("%d", arr + i);
//             flag[i] = 0;
//         }
//         quickSort(0, n - 1);
//         putchar('\n');
//     }

//     return 0;
// }

#include <iostream>

using namespace std;

int GetPivot(int *item, int low, int high)
{
    int key = item[low];
    while (low < high)
    {
        while (low < high && item[high] >= key)
        {
            high--;
        }
        if (low < high)
        {
            item[low] = item[high];
        }

        while (low < high && item[low] <= key)
        {
            low++;
        }
        if (low < high)
        {
            item[high] = item[low];
        }
    }
    item[low] = key;
    return low;
}

void QuickSort(int *item, int low, int high)
{
    if (low <= high)
    {
        int pivotkey = GetPivot(item, low, high);
        cout << item[pivotkey] << " " << pivotkey + 1 << endl;
        QuickSort(item, low, pivotkey - 1);
        QuickSort(item, pivotkey + 1, high);
    }
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        QuickSort(arr, 0, n - 1);
        cout << endl;
    }
    return 0;
}