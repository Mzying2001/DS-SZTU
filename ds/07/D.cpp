/*
问题 D: DS二叉树--叶子数量
时间限制: 1 Sec  内存限制: 128 MB
提交: 258  解决: 231
[提交][状态][讨论版]
题目描述
计算一颗二叉树包含的叶子结点数量。

提示：叶子是指它的左右孩子为空。

建树方法采用“先序遍历+空树用0表示”的方法，即给定一颗二叉树的先序遍历的结果为AB0C00D00，其中空节点用字符‘0’表示。则该树的逻辑结构如下图。



输入
第一行输入一个整数t，表示有t个测试数据

第二行起输入二叉树先序遍历的结果，空树用字符‘0’表示，输入t行

输出
逐行输出每个二叉树的包含的叶子数量

样例输入
3
AB0C00D00
AB00C00
ABC00D00E00
样例输出
2
2
3
提示
*/

#include <cstdio>
#include <cstring>

char buf[1024];
int len = 0;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%s", buf);
        len = strlen(buf);

        int count = 0;
        for (int i = 0; i < len - 2; ++i)
        {
            if (buf[i] != '0' && buf[i + 1] == '0' && buf[i + 2] == '0')
                ++count;
        }

        printf("%d\n", count);
    }

    return 0;
}