/*
问题 A: 图综合练习--构建邻接表
时间限制: 1 Sec  内存限制: 128 MB
提交: 127  解决: 109
[提交][状态][讨论版]
题目描述


已知一有向图，构建该图对应的邻接表。

邻接表包含数组和单链表两种数据结构，其中每个数组元素也是单链表的头结点，数组元素包含两个属性，属性一是顶点编号info，属性二是指针域next指向与它相连的顶点信息。

单链表的每个结点也包含两个属性，属性一是顶点在数组的位置下标，属性二是指针域next指向下一个结点。

 

输入
第1行输入整数t，表示有t个图

第2行输入n和k，表示该图有n个顶点和k条弧。

第3行输入n个顶点。

第4行起输入k条弧的起点和终点，连续输入k行

以此类推输入下一个图

输出
输出每个图的邻接表，每行输出格式：数组下标 顶点编号-连接顶点下标-......-^，数组下标从0开始。

具体格式请参考样例数据，每行最后加入“^”表示NULL。

样例输入
1
5 7
A B C D E
A B
A D
A E
B D
C B
C E
E D
样例输出
0 A-1-3-4-^
1 B-3-^
2 C-1-4-^
3 D-^
4 E-3-^
提示

*/

#include <cstdio>
#include <map>

struct node
{
    char value;
    node *next;
    node() { next = NULL; }
    node(char val) : node() { value = val; }
} nodes[128];

int n, k;
std::map<char, int> map;

void clear()
{
    for (int i = 0; i < n; i++)
    {
        node *n = nodes[i].next;
        while (n != NULL)
        {
            node *tmp = n->next;
            delete n;
            n = tmp;
        }
        nodes[i].next = NULL;
    }
    map.clear();
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d%d\n", &n, &k);
        for (int i = 0; i < n; i++)
        {
            nodes[i].value = getchar();
            map[nodes[i].value] = i;
            getchar();
        }

        for (int i = 0; i < k; i++)
        {
            char from = getchar();
            getchar();
            char to = getchar();
            getchar();
            node *n = &nodes[map[from]];
            while (n->next != NULL)
                n = n->next;
            n->next = new node(to);
        }

        for (int i = 0; i < n; i++)
        {
            printf("%d %c-", i, nodes[i].value);
            node *n = nodes[i].next;
            while (n != NULL)
            {
                printf("%d-", map[n->value]);
                n = n->next;
            }
            puts("^");
        }

        clear();
    }

    return 0;
}