/*
问题 C: DS树--带权路径和
时间限制: 1 Sec  内存限制: 128 MB
提交: 238  解决: 211
[提交][状态][讨论版]
题目描述
计算一棵二叉树的带权路径总和，即求赫夫曼树的带权路径和。

已知一棵二叉树的叶子权值，该二叉树的带权案路径和APL等于叶子权值乘于根节点到叶子的分支数，然后求总和。如下图中，叶子都用大写字母表示，权值对应为：A-7，B-6，C-2，D-3

树的带权路径和 = 7*1 + 6*2 + 2*3 + 3*3 = 34



本题二叉树的创建参考前面的方法

输入
第一行输入一个整数t，表示有t个二叉树

第二行输入一棵二叉树的先序遍历结果，空树用字符‘0’表示，注意输入全是英文字母和0，其中大写字母表示叶子

第三行先输入n表示有n个叶子，接着输入n个数据表示n个叶子的权值，权值的顺序和前面输入的大写字母顺序对应

以此类推输入下一棵二叉树

输出
输出每一棵二叉树的带权路径和

样例输入
2
xA00tB00zC00D00
4 7 6 2 3
ab0C00D00
2 10 20
样例输出
34
40
提示

*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

char buf[1024];
int len, sum;

std::queue<char> q;
std::map<char, int> map;

void get_sum(int &i, int j, int k)
{
    if (i < len)
    {
        char c = buf[i++];
        if (c != '0')
        {
            if (map.count(c))
                sum += k * map[c];
            get_sum(i, j * 2 + 1, k + 1);
            get_sum(i, j * 2 + 2, k + 1);
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
            if (buf[i + 1] == '0' && buf[i + 2] == '0')
                q.push(buf[i]);
        }

        int tmp;
        scanf("%d", &tmp);
        while (tmp--)
        {
            int i;
            scanf("%d", &i);
            map[q.front()] = i;
            q.pop();
        }

        int index = sum = 0;
        get_sum(index, 0, 0);
        map.clear();

        printf("%d\n", sum);
    }

    return 0;
}