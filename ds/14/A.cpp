/*
问题 A: DS查找—二叉树平衡因子
时间限制: 1 Sec  内存限制: 128 MB
提交: 146  解决: 124
[提交][状态][讨论版]
题目描述
二叉树用数组存储，将二叉树的结点数据依次自上而下,自左至右存储到数组中，一般二叉树与完全二叉树对比，比完全二叉树缺少的结点在数组中用0来表示。

计算二叉树每个结点的平衡因子，并按后序遍历的顺序输出结点的平衡因子。

--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
输入
测试次数t

每组测试数据一行，数组元素个数n，后跟n个字符，二叉树的数组存储。

输出
对每组测试数据，按后序遍历的顺序输出树中结点的平衡因子（测试数据没有空树）

样例输入
2
6 ABC00D
24 ABCD0EF0000H00000000000I


样例输出
B 0
D 0
C 1
A -1
D 0
B 1
I 0
H 1
E 2
F 0
C 2
A -2
提示
*/

#include <stdio.h>

int t, n;
char tree[1024];

int max(int a, int b)
{
    return a > b ? a : b;
}

int deepth(int i)
{
    return (i >= n || tree[i] == '0') ? 0 : (max(deepth(2 * i + 1), deepth(2 * i + 2)) + 1);
}

void suf_order(int i)
{
    if (i < n && tree[i] != '0')
    {
        suf_order(i * 2 + 1);
        suf_order(i * 2 + 2);
        printf("%c %d\n", tree[i], deepth(i * 2 + 1) - deepth(i * 2 + 2));
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s", &n, tree);
        suf_order(0);
    }

    return 0;
}