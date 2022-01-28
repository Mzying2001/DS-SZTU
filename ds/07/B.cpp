/*
问题 B: DS二叉树——二叉树之父子结点
时间限制: 1 Sec  内存限制: 128 MB
提交: 266  解决: 236
[提交][状态][讨论版]
题目描述
给定一颗二叉树的逻辑结构如下图，（先序遍历的结果，空树用字符‘0’表示，例如AB0C00D00），建立该二叉树的二叉链式存储结构。

编写程序输出该树的所有叶子结点和它们的父亲结点



输入
第一行输入一个整数t，表示有t个二叉树

第二行起，按照题目表示的输入方法，输入每个二叉树的先序遍历，连续输入t行

输出
第一行按先序遍历，输出第1个示例的叶子节点

第二行输出第1个示例中与叶子相对应的父亲节点

以此类推输出其它示例的结果

 

样例输入
3
AB0C00D00
AB00C00
ABCD0000EF000
样例输出
C D 
B A 
B C 
A A 
D F 
C E 
提示
*/

#include <cstdio>
#include <cstring>
#include <queue>

char buf[1024], tree[1024];
int len;

std::queue<int> q;

void build_tree(int &i, int j)
{
    if (i < len)
    {
        tree[j] = buf[i];
        if (q.front() == i)
        {
            q.pop();
            q.push(j);
        }

        if (buf[i++] == '0')
            return;
        else
        {
            build_tree(i, j * 2 + 1);
            build_tree(i, j * 2 + 2);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%s", buf);
        len = strlen(buf);

        for (int i = 0; i < len - 2; ++i)
        {
            if (buf[i] != '0' && buf[i + 1] == '0' && buf[i + 2] == '0')
            {
                q.push(i);
                printf("%c ", buf[i]);
            }
        }
        putchar('\n');

        int tmp = 0;
        build_tree(tmp, 0);

        while (!q.empty())
        {
            printf("%c ", tree[(q.front() - 1) / 2]);
            q.pop();
        }
        putchar('\n');
    }

    return 0;
}