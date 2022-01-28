/*
问题 D: DS二叉树--基于数组存储的构建
时间限制: 1 Sec  内存限制: 128 MB
提交: 258  解决: 196
[提交][状态][讨论版]
题目描述
任意二叉树可以根据完全二叉树性质保存在一个数组中。已知二叉树的数组存储，用程序构建该二叉树。

提示：用递归方法或非递归都可以

递归方法的代码框架如下：

 



输入
第一行输入一个整数t，表示有t个测试数据

第二行起输入二叉树的数组存储结果，空树用字符‘0’表示，输入t行

数组的数据由大写字母和0表示

输出
逐行输出每个二叉树的先序结果

样例输入
3
ABC0D
ABCDEF000G
ABEC0F0D0
样例输出
ABDC
ABDEGCF
ABCDEF
提示
*/

#include <cstdio>
#include <cstring>

char buf[1024];
int len;

void pre_order(int i)
{
    if (i < len && buf[i] != '0')
    {
        putchar(buf[i]);
        pre_order(i * 2 + 1);
        pre_order(i * 2 + 2);
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
        pre_order(0);
        putchar('\n');
    }

    return 0;
}