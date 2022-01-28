/*
问题 B: 数组最大值（指针作为函数参数）
时间限制: 1 Sec  内存限制: 128 MB
提交: 235  解决: 142
[提交][状态][讨论版]
题目描述
写函数void search(int *num,int n,int *nmax,int *nmaxindex)实现在含n各元素的数组num中查找最大值及其第一次出现下标，分别通过指针nmax,nmaxindex返回。

写函数void input(int *num,int n)，输入数组num的n个数。

主函数输入数据，调用input, search, 输出最大值及其第一次出现下标。

不可以在主函数中计算。

输入
测试次数t

每组测试数据一行: 数据个数n(n>1)  n个整数

输出
每组测试数据输出一行:

数组最大值  数组最大值第一次出现下标（下标从0开始）

样例输入
2
10 1 2 3 4 5 6 7 8 9 -10
20 9 10 20 40 50 999999 -99 999998 0 9 20 11 12 432 53 3421 6 42 43 34
样例输出
9 8
999999 5
提示

*/

#include <iostream>

void input(int *num, int n)
{
    while (n--)
        std::cin >> *num++;
}

void search(int *num, int n, int *nmax, int *nmaxindex)
{
    for (int i = 0; i < n; ++i)
    {
        int tmp = *num++;
        if (tmp > *nmax)
        {
            *nmax = tmp;
            *nmaxindex = i;
        }
    }
}

int main()
{
    int t, n;
    std::cin >> t;

    while (t--)
    {
        std::cin >> n;
        int *arr = new int[n];
        input(arr, n);

        int nmax = (-2147483647 - 1), nmaxindex = 0;
        search(arr, n, &nmax, &nmaxindex);
        std::cout << nmax << ' ' << nmaxindex << std::endl;

        delete[] arr;
    }

    return 0;
}
