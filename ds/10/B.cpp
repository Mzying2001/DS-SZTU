/*
问题 B: DS图—图的邻接矩阵存储及度计算
时间限制: 1 Sec  内存限制: 128 MB
提交: 180  解决: 100
[提交][状态][讨论版]
题目描述
假设图用邻接矩阵存储。输入图的顶点信息和边信息，完成邻接矩阵的设置，并计算各顶点的入度、出度和度，并输出图中的孤立点（度为0的顶点）

--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
输入
测试次数T，每组测试数据格式如下：

图类型  顶点数 （D—有向图，U—无向图）

顶点信息

边数

每行一条边（顶点1 顶点2）或弧（弧尾 弧头）信息

输出
每组测试数据输出如下信息（具体输出格式见样例）：

图的邻接矩阵

按顶点信息输出各顶点的度（无向图）或各顶点的出度  入度  度（有向图）。孤立点的度信息不输出。

图的孤立点。若没有孤立点，不输出任何信息。

样例输入
2
D 5
V1 V2 V3 V4 V5
7
V1 V2
V1 V4
V2 V3
V3 V1
V3 V5
V4 V3
V4 V5
U 5
A B C D E
5
A B
A C
B D
D C
A D
样例输出
0 1 0 1 0
0 0 1 0 0
1 0 0 0 1
0 0 1 0 1
0 0 0 0 0
V1: 2 1 3
V2: 1 1 2
V3: 2 2 4
V4: 2 1 3
V5: 0 2 2
0 1 1 1 0
1 0 0 1 0
1 0 0 1 0
1 1 1 0 0
0 0 0 0 0
A: 3
B: 2
C: 2
D: 3
E
提示

*/

#include <iostream>

int matrix[128][128], io[128][2], count;
char name[128][128], buf1[128], buf2[128];

bool str_equals(char *a, char *b)
{
    while (*a && *b)
    {
        if (*a++ != *b++)
            return false;
    }
    return *a == *b;
}

int name_index_of(char *target)
{
    for (int i = 0; i < count; i++)
    {
        if (str_equals(name[i], target))
            return i;
    }
    return -1;
}

int main()
{
    int t;
    char type;
    std::cin >> t;

    while (t--)
    {
        std::cin >> type >> count;
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count; j++)
                matrix[i][j] = 0;
        }

        for (int i = 0; i < count; i++)
            std::cin >> name[i];

        int path_count;
        std::cin >> path_count;
        while (path_count--)
        {
            std::cin >> buf1 >> buf2;
            int i = name_index_of(buf1);
            int j = name_index_of(buf2);
            matrix[i][j] = 1;
            if (type == 'U')
                matrix[j][i] = 1;
        }

        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count; j++)
                std::cout << (" " + !j) << matrix[i][j];
            std::cout << std::endl;
        }

        if (type == 'U')
        {
            for (int i = 0; i < count; i++)
            {
                int d = 0;
                for (int j = 0; j < count; j++)
                    d += matrix[i][j];
                if (d)
                    std::cout << name[i] << ": " << d << std::endl;
            }
            for (int i = 0; i < count; i++)
            {
                int d = 0;
                for (int j = 0; j < count; j++)
                    d += matrix[i][j];
                if (!d)
                    std::cout << name[i] << std::endl;
            }
        }
        else
        {
            for (int i = 0; i < count; i++)
                io[i][0] = io[i][1] = 0;
            for (int i = 0; i < count; i++)
            {
                for (int j = 0; j < count; j++)
                {
                    if (matrix[i][j])
                    {
                        io[i][1]++;
                        io[j][0]++;
                    }
                }
            }

            for (int i = 0; i < count; i++)
            {
                if (io[i][0] || io[i][1])
                    std::cout << name[i] << ": "
                              << io[i][1] << " "
                              << io[i][0] << " "
                              << io[i][0] + io[i][1] << std::endl;
            }
            for (int i = 0; i < count; i++)
            {
                if (!(io[i][0] || io[i][1]))
                    std::cout << name[i] << std::endl;
            }
        }
    }

    return 0;
}