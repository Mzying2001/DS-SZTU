/*
问题 E: DS二叉树--二叉树构建与遍历（含代码框架）
时间限制: 1 Sec  内存限制: 128 MB
提交: 335  解决: 231
[提交][状态][讨论版]
题目描述
给定一颗二叉树的逻辑结构如下图，（先序遍历的结果，空树用字符‘0’表示，例如AB0C00D00），建立该二叉树的二叉链式存储结构，并输出该二叉树的先序遍历、中序遍历和后序遍历结果



本题目的代码框架参考如下



三种遍历的代码框架



主函数如下：


输入
第一行输入一个整数t，表示有t个二叉树

第二行起输入每个二叉树的先序遍历结果，空树用字符‘0’表示，连续输入t行

输出
输出每个二叉树的先序遍历、中序遍历和后序遍历结果

样例输入
2
AB0C00D00
AB00C00
样例输出
ABCD
BCAD
CBDA
ABC
BAC
BCA
提示

*/

#include <cstdio>
#include <cstring>

char buf[1024], tree[1024];
int len;

void build_tree(int &i, int j)
{
    if (i < len)
    {
        tree[j] = buf[i];
        if (buf[i] != '0')
        {
            putchar(buf[i++]);
            build_tree(i, j * 2 + 1);
            build_tree(i, j * 2 + 2);
        }
        else
            ++i;
    }
}

void inorder(int i)
{
    if (tree[i] != '0')
    {
        inorder(i * 2 + 1);
        putchar(tree[i]);
        inorder(i * 2 + 2);
    }
}

void suforder(int i)
{
    if (tree[i] != '0')
    {
        suforder(i * 2 + 1);
        suforder(i * 2 + 2);
        putchar(tree[i]);
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

        int tmp = 0;
        build_tree(tmp, 0);
        putchar('\n');

        inorder(0);
        putchar('\n');

        suforder(0);
        putchar('\n');
    }

    return 0;
}