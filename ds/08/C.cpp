/*
问题 C: DS树--二叉树高度
时间限制: 1 Sec  内存限制: 128 MB
提交: 153  解决: 114
[提交][状态][讨论版]
题目描述
给出一棵二叉树，求它的高度。二叉树的创建采用前面实验的方法。

注意，二叉树的层数是从1开始

输入

第一行输入一个整数t，表示有t个二叉树

第二行起输入每个二叉树的先序遍历结果，空树用字符‘0’表示，连续输入t行

输出
每行输出一个二叉树的高度

样例输入
1
AB0C00D00
样例输出
3
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
        if (buf[i++] != '0')
        {
            build_tree(i, j * 2 + 1);
            build_tree(i, j * 2 + 2);
        }
    }
}

inline int max(int i, int j)
{
    return i > j ? i : j;
}

int deepth(int i = 0)
{
    return tree[i] == '0' ? 0 : (max(deepth(i * 2 + 1), deepth(i * 2 + 2)) + 1);
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
        printf("%d\n", deepth());
    }

    return 0;
}