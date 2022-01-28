/*
问题 B: DS图—最小生成树
时间限制: 1 Sec  内存限制: 128 MB
提交: 101  解决: 51
[提交][状态][讨论版]
题目描述
根据输入创建无向网。分别用Prim算法和Kruskal算法构建最小生成树。（假设：输入数据的最小生成树唯一。）

输入
顶点数n

n个顶点

边数m

m条边信息,格式为：顶点1 顶点2 权值

Prim算法的起点v

输出
输出最小生成树的权值之和

对两种算法，按树的生长顺序，输出边信息(Kruskal中边顶点按数组序号升序输出)

样例输入
6
v1 v2 v3 v4 v5 v6 
10
v1 v2 6
v1 v3 1
v1 v4 5
v2 v3 5
v2 v5 3
v3 v4 5
v3 v5 6
v3 v6 4
v4 v6 2
v5 v6 6
v1
样例输出
15
prim:
v1 v3 1
v3 v6 4
v6 v4 2
v3 v2 5
v2 v5 3
kruskal:
v1 v3 1
v4 v6 2
v2 v5 3
v3 v6 4
v2 v3 5
提示

*/

// #include <iostream>
// #include <string>
// #include <vector>
// #include <map>
// #include <algorithm>

// struct edge
// {
//     int weight;
//     std::string from, to;
// };

// int cmp_edge(edge a, edge b)
// {
//     return a.weight < b.weight;
// }

// int m, n, weight[128][128];
// std::vector<edge> edges;
// std::vector<std::string> names;
// std::map<std::string, int> map;

// void prim(std::string &start)
// {
//     bool *visited = new bool[n];
//     for (int i = 0; i < n; i++)
//         visited[i] = false;
//     visited[map[start]] = true;

//     int h1 = -1, h2 = -1, min_weight = 1e8;
//     for (int k = 1; k < n; k++)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (visited[i] && !visited[j] && weight[i][j] < min_weight)
//                 {
//                     min_weight = weight[i][j];
//                     h1 = i;
//                     h2 = j;
//                 }
//             }
//         }
//         std::cout << names[h1] << " " << names[h2] << " " << min_weight << std::endl;
//         visited[h2] = true;
//         min_weight = 1e8;
//     }

//     delete[] visited;
// }

// int get_end(int *ends, int i)
// {
//     while (ends[i])
//         i = ends[i];
//     return i;
// }

// void kruskal()
// {
//     std::sort(edges.begin(), edges.end(), cmp_edge);
//     int *ends = new int[m];
//     for (int i = 0; i < m; i++)
//         ends[i] = 0;

//     for (edge &item : edges)
//     {
//         int p1 = map[item.from];
//         int p2 = map[item.to];
//         int e1 = get_end(ends, p1);
//         int e2 = get_end(ends, p2);
//         if (e1 != e2)
//         {
//             ends[e1] = e2;
//             std::cout << item.from << " " << item.to << " " << item.weight << std::endl;
//         }
//     }

//     delete[] ends;
// }

// int main()
// {
//     std::cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         std::string node;
//         std::cin >> node;
//         names.push_back(node);
//         map[node] = i;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//             weight[i][j] = 1e9;
//     }

//     std::cin >> m;
//     for (int i = 0; i < m; i++)
//     {
//         edge e;
//         std::cin >> e.from >> e.to >> e.weight;
//         edges.push_back(e);
//         weight[map[e.from]][map[e.to]] = e.weight;
//         weight[map[e.to]][map[e.from]] = e.weight;
//     }

//     std::string start;
//     std::cin >> start;

//     std::cout << "prim:" << std::endl;
//     prim(start);

//     std::cout << "kruskal:" << std::endl;
//     kruskal();

