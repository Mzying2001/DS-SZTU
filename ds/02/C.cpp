/*
问题 C: DS顺序表--合并操作
时间限制: 1 Sec  内存限制: 128 MB
提交: 419  解决: 269
[提交][状态][讨论版]
题目描述
建立顺序表的类，属性包括：数组、实际长度、最大长度（设定为1000）

已知两个递增序列，把两个序列的数据合并到顺序表中，并使得顺序表的数据递增有序

输入
第1行先输入n表示有n个数据，接着输入n个数据，表示第1个序列，要求数据递增互不等

第2行先输入m表示有m个数据，接着输入m个数据，表示第2个序列，要求数据递增互不等

输出
顺序表内容包括顺序表的实际长度和数据，数据之间用空格隔开

第1行输出创建后的顺序表内容

样例输入
3 11 33 55
5 22 44 66 88 99
样例输出
8 11 22 33 44 55 66 88 99 
提示
*/

#include <iostream>

#define ok 0
#define error -1

class SeqList
{
private:
    int *list;
    int maxsize;
    int size;

public:
    SeqList()
    {
        maxsize = 1000;
        size = 0;
        list = new int[maxsize];
    }

    // ~SeqList()
    // {
    //     delete[] list;
    // }

    int list_size()
    {
        return size;
    }

    int list_insert(int i, int item)
    {
        --i;
        if (size == maxsize || i < 0 || i > size)
            return error;
        for (int j = size; j > i; --j)
            list[j] = list[j - 1];
        ++size;
        list[i] = item;
        return ok;
    }

    int list_del(int i)
    {
        --i;
        if (i < 0 || i >= size)
            return error;
        for (int j = i + 1; j < size; ++j)
            list[j - 1] = list[j];
        --size;
        return ok;
    }

    int list_get(int i)
    {
        --i;
        if (i < 0 || i >= size)
            return error;
        return list[i];
    }

    void list_display()
    {
        std::cout << size << ' ';
        for (int i = 0; i < size; ++i)
            std::cout << list[i] << ' ';
        std::cout << std::endl;
    }

    void push(int value)
    {
        list[size++] = value;
    }

    void init(int n)
    {
        while (n--)
        {
            int value;
            std::cin >> value;
            push(value);
        }
    }
};

void print_err()
{
    std::cout << "error" << std::endl;
}

int main()
{
    int n, m;
    SeqList a, b;

    std::cin >> n;
    a.init(n);
    std::cin >> m;
    b.init(m);

    std::cout << m + n << ' ';

    int i = 1, j = 1;
    while (i <= n && j <= m)
    {
        int aa = a.list_get(i);
        int bb = b.list_get(j);
        if (aa < bb)
        {
            std::cout << aa << ' ';
            ++i;
        }
        else
        {
            std::cout << bb << ' ';
            ++j;
        }
    }

    while (i <= n)
        std::cout << a.list_get(i++) << ' ';
    while (j <= m)
        std::cout << b.list_get(j++) << ' ';
    std::cout << std::endl;
    
    return 0;
}
