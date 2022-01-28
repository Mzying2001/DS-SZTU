/*
问题 B: 图综合练习--拓扑排序
时间限制: 1 Sec  内存限制: 128 MB
提交: 121  解决: 104
[提交][状态][讨论版]
题目描述
已知有向图，顶点从0开始编号，求它的求拓扑有序序列。

拓扑排序算法：给出有向图邻接矩阵
1.逐列扫描矩阵，找出入度为0且编号最小的顶点v

2.输出v，并标识v已访问

3.把矩阵第v行全清0

重复上述步骤，直到所有顶点输出为止

--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求

输入
第一行输入一个整数t，表示有t个有向图

第二行输入n，表示图有n个顶点

第三行起，输入n行整数，表示图对应的邻接矩阵

以此类推输入下一个图的顶点数和邻接矩阵

输出
每行输出一个图的拓扑有序序列

样例输入
2
5
0 1 0 1 1
0 0 1 0 0
0 0 0 0 1
0 0 1 0 0
0 0 0 0 0
7
0 0 0 0 0 0 0
1 0 1 1 0 0 0
1 0 0 0 0 0 0
1 0 1 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 0 0 1 0 1 0
样例输出
0 1 3 2 4 
4 6 5 1 3 2 0 
提示
*/

#include <cstdio>

int matrix[128][128], vis[128], t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            for (int j = 0; j < n; j++)
                scanf("%d", matrix[i] + j);
        }

        for (int k = 0; k < n; k++)
        {
            int target;
            for (int i = 0; i < n; i++)
            {
                if (vis[i])
                    continue;
                bool flag = true;
                for (int j = 0; j < n; j++)
                {
                    if (matrix[j][i] == 1)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    target = i;
                    break;
                }
            }

            vis[target] = 1;
            printf("%d ", target);
            for (int i = 0; i < n; i++)
                matrix[target][i] = matrix[i][target] = -1;
        }
        putchar('\n');
    }

    return 0;
}