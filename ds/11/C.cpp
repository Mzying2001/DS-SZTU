/*
问题 C: DS图—图的连通分量
时间限制: 1 Sec  内存限制: 128 MB
提交: 142  解决: 97
[提交][状态][讨论版]
题目描述
输入无向图顶点信息和边信息，创建图的邻接矩阵存储结构，计算图的连通分量个数。

输入
测试次数t

每组测试数据格式如下：

第一行：顶点数 顶点信息

第二行：边数

第三行开始，每行一条边信息

输出
每组测试数据输出，顶点信息和邻接矩阵信息

输出图的连通分量个数，具体输出格式见样例。

每组输出直接用空行分隔。

样例输入
3
4 A B C D
2
A B
A C
6 V1 V2 V3 V4 V5 V6
5
V1 V2
V1 V3
V2 V4
V5 V6
V3 V5
8 1 2 3 4 5 6 7 8
5
1 2
1 3
5 6
5 7
4 8
样例输出
A B C D
0 1 1 0
1 0 0 0
1 0 0 0
0 0 0 0
2

V1 V2 V3 V4 V5 V6
0 1 1 0 0 0
1 0 0 1 0 0
1 0 0 0 1 0
0 1 0 0 0 0
0 0 1 0 0 1
0 0 0 0 1 0
1

1 2 3 4 5 6 7 8
0 1 1 0 0 0 0 0
1 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1
0 0 0 0 0 1 1 0
0 0 0 0 1 0 0 0
0 0 0 0 1 0 0 0
0 0 0 1 0 0 0 0
3
提示
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define MAX_LEN 20

class Graph
{
private:
    bool vis[MAX_LEN];
    int matrix[MAX_LEN][MAX_LEN];
    int vexnum;
    void Bfs(int v);

public:
    void SetMatrix(int vnum, int **mx);
    void BfsTraverse();
    int Get();
};

void Graph::BfsTraverse()
{
    cout << 0 << ' ';
    vis[0] = true;
    Bfs(0);
    cout << endl;
}

void Graph::Bfs(int v)
{
    vis[v] = true;
    queue<int> q;
    for (int i = 0; i < vexnum; i++)
    {
        if (matrix[v][i] != 0 && !vis[i])
            q.push(i);
    }
    while (!q.empty())
    {
        Bfs(q.front());
        q.pop();
    }
}

void Graph::SetMatrix(int vnum, int **mx)
{
    for (int i = 0; i < vexnum; i++)
        vis[i] = false;
    int i, j;
    vexnum = vnum;
    for (i = 0; i < MAX_LEN; i++)
        for (j = 0; j < MAX_LEN; j++)
            matrix[i][j] = 0;
    for (i = 0; i < vexnum; i++)
        for (j = 0; j < vexnum; j++)
            matrix[i][j] = mx[i][j];
}

int Graph::Get()
{
    int sum = 0;
    for (int i = 0; i < vexnum; i++)
    {
        if (!vis[i])
        {
            Bfs(i);
            sum++;
        }
    }
    return sum;
}

void run()
{
    int n, k;
    cin >> n;

    string *s = new string[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
        
    int **m;
    m = new int *[n];
    for (int i = 0; i < n; i++)
    {
        m[i] = new int[n];
        for (int j = 0; j < n; j++)
            m[i][j] = 0;
    }

    cin >> k;
    string temp1, temp2;
    int flag1, flag2;
    for (int i = 0; i < k; i++)
    {
        cin >> temp1 >> temp2;
        for (int p = 0; p < n; p++)
        {
            if (s[p] == temp1)
                flag1 = p;
            if (s[p] == temp2)
                flag2 = p;
        }
        m[flag1][flag2] = 1;
        m[flag2][flag1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << s[i];
        else
            cout << s[i] << ' ';
    }
    
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
                cout << m[i][j];
            else
                cout << m[i][j] << ' ';
        }
        cout << endl;
    }

    Graph t;
    t.SetMatrix(n, m);
    cout << t.Get() << endl
         << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        run();
}