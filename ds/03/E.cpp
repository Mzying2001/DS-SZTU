/*
问题 E: DS单链表—删除重复元素
时间限制: 1 Sec  内存限制: 128 MB
提交: 96  解决: 71
[提交][状态][讨论版]
题目描述
给定n个整数，按输入顺序建立单链表，删除其中的重复数字，输出结果链表。（要求不可以构建新结点，不可以定义新链表。在原链表上删除。）

输入

测试次数t



每组测试数据一行：


n（表示有n个整数），后跟n个数字

输出
 对每组测试数据，输出删除重复数字后的结果链表表长和每个元素，具体格式见样例。

样例输入
3
10 1 2 3 4 1 2 10 20 30 20
5 1 1 1 1 1
6 20 22 22 22 22 20
样例输出
7: 1 2 3 4 10 20 30
1: 1
2: 20 22
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

int main()
{
    int t, n;
    std::cin >> t;

    while (t--)
    {
        std::cin >> n;
        LinkList list;
        while (n--)
        {
            int temp;
            std::cin >> temp;
            list.push(temp);
        }
        for (int i = 1; i <= list.len; ++i)
        {
            int value = list.LL_get(i);
            for (int j = i + 1; j <= list.len;)
            {
                if (list.LL_get(j) == value)
                    list.LL_del(j);
                else
                    ++j;
            }
        }
        std::cout << list.len << ':';
        ListNode *p = list.head->next;
        while (p != NULL)
        {
            std::cout << ' ' << p->data;
            p = p->next;
        }
        std::cout << std::endl;
    }

    return 0;
}
