/*
问题 E: 道路建设 (Ver. I)
时间限制: 1 Sec  内存限制: 128 MB
提交: 107  解决: 42
[提交][状态][讨论版]
题目描述
有N个村庄，编号从1到N，你应该建造一些道路，使每个村庄都可以相互连接。

两个村A和B是相连的，当且仅当A和B之间有一条道路，或者存在一个村C使得在A和C之间有一条道路，并且C和B相连。

现在一些村庄之间已经有一些道路，你的任务就是修建一些道路，使所有村庄都连通起来，并且所有道路的长度总和是最小的。
输入
测试数据有多组

第一行是整数N（3 <= N <= 100），代表村庄的数量。 然后是N行，其中第i行包含N个整数，这些N个整数中的第j个是村庄i和村庄j之间的距离（距离是[1,1000]内的整数）。

然后是整数Q（0 <= Q <= N *（N + 1）/ 2），接下来是Q行，每行包含两个整数a和b（1 <= a <b <= N），代表着村庄a和村庄b之间的道路已经建成。
输出
对于每组测试数据

输出一个整数，表示要构建的道路的长度总和最小值

样例输入
3
0 990 692
990 0 179
692 179 0
1
1 2
样例输出
179
提示
*/

#include <cstdio>
#include <vector>
#include <algorithm>

struct Edge
{
    int start, end, weight;
};

bool cmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int n, q, ends[128];
std::vector<Edge> edges, result, done;

int get_end(int i)
{
    while (ends[i] != -1)
        i = ends[i];
    return i;
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        edges.clear();
        result.clear();
        done.clear();

        for (int i = 0; i < n; i++)
        {
            ends[i] = -1;
            for (int j = 0; j < n; j++)
            {
                int weight;
                scanf("%d", &weight);
                if (i != j)
                    edges.push_back({i, j, weight});
            }
        }

        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            int start, end;
            scanf("%d%d", &start, &end);
            done.push_back({start - 1, end - 1, 0});
        }

        for (Edge &item : done)
        {
            int e1 = get_end(item.start);
            int e2 = get_end(item.end);
            if (e1 != e2)
                ends[e1] = e2;

            for (Edge &tmp : edges)
            {
                if ((tmp.start == item.start && tmp.end == item.end) ||
                    (tmp.end == item.start && tmp.start == item.end))
                    tmp.weight = -1;
            }
        }

        std::sort(edges.begin(), edges.end(), cmp);

        for (Edge &item : edges)
        {
            if (item.weight == -1)
                continue;
            int e1 = get_end(item.start);
            int e2 = get_end(item.end);
            if (e1 != e2)
            {
                ends[e1] = e2;
                result.push_back(item);
            }
        }

        int ans = 0;
        for (Edge &item : result)
            ans += item.weight;

        printf("%d\n", ans);
    }
    return 0;
}