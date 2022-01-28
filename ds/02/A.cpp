/*
问题 A: DS顺序表--类实现
时间限制: 1 Sec  内存限制: 128 MB
提交: 701  解决: 284
[提交][状态][讨论版]
题目描述
用C++语言和类实现顺序表

属性包括：数组、实际长度、最大长度（设定为1000）

操作包括：创建、插入、删除、查找

类定义参考



输入
第1行先输入n表示有n个数据，即n是实际长度；接着输入n个数据
第2行输入要插入的位置和新数据
第3行输入要插入的位置和新数据
第4行输入要删除的位置
第5行输入要删除的位置
第6行输入要查找的位置
第7行输入要查找的位置

输出
数据之间用空格隔开

第1行输出创建后的顺序表内容，包括顺序表实际长度和数据

每成功执行一次操作（插入或删除），输出执行后的顺序表内容

每成功执行一次查找，输出查找到的数据

如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出顺序表内容

样例输入
6 11 22 33 44 55 66
3 777
1 888
1
9
0
5
样例输出
6 11 22 33 44 55 66 
7 11 22 777 33 44 55 66 
8 888 11 22 777 33 44 55 66 
7 11 22 777 33 44 55 66 
error
error
44
提示
第i个位置是逻辑意义的位置，从1开始，在实际编程用数组，从0开始，对应数组i-1位置


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
};

void print_err()
{
    std::cout << "error" << std::endl;
}

int main()
{
    int n;
    std::cin >> n;

    SeqList list;
    for (int i = 0; i < n; ++i)
    {
        int in;
        std::cin >> in;
        list.push(in);
    }
    list.list_display();

    int a, b;

    for (int i = 0; i < 2; ++i)
    {
        std::cin >> a >> b;
        if (list.list_insert(a, b) == error)
            print_err();
        else
            list.list_display();
    }

    for (int i = 0; i < 2; ++i)
    {
        std::cin >> a;
        if (list.list_del(a) == error)
            print_err();
        else
            list.list_display();
    }

    for (int i = 0; i < 2; ++i)
    {
        std::cin >> a;
        if ((b = list.list_get(a)) == error)
            print_err();
        else
            std::cout << b << std::endl;
    }

    return 0;
}
