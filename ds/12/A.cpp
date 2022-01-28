/*
问题 A: DS图—图的最短路径（不含代码框架）
时间限制: 1 Sec  内存限制: 128 MB
提交: 157  解决: 119
[提交][状态][讨论版]
题目描述
给出一个图的邻接矩阵，输入顶点v，用迪杰斯特拉算法求顶点v到其它顶点的最短路径。

注：不允许用STL实现。

输入
 第一行输入t，表示有t个测试实例

第二行输入顶点数n和n个顶点信息

第三行起，每行输入邻接矩阵的一行，以此类推输入n行

第i个结点与其它结点如果相连则为距离，无连接则为0，数据之间用空格

隔开。第四行输入v0，表示求v0到其他顶点的最短路径距离

以此类推输入下一个示例

输出
对每组测试数据，输出：

每行输出v0到某个顶点的最短距离和最短路径

每行格式：v0编号-其他顶点编号-最短路径值----[最短路径]。没有路径输出：v0编号-其他顶点编号--1。具体请参考示范数据

样例输入
2
5 0 1 2 3 4
0 5 0 7 15
0 0 5 0 0
0 0 0 0 1
0 0 2 0 0
0 0 0 0 0
0
6 V0 V1 V2 V3 V4 V5
0 0 10 0 30 100
0 0 5 0 0 0
0 0 0 50 0 0
0 0 0 0 0 10
0 0 0 20 0 60
0 0 0 0 0 0
V0
样例输出
0-1-5----[0 1 ]
0-2-9----[0 3 2 ]
0-3-7----[0 3 ]
0-4-10----[0 3 2 4 ]
V0-V1--1
V0-V2-10----[V0 V2 ]
V0-V3-50----[V0 V4 V3 ]
V0-V4-30----[V0 V4 ]
V0-V5-60----[V0 V4 V3 V5 ]
提示
*/

#include <iostream>
#include <string>

#define MAX int(1e9)
using namespace std;

class Graph
{
private:
    int count, **matrix;
    string *names, *paths, start;

public:
    Graph()
    {
        cin >> count;
        names = new string[count];
        paths = new string[count];

        for (int i = 0; i < count; i++)
        {
            cin >> names[i];
            matrix = new int *[count];
        }

        for (int i = 0; i < count; i++)
        {
            matrix[i] = new int[count];
            for (int j = 0; j < count; j++)
            {
                cin >> matrix[i][j];
                if (matrix[i][j] == 0)
                    matrix[i][j] = MAX;
            }
        }

        cin >> start;
    }

    int indexOf(string a)
    {
        for (int i = 0; i < count; i++)
            if (a == names[i])
                return i;
        return -1;
    }

    void dijkstra()
    {
        int i, j, Current, min;
        bool *final = new bool[count];
        int *dest = new int[count];
        int index = indexOf(start);

        for (int i = 0; i < count; i++)
        {
            paths[i] = start + " ";
            dest[i] = matrix[index][i];
            final[i] = false;
        }

        dest[index] = 0;
        final[index] = true;
        for (i = 0; i < count - 1; i++)
        {
            min = MAX;
            Current = -1;
            for (j = 0; j < count; j++)
            {
                if (final[j] == false && min > dest[j])
                {
                    Current = j;
                    min = dest[j];
                }
            }
            if (Current != -1)
            {
                final[Current] = true;
                paths[Current] += names[Current] + " ";
                for (int q = 0; q < count; q++)
                {
                    if (final[q] == false && min + matrix[Current][q] < dest[q])
                    {
                        dest[q] = min + matrix[Current][q];
                        paths[q] = paths[Current];
                    }
                }
            }
        }

        for (int i = 1; i < count; i++)
        {
            cout << names[0] << "-" << names[i];
            if (dest[i] >= MAX)
            {
                cout << "--1" << endl;
                continue;
            }
            cout << "-" << dest[i] << "----[" << paths[i] << "]" << endl;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Graph g;
        g.dijkstra();
    }
    return 0;
}
