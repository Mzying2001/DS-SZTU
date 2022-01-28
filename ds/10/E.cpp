/*
问题 E: DS图—图非0面积
时间限制: 1 Sec  内存限制: 128 MB
提交: 75  解决: 45
[提交][状态][讨论版]
题目描述
编程计算由"1"围成的下列图形的面积。面积计算方法是统计"1"所围成的闭合曲线中"0"点的数目。如图所示，在10*10的二维数组中，"1"围住了15个点，因此面积为15。



输入
测试次数t

每组测试数据格式为：

数组大小m,n

一个由0和1组成的m*n的二维数组

输出
对每个二维数组，输出符号"1"围住的"0"的个数，即围成的面积。假设一定有1组成的闭合曲线，但不唯一。

样例输入
2
10 10
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 1 0 0 1 0 0
0 0 0 0 0 1 0 0 1 0
0 0 1 0 0 0 1 0 1 0
0 1 0 1 0 1 0 0 1 0
0 1 0 0 1 1 0 1 1 0
0 0 1 0 0 0 0 1 0 0
0 0 0 1 1 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0
5 8
0 1 1 0 0 1 1 0
1 0 1 0 1 0 0 1
0 1 0 1 0 0 1 0
0 1 0 0 1 1 1 0
0 0 0 0 0 0 0 0
样例输出
15
5
提示
*/

#include <cstdio>
#include <cstring>

int matrix[128][128], m, n;

void run(int i, int j)
{
    if (i >= 0 && i < m && j >= 0 && j < n && !matrix[i][j])
    {
        matrix[i][j] = 1;
        run(i + 1, j);
        run(i - 1, j);
        run(i, j + 1);
        run(i, j - 1);
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                scanf("%d", matrix[i] + j);
        }

        for (int i = 0; i < m; i++)
        {
            if (i == 0 || i == m - 1)
            {
                for (int j = 0; j < n; j++)
                    run(i, j);
            }
            else
            {
                run(i, 0);
                run(i, n - 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                ans += !matrix[i][j];
        }

        printf("%d\n", ans);
    }

    return 0;
}