/*
问题 A: DS单链表--结点交换
时间限制: 1 Sec  内存限制: 128 MB
提交: 319  解决: 248
[提交][状态][讨论版]
题目描述
用C++实现含头结点的单链表，然后实现单链表的两个结点交换位置。

注意不能简单交换两个结点包含数据，必须通过修改指针来实现两个结点的位置交换

交换函数定义可以参考：

swap（int  pa, int pb)  //pa和pb表示两个结点在单链表的位置序号

swap (ListNode * p, ListNode * q)  //p和q表示指向两个结点的指针

输入
第1行先输入n表示有n个数据，接着输入n个数据

第2行输入要交换的两个结点位置

第3行输入要交换的两个结点位置

输出
第一行输出单链表创建后的所有数据，数据之间用空格隔开

第二行输出执行第1次交换操作后的单链表数据，数据之间用空格隔开

第三行输出执行第2次交换操作后的单链表数据，数据之间用空格隔开

如果发现输入位置不合法，输出字符串error，不必输出单链表

样例输入
5 11 22 33 44 55
1 4
2 6
样例输出
11 22 33 44 55 
44 22 33 11 55 
error
提示
注意要用链表实现哦！
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
        tail = NULL;
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

    ListNode *get_nth_node(int n)
    {
        ListNode *node = get_nth_pre_node(n);
        return node == NULL ? NULL : node->next;
    }

    int LL_get(int i)
    {
        ListNode *node = get_nth_node(i);
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
        if (i == len)
            tail = newNode;
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
        if (i == len)
            tail = node;
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

    int swap(int pa, int pb)
    {
        ListNode *a = get_nth_pre_node(pa);
        ListNode *b = get_nth_pre_node(pb);
        if ((a == NULL || a->next == NULL) ||
            (b == NULL || b->next == NULL))
            return error;
        int data_a = a->next->data;
        int data_b = b->next->data;
        LL_del(pb);
        LL_del(pa);
        LL_insert(pa, data_b);
        LL_insert(pb, data_a);
        return ok;
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
        int pa, pb, res;
        std::cin >> pa >> pb;
        res = list.swap(pa, pb);
        if (res == error)
            print_err();
        else
            list.LL_display();
    }

    return 0;
}
