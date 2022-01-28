/*
问题 B: DS单链表--合并
时间限制: 1 Sec  内存限制: 128 MB
提交: 223  解决: 165
[提交][状态][讨论版]
题目描述
假定两个单链表是递增有序，定义并实现以下函数，完成两个单链表的合并，继续保持递增有序

int LL_merge(ListNode *La, ListNode *Lb)

输入
第1行先输入n表示有n个数据，接着输入n个数据
第2行先输入m表示有M个数据，接着输入m个数据
输出
输出合并后的单链表数据，数据之间用空格隔开

样例输入
3 11 33 55
4 22 44 66 88
样例输出
11 22 33 44 55 66 88 
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

void LL_merge(ListNode *La, ListNode *Lb)
{
    while (La != NULL && Lb != NULL)
    {
        int data_a = La->data;
        int data_b = Lb->data;
        if (data_a < data_b)
        {
            std::cout << data_a;
            La = La->next;
        }
        else
        {
            std::cout << data_b;
            Lb = Lb->next;
        }
        std::cout << ' ';
    }
    while (La != NULL)
    {
        std::cout << La->data << ' ';
        La = La->next;
    }
    while (Lb != NULL)
    {
        std::cout << Lb->data << ' ';
        Lb = Lb->next;
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    LinkList la, lb;

    std::cin >> n;
    while (n--)
    {
        int value;
        std::cin >> value;
        la.push(value);
    }
    std::cin >> n;
    while (n--)
    {
        int value;
        std::cin >> value;
        lb.push(value);
    }

    LL_merge(la.head->next, lb.head->next);

    return 0;
}
