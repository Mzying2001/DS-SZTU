/*
问题 B: DS二叉树--同一棵二叉树？
时间限制: 1 Sec  内存限制: 128 MB
提交: 255  解决: 116
[提交][状态][讨论版]
题目描述
二叉树分别以数组存储方式创建、以先序遍历序列创建。输入二叉树的数组存储、先序遍历结果，判断根据它们创建的二叉树是否是同一棵二叉树。

输入
 测试次数t

每组测试数据两行：

第一行：二叉树的数组存储（英文字母表示树结点，#表示空树）

第二行：二叉树的先序遍历结果(英文字母表示树结点，#表示空树）

输出
 对每组测试数据，如果两种方式创建的是同一棵二叉树，输出YES，否则，输出NO。

样例输入
3
ABCDE
ABD##E##C##
ABC##DE####W##F
AB##CDW###E#F##
abc##d
ab##c#d


样例输出
YES
YES
NO
提示
*/

#include <cstdio>
#include <cstring>

char buf[1024], tree1[1024], tree2[1024];
int len;

void build_tree1(int &i, int j)
{
    if (i < len)
    {
        tree1[j] = buf[i];
        if (buf[i++] != '#' && buf[i])
        {
            build_tree1(i, j * 2 + 1);
            build_tree1(i, j * 2 + 2);
        }
    }
}

bool check()
{
    for (char *c1 = tree1, *c2 = tree2; *c2; ++c1, ++c2)
    {
        if (*c1 != *c2)
            return false;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%s%s", tree2, buf);
        len = strlen(buf);

        int tmp = 0;
        build_tree1(tmp, 0);
        printf("%s\n", check() ? "YES" : "NO");
    }

    return 0;
}