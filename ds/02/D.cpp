/*
问题 D: DS顺序表之循环移位
时间限制: 1 Sec  内存限制: 128 MB
提交: 391  解决: 250
[提交][状态][讨论版]
题目描述
顺序表的移位是循环移位，例如顺序表：1，2，3，4，5，6。如果左移1位，即原来的头元素移动到末尾，其它元素向左移1位，变成2，3，4，5，6，1。同理，如果右移1位，即原来的尾元素移动到头，其它元素向右移1位，变成6，1，2，3，4，5。以下是移位的多个例子：

原数据：1，2，3，4，5，6

左移3位：4，5，6，1，2，3，与原数据对比

右移4位：3，4，5，6，1，2，与原数据对比

请编写程序实现顺序表的循环移位操作

输入
第1行输入n表示顺序表包含的·n个数据

第2行输入n个数据，数据是小于100的正整数

第3行输入移动方向和移动的位数，左移方向为0，右移方向为1

第4行输入移动方向和移动的位数，左移方向为0，右移方向为1

注意：移动操作是针对上一次移动后的结果进行的

输出
第一行输出创建后，顺序表内的所有数据，数据之间用空格隔开

第二行输出第一次移位操作后，顺序表内的所有数据，数据之间用空格隔开

第三行输出第二次移位操作后，顺序表内的所有数据，数据之间用空格隔开

样例输入
5
11 22 33 44 55
0 2
1 4
样例输出
11 22 33 44 55 
33 44 55 11 22 
44 55 11 22 33 
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

    void list_display(bool show_size = false)
    {
        if (show_size)
            std::cout << size << ' ';
        for (int i = 0; i < size; ++i)
            std::cout << list[i] << ' ';
        std::cout << std::endl;
    }

    void l_move(int step)
    {
        step %= size;
        SeqList temp;

        int index = 0;
        while (index < step)
            temp.push(list[index++]);

        while (index < size)
        {
            list[index - step] = list[index];
            ++index;
        }

        index -= step;
        for (int i = 0; i < temp.size; ++i, ++index)
            list[index] = temp.list_get(i + 1);
    }

    void r_move(int step)
    {
        step %= size;
        SeqList temp;

        int index = size - step;
        while (index < size)
        {
            temp.push(list[index]);
            list[index] = list[index - step];
            ++index;
        }

        for (int i = 1; i <= temp.size; ++i)
            list[i - 1] = temp.list_get(i);
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
    int n;
    std::cin >> n;

    SeqList list;
    list.init(n);
    list.list_display();

    int a, b;
    for (int i = 0; i < 2; ++i)
    {
        std::cin >> a >> b;
        if (a == 0)
            list.l_move(b);
        else
            list.r_move(b);
        list.list_display();
    }

    return 0;
}