//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void prim(int **m, string *s, int n, string start_point)
{
    int *visit = new int[n];
    for (int i = 0; i < n; i++)
        visit[i] = 0;

    struct
    {
        string adj;
        int lowcost;
    } closedge[n];

    int temp;
    for (int i = 0; i < n; i++)
    {
        temp = m[i][0];
        closedge[i].adj = s[0];
        closedge[i].lowcost = temp;
        for (int j = 1; j < n; j++)
        {
            if (temp > m[i][j])
            {
                temp = m[i][j];
                closedge[i].adj = s[j];
                closedge[i].lowcost = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == start_point)
        {
            visit[i] = 1;
            break;
        }
    }

    int mmin, loc;
    string t;
    vector<string> v_one;          
    vector<string> v_two;          
    vector<int> the_min;           
    for (int i = 0; i < n - 1; i++)
    {
        mmin = 100000000;
        for (int j = 0; j < n; j++)
        {
            if (visit[j] != 1) 
                continue;
            else
            {
                if (mmin > closedge[j].lowcost)
                {
                    mmin = closedge[j].lowcost;
                    t = closedge[j].adj;       
                    loc = j;                   
                }
            }
        }

        v_one.push_back(s[loc]);
        v_two.push_back(t);
        the_min.push_back(mmin);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == t)
            {
                visit[i] = 1;        
                m[loc][i] = 10000000;
                m[i][loc] = 10000000;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            temp = m[i][0];
            closedge[i].adj = s[0];
            closedge[i].lowcost = temp;
            for (int j = 1; j < n; j++)
            {
                if (temp > m[i][j] && visit[j] != 1)
                {
                    temp = m[i][j];
                    closedge[i].adj = s[j];
                    closedge[i].lowcost = temp;
                }
            }
        }
    }
    int last = 0;
    for (int i = 0; i < v_one.size(); i++)
        last += the_min[i];
    cout << last << endl;
    cout << "prim:" << endl;
    for (int i = 0; i < v_one.size(); i++)
    {
        cout << v_one[i] << ' ' << v_two[i] << ' ' << the_min[i] << endl;
    }
    delete[] visit;
}

void kruskal(int **m, string *s, int n)
{
    cout << "kruskal:" << endl;
    int *father = new int[n];
    for (int i = 0; i < n; i++)
        father[i] = i;
    int temp_min;
    string s1, s2;
    int loc1, loc2;
    for (int i = 0; i < n - 1; i++)
    {
        temp_min = 10000000;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (father[j] == father[k])
                    continue;
                else
                {
                    if (temp_min > m[j][k])
                    {
                        temp_min = m[j][k];
                        loc1 = j;
                        loc2 = k;
                    }
                }
            }
        }
        m[loc1][loc2] = 10000000;
        m[loc2][loc1] = 10000000;
        if (loc1 > loc2)
        {
            cout << s[loc2] << ' ' << s[loc1] << ' ' << temp_min << endl;
            for (int i = 0; i < n; i++) 
            {
                if (father[i] == father[loc1] && i != loc1)
                    father[i] = father[loc2];
            }
            father[loc1] = father[loc2];
        }
        else
        {
            cout << s[loc1] << ' ' << s[loc2] << ' ' << temp_min << endl;
            for (int i = 0; i < n; i++)
            {
                if (father[i] == father[loc2] && i != loc2)
                    father[i] = father[loc1];
            }
            father[loc2] = father[loc1];
        }
    }
    delete[] father;
}

void run(int n)
{
    int k;
    string *s = new string[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int **m, **m1;
    m = new int *[n];
    m1 = new int *[n];
    for (int i = 0; i < n; i++)
    {
        m[i] = new int[n];
        m1[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            m[i][j] = 10000000;
            m1[i][j] = 10000000;
        }
    }
    cin >> k;
    string temp1, temp2;
    int flag1, flag2, cost;
    for (int i = 0; i < k; i++)
    {
        cin >> temp1 >> temp2 >> cost;
        for (int p = 0; p < n; p++)
        {
            if (s[p] == temp1)
                flag1 = p;
            if (s[p] == temp2)
                flag2 = p;
        }
        m[flag1][flag2] = cost;
        m[flag2][flag1] = cost;
        m1[flag1][flag2] = cost;
        m1[flag2][flag1] = cost;
    }
    string start_point;
    cin >> start_point;
    prim(m, s, n, start_point);
    kruskal(m1, s, n);
    delete[] m;
    delete[] m1;
    delete[] s;
}

int main()
{
    int t;
    while (cin >> t)
        run(t);
    return 0;
}