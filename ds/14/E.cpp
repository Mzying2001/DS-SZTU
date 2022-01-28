/*
问题 E: DS哈希查找—线性探测再散列
时间限制: 1 Sec  内存限制: 128 MB
提交: 198  解决: 140
[提交][状态][讨论版]
题目描述
 定义哈希函数为H(key) = key%11，输入表长（大于、等于11）。输入关键字集合，用线性探测再散列构建哈希表，并查找给定关键字。

--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
输入
 测试次数t

每组测试数据为：

哈希表长m、关键字个数n

n个关键字

查找次数k

k个待查关键字

输出
对每组测试数据，输出以下信息：

构造的哈希表信息，数组中没有关键字的位置输出NULL

对k个待查关键字，分别输出：0或1（0—不成功，1—成功）、比较次数、查找成功的位置（从1开始）

样例输入
1
12 10
22 19 21 8 9 30 33 4 15 14
4
22
56
30
17
样例输出
22 30 33 14 4 15 NULL NULL 19 8 21 9
1 1 1
0 6
1 6 2
0 1
提示
*/

#include <cstdio>

#define NINF (-1e9)
int *buf, base, t, m, n, k;

void insert_value(int value)
{
    int i = value % base;
    while (buf[i] != NINF && buf[i] != value)
        i = (i + 1) % m;
    buf[i] = value;
}

int find_value(int value, int &time)
{
    int i = value % base; 
    time = 1;
    while (buf[i] != NINF && buf[i] != value)
    {
        i = (i + 1) % m;
        time++;
    }
    return buf[i] == value ? i : -1;
}

int main()
{
    // freopen("in.txt", "r", stdin);

    base = 11;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &m, &n);

        buf = new int[m];
        for (int i = 0; i < m; i++)
            buf[i] = NINF;
        
        while (n--)
        {
            int tmp;
            scanf("%d", &tmp);
            insert_value(tmp);
        }

        for (int i = 0; i < m; i++)
        {
            if (buf[i] == NINF)
                printf(" NULL" + !i);
            else
                printf(" %d" + !i, buf[i]);
        }
        putchar('\n');

        scanf("%d", &k);
        while (k--)
        {
            int tmp, time, i;
            scanf("%d", &tmp);
            i = find_value(tmp, time);

            if (i == -1)
                printf("0 %d\n", time);
            else
                printf("1 %d %d\n", time, i + 1);
        }

        delete[] buf;
    }
    return 0;
}