/*
问题 C: DS二叉树--左叶子数量
时间限制: 1 Sec  内存限制: 128 MB
提交: 257  解决: 231
[提交][状态][讨论版]
题目描述
计算一颗二叉树包含的叶子结点数量。

左叶子是指它的左右孩子为空，而且它是父亲的左孩子

提示：可以用三叉链表法，也可以用现有算法对两层结点进行判断

建树方法采用“先序遍历+空树用0表示”的方法

输入
第一行输入一个整数t，表示有t个测试数据

第二行起输入二叉树先序遍历的结果，空树用字符‘0’表示，输入t行

输出
逐行输出每个二叉树的包含的左叶子数量

样例输入
3
AB0C00D00
AB00C00
ABCD0000EF000

样例输出
0
1
2
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
                q.push(i);
        }

        int tmp = 0;
        build_tree(tmp, 0);

        int count = 0;
        while (!q.empty())
        {
            if (q.front() % 2)
                ++count;
            q.pop();
        }

        printf("%d\n", count);
    }

    return 0;
}