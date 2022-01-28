/*
问题 B: DS顺序表--连续操作
时间限制: 1 Sec  内存限制: 128 MB
提交: 443  解决: 270
[提交][状态][讨论版]
题目描述
建立顺序表的类，属性包括：数组、实际长度、最大长度（设定为1000）

该类具有以下成员函数：

构造函数：实现顺序表的初始化。

插入多个数据的multiinsert(int i, int n, int item[])函数，实现在第i个位置，连续插入来自数组item的n个数据，即从位置i开始插入多个数据。

删除多个数据的multidel(int i, int n)函数，实现从第i个位置开始，连续删除n个数据，即从位置i开始删除多个数据。

编写main函数测试该顺序表类。

输入
第1行先输入n表示有n个数据，即n是实际长度；接着输入n个数据

第2行先输入i表示插入开始的位置，再输入k表示有k个插入数据，接着输入k个数据

第3行先输入i表示删除开始的位置，再输入k表示要删除k个数据

输出
顺序表内容包括顺序表的实际长度和数据，数据之间用空格隔开

第1行输出创建后的顺序表内容

第2行输出执行连续插入后的顺序表内容

第3行输出执行连续删除后的顺序表内容

 

样例输入
6 11 22 33 44 55 66
2 3 99 88 77
4 5
样例输出
6 11 22 33 44 55 66 
9 11 99 88 77 22 33 44 55 66 
4 11 99 88 66 
提示
*/

#include <iostream>

using namespace std;

class SeqList
{
private:
    int *list;
    int maxsize;
    int size;

public:
    SeqList();
    ~SeqList();
    void list_int(int n);
    int list_size();
    void list_insert(int i, int item);
    void list_multiinsert(int i, int n, int *item);
    void list_del(int i);
    void list_multidel(int i, int n);
    void list_get(int i);
    void list_display();
};

SeqList::SeqList()
{
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}

SeqList::~SeqList()
{
    delete[] list;
}

void SeqList::list_int(int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    size = n;
}

int SeqList::list_size()
{
    for (int i = 0; i < 1000; i++)
    {
        if (list[i] == '\0')
            size = i + 1;
    }
    return size;
}

void SeqList::list_insert(int i, int item)
{
    if ((i > 0) && (i <= (size + 1)))
    {
        for (int k = size; k >= i; k--)
        {
            list[k] = list[k - 1];
        }
        list[i - 1] = item;
        size++;
        list_display();
    }
    else
        cout << "error" << endl;
}

void SeqList::list_multiinsert(int i, int n, int *item)
{
    if ((i > 0) && (i <= (size + 1)))
    {
        for (int k = size + n - 1; k > i; k--)
        {
            list[k] = list[k - n];
        }
        for (int k = i - 1; k < i - 1 + n; k++)
        {
            list[k] = item[k - i + 1];
        }
        size += n;
        list_display();
    }
    else
        cout << "error" << endl;
}

void SeqList::list_del(int i)
{
    if ((i > 0) && (i <= size))
    {
        size--;
        for (int k = i - 1; k < size; k++)
        {
            list[k] = list[k + 1];
        }
        list_display();
    }
    else
        cout << "error" << endl;
}

void SeqList::list_multidel(int i, int n)
{
    if ((i > 0) && (i <= size))
    {
        size -= n;
        for (int k = i - 1; k < size; k++)
        {
            list[k] = list[k + n];
        }
        list_display();
    }
    else
        cout << "error" << endl;
}

void SeqList::list_get(int i)
{
    if ((i > 0) && (i <= size))
        cout << list[i - 1] << endl;
    else
        cout << "error" << endl;
}

void SeqList::list_display()
{
    cout << size << " ";
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    SeqList s;
    s.list_int(n);
    s.list_display();
    int i1, n1, i2, n2;
    cin >> i1 >> n1;
    int *item = new int[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> item[i];
    }
    s.list_multiinsert(i1, n1, item);
    cin >> i2 >> n2;
    s.list_multidel(i2, n2);
}
