/*
问题 F: DS哈希查找—二次探测再散列
时间限制: 1 Sec  内存限制: 128 MB
提交: 768  解决: 109
[提交][状态][讨论版]
题目描述
定义哈希函数为H(key) = key%11。输入表长（大于、等于11），输入关键字集合，用二次探测再散列构建哈希表，并查找给定关键字。探测时如遇到已存在于哈希表的相同数字，则新数字不存入。

输入
测试次数t

每组测试数据格式如下：

哈希表长m、关键字个数n

n个关键字

查找次数k

k个待查关键字

输出
对每组测试数据，输出以下信息：

构造的哈希表信息，数组中没有关键字的位置输出NULL

对k个待查关键字，分别输出：

0或1（0—不成功，1—成功）、比较次数、查找成功的位置（从1开始）

样例输入
1
12 10
22 19 21 8 9 30 33 4 41 13
4
22
15
30
41
样例输出
22 9 13 NULL 4 41 NULL 30 19 8 21 33
1 1 1
0 3
1 3 8
1 6 6
提示
*/

#include <cstdio>

#define NINF ((int)-1e9)
int *buf, base, t, m, n, k;

void insert_value(int value)
{
    int key = value % base;
    int i = key, off = 1, flag = 1;
    while (buf[i] != NINF && buf[i] != value)
    {
        i = key + flag * (off * off);
        flag *= -1;
        if (flag > 0)
            off++;
        i = (i + m) % m;
    }
    buf[i] = value;
}

int find_value(int value, int &time)
{
    int key = value % base;
    int i = key, off = 1, flag = 1;
    time = 1;
    while (buf[i] != NINF && buf[i] != value)
    {
        i = key + flag * (off * off);
        flag *= -1;
        if (flag > 0)
            off++;
        i = (i + m) % m;
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