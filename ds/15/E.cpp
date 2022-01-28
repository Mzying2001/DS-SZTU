/*
问题 E: DS排序--折半插入排序
时间限制: 1 Sec  内存限制: 128 MB
提交: 170  解决: 124
[提交][状态][讨论版]
题目描述
给出一个数据序列，使用折半插入排序算法进行降序排序。

输入
第一行输入t，表示有t个测试示例
第二行输入n，表示第一个示例有n个数据(n>1)
第三行输入n个数据，都是正整数，数据之间用空格隔开
以此类推
输出
对每组测试数据，输出每趟排序结果。不同组测试数据间用空行分隔。

样例输入
2
5
111 22 6 444 333
8
30 13 70 85 39 42 6 20
样例输出
111 22 6 444 333
111 22 6 444 333
444 111 22 6 333
444 333 111 22 6

30 13 70 85 39 42 6 20
70 30 13 85 39 42 6 20
85 70 30 13 39 42 6 20
85 70 39 30 13 42 6 20
85 70 42 39 30 13 6 20
85 70 42 39 30 13 6 20
85 70 42 39 30 20 13 6

提示
*/

#include <iostream>

using namespace std;

void BinaryInsertSort(int *arr, int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        int low = 0;
        int high = i - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (temp > arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        int j;
        for (j = i - 1; j >= high + 1; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;

        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        BinaryInsertSort(arr, n);
        cout << endl;
    }
    return 0;
}