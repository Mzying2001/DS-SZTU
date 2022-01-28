/*
问题 C: DS静态查找之顺序索引查找
时间限制: 1 Sec  内存限制: 128 MB
提交: 171  解决: 135
[提交][状态][讨论版]
题目描述
给出一个队列和要查找的数值，找出数值在队列中的位置，队列位置从1开始

要求使用顺序索引查找算法，其中索引表查找和块内查找都采用不带哨兵、从头开始的顺序查找方法。

输入
第一行输入n，表示主表有n个数据
第二行输入n个数据，都是正整数，用空格隔开
第三行输入k，表示主表划分为k个块，k也是索引表的长度
第四行输入k个数据，表示索引表中每个块的最大值
第五行输入t，表示有t个要查找的数值
第六行起，输入t个数值，输入t行

输出
每行输出一个要查找的数值在队列的位置和查找次数，数据之间用短划线隔开，如果查找不成功，输出字符串error

样例输入
18
22 12 13 8 9 20 33 42 44 38 24 48 60 58 74 57 86 53
3
22 48 86
6
13
5
48
40
53
90
样例输出
3-4
error
12-8
error
18-9
error
提示
*/

#include <iostream>

using namespace std;

class SequentialIndexSearch
{
private:
    int n, k, *item;
    int *maxkey_index;
    int *startPosition_index;

public:
    SequentialIndexSearch(int n1, int k1, int *item1, int *a)
    {
        n = n1;
        k = k1;
        item = item1;
        maxkey_index = a;
        startPosition_index = new int[k];
        int p = 1;
        for (int i = 0; i < k; i++)
        {
            startPosition_index[i] = p + i * (n / k);
        }
    }

    int Search(int key)
    {
        for (int i = 0; i < k; i++)
        {
            if (maxkey_index[i] >= key)
            {
                int spi = startPosition_index[i];
                for (int j = spi; j < spi + (n / k); j++)
                {
                    if (item[j] == key)
                        return j;
                }
                return 0;
            }
        }
        return 0;
    }

    void Search_times(int key)
    {
        for (int i = 0; i < k; i++)
        {
            if (maxkey_index[i] >= key)
            {
                int spi = startPosition_index[i];
                for (int j = spi; j < spi + (n / k); j++)
                {
                    if (item[j] == key)
                    {
                        cout << j << "-" << (j - spi + 1) + (i + 1) << endl;
                        return;
                    }
                }
                cout << "error" << endl;
                return;
            }
        }
        cout << "error" << endl;
    }
};

int main()
{
    int n, k, t, key;
    cin >> n;

    int *item = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> item[i];
    }

    cin >> k;
    int *a = new int[k];
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }

    cin >> t;
    while (t--)
    {
        cin >> key;
        SequentialIndexSearch tmp(n, k, item, a);
        tmp.Search_times(key);
    }

    return 0;
}