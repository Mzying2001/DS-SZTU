/*
问题 E: DS二叉树—二叉树结点的最大距离
时间限制: 1 Sec  内存限制: 128 MB
提交: 223  解决: 154
[提交][状态][讨论版]
题目描述
      二叉树两个结点的距离是一个结点经过双亲结点，祖先结点等中间结点到达另一个结点经过的分支数。二叉树结点的最大距离是所有结点间距离的最大值。例如，下图所示二叉树结点最大距离是3，C和D的距离。

          二叉树用先序遍历顺序创建，#表示空树。计算二叉树结点最大距离和最大距离的两个结点(假设二叉树中取最大距离的两个结点唯一）。



输入
测试次数T

第2行之后的T行，每行为一棵二叉树先序遍历结果（#表示空树）

输出
 对每棵二叉树，输出树的结点最大距离和最大距离的结点，输出格式见样例。

样例输入
4
A##
ABC##EF#G###D##
ABEH###F#K###
AB###
样例输出
0:
5:G D
4:H K
1:B A
提示
*/

#include <cstdio>
#include <cstring>
#include <map>

char buf[1024], tree[1024], leave[1024];
int len;

std::map<char, int> map;

void build_tree(int &i, int j)
{
    if (i < len)
    {
        char c = buf[i++];
        tree[j] = c;
        if (c != '#')
        {
            map[c] = j;
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

        if (len == 3)
        {
            puts("0:");
            continue;
        }
        else if (len == 5)
        {
            printf("1:%c %c\n", buf[1] == '#' ? buf[2] : buf[1], buf[0]);
            continue;
        }

        int tmp = 0;
        build_tree(tmp, 0);

        int leave_count = 0;
        for (int i = 0; i < len - 2; ++i)
        {
            if (buf[i] != '#' && buf[i + 1] == '#' && buf[i + 2] == '#')
                leave[leave_count++] = buf[i];
        }

        int max = 0, l_index, r_index;

        for (int i = 0; i < leave_count; ++i)
        {
            for (int j = 0; j < leave_count; ++j)
            {
                int l = map[leave[i]], r = map[leave[j]], c = 0;
                while (tree[l] != tree[r])
                {
                    if (l > r)
                        l = (l + 1) / 2 - 1;
                    else
                        r = (r + 1) / 2 - 1;
                    ++c;
                }
                if (c > max)
                {
                    max = c;
                    l_index = map[leave[i]];
                    r_index = map[leave[j]];
                }
            }
        }

        printf("%d:%c %c\n", max, tree[l_index], tree[r_index]);
        map.clear();
    }

    return 0;
}