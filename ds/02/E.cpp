/*
问题 E: DS单链表--类实现
时间限制: 1 Sec  内存限制: 128 MB
提交: 453  解决: 247
[提交][状态][讨论版]
题目描述
用C++语言和类实现单链表，含头结点

属性包括：data数据域、next指针域

操作包括：插入、删除、查找

注意：单链表不是数组，所以位置从1开始对应首结点，头结点不放数据

类定义参考



输入
n
第1行先输入n表示有n个数据，接着输入n个数据
第2行输入要插入的位置和新数据
第3行输入要插入的位置和新数据
第4行输入要删除的位置
第5行输入要删除的位置
第6行输入要查找的位置
第7行输入要查找的位置
输出
n
数据之间用空格隔开，

第1行输出创建后的单链表的数据

每成功执行一次操作（插入或删除），输出执行后的单链表数据

每成功执行一次查找，输出查找到的数据

如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出单链表

样例输入
6 11 22 33 44 55 66
3 777
1 888
1
11
0
5
样例输出
11 22 33 44 55 66 
11 22 777 33 44 55 66 
888 11 22 777 33 44 55 66 
11 22 777 33 44 55 66 
error
error
44
提示
*/

#include <iostream>

#define ok 0
#define error -1

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode() { next = NULL; }
};

class LinkList
{
public:
    ListNode *head, *tail;
    int len;

    LinkList()
    {
        head = new ListNode();
        tail = NULL;
        len = 0;
    }

    ~LinkList()
    {
        ListNode *p, *q;
        p = head;
        while (p != NULL)
        {
            q = p;
            p = p->next;
            delete q;
        }
        len = 0;
        head = NULL;
    }

    void push(int value)
    {
        if (len == 0)
        {
            head->next = new ListNode();
            head->next->data = value;
            tail = head->next;
        }
        else
        {
            tail->next = new ListNode();
            tail->next->data = value;
            tail = tail->next;
        }
        ++len;
    }

    ListNode *get_nth_pre_node(int n)
    {
        if (head == NULL)
            return NULL;
        ListNode *node = head;
        while (--n)
        {
            node = node->next;
            if (node == NULL)
                return NULL;
        }
        return node;
    }

    int LL_get(int i)
    {
        ListNode *node = get_nth_pre_node(i);
        if (node != NULL)
            node = node->next;
        return node == NULL ? error : node->data;
    }

    int LL_insert(int i, int item)
    {
        ListNode *node = get_nth_pre_node(i);
        if (node == NULL)
            return error;
        ListNode *newNode = new ListNode();
        newNode->data = item;
        newNode->next = node->next;
        node->next = newNode;
        ++len;
        return ok;
    }

    int LL_del(int i)
    {
        ListNode *node = get_nth_pre_node(i);
        if (node == NULL)
            return error;
        ListNode *target = node->next;
        if (target == NULL)
            return error;
        node->next = target->next;
        delete target;
        --len;
        return ok;
    }

    void LL_display()
    {
        ListNode *p = head->next;
        while (p != NULL)
        {
            std::cout << p->data << ' ';
            p = p->next;
        }
        std::cout << std::endl;
    }
};

void print_err()
{
    std::cout << "error" << std::endl;
}

int main()
{
    int n;
    LinkList list;

    std::cin >> n;
    while (n--)
    {
        int value;
        std::cin >> value;
        list.push(value);
    }
    list.LL_display();

    for (int i = 0; i < 2; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        if (list.LL_insert(a, b) == error)
            print_err();
        else
            list.LL_display();
    }

    for (int i = 0; i < 2; ++i)
    {
        int a;
        std::cin >> a;
        if (list.LL_del(a) == error)
            print_err();
        else
            list.LL_display();
    }

    for (int i = 0; i < 2; ++i)
    {
        int a, b;
        std::cin >> a;
        if ((b = list.LL_get(a)) == error)
            print_err();
        else
            std::cout << b << std::endl;
    }

    return 0;
}
