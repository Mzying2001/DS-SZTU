/*
问题 A: 图的应用之——图的连通
时间限制: 1 Sec  内存限制: 128 MB
提交: 206  解决: 120
[提交][状态][讨论版]
题目描述
给定一个图的邻接矩阵，请判断该图是否是连通图。连通图：任意两个顶点之间都有路径。
--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
输入
第1行输入一个整数k，表示有k个测试数据
第2行输入一个整数n，表示有n个结点
从第3行起到第n+2行输入一个邻接矩阵，其中Matrix[i,j]=1表示第i，j个结点之间有边，否则不存在边。
接下来是第2到第k个测试数据的结点数和邻接矩阵
输出
输出Yes or No表示图是否是强连通图
样例输入
2
4
0 1 1 1 
1 0 1 1 
1 1 0 1 
1 1 1 0 
7
0 1 0 0 0 0 0 
0 0 1 1 0 0 0 
1 0 0 0 0 0 0 
1 0 1 0 0 0 0 
0 0 0 0 0 1 1 
0 1 0 0 0 0 0 
0 0 0 1 0 1 0 
样例输出
Yes
No
提示
*/

#include <iostream>

using namespace std;
#define MAX_LEN 50

bool check(int n, int m[MAX_LEN][MAX_LEN])
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[i][j] == 0 && m[i][k] == 1 && m[k][j] == 1)
                    m[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else
            {
                if (m[i][j] != 1 || m[j][i] != 1)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int m[MAX_LEN][MAX_LEN];

        for (int i = 0; i < MAX_LEN; i++)
            for (int j = 0; j < MAX_LEN; j++)
                m[i][j] = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> m[i][j];

        cout << (check(n, m) ? "Yes" : "No") << endl;
    }

    return 0;
}