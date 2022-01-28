/*
问题 C: DS图遍历--深度优先搜索
时间限制: 1 Sec  内存限制: 128 MB
提交: 110  解决: 79
[提交][状态][讨论版]
题目描述
给出一个图的邻接矩阵，对图进行深度优先搜索，从顶点0开始

注意：图n个顶点编号从0到n-1

代码框架如下：





输入
第一行输入t，表示有t个测试实例

第二行输入n，表示第1个图有n个结点

第三行起，每行输入邻接矩阵的一行，以此类推输入n行

第i个结点与其他结点如果相连则为1，无连接则为0，数据之间用空格隔开

以此类推输入下一个示例

输出
每行输出一个图的深度优先搜索结果，结点编号之间用空格隔开

样例输入
2
4
0 0 1 1
0 0 1 1
1 1 0 1
1 1 1 0
5
0 0 0 1 1
0 0 1 0 0
0 1 0 1 1
1 0 1 0 0
1 0 1 0 0
样例输出
0 2 1 3 
0 3 2 1 4 
提示
*/

#include <iostream>

using namespace std;

class graph
{
    int count, **arr;
    bool *vis;
    void DFS(int v);

public:
    graph();
    ~graph();
    void DFS();
};

graph::graph()
{
    cin >> count;
    arr = new int *[count];
    vis = new bool[count];
    for (int i = 0; i < count; i++)
    {
        vis[i] = false;
        arr[i] = new int[count];
        for (int j = 0; j < count; j++)
            cin >> arr[i][j];
    }
}

graph::~graph()
{
    delete[] vis;
    for (int i = 0; i < count; i++)
        delete arr[i];
    delete arr;
}

void graph::DFS(int v)
{
    if (!vis[v])
    {
        vis[v] = true;
        cout << v << ' ';
        for (int i = 0; i < count; i++)
        {
            if (arr[v][i] == 1)
                DFS(i);
        }
    }
}

void graph::DFS()
{
    for (int i = 0; i < count; i++)
        DFS(i);
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        graph myGraph;
        myGraph.DFS();
    }

    return 0;
}
