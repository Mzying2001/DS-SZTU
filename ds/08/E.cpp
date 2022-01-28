/*
问题 E: 二叉树的中后序遍历及操作
时间限制: 1 Sec  内存限制: 128 MB
提交: 86  解决: 15
[提交][状态][讨论版]
题目描述
按中序遍历和后序遍历给出一棵二叉树，现在有如下操作：
1. UPDATE A B，将中序遍历中A位置（从1开始编号的下标）对应的在二叉树中的节点的权值改为B
2. QUERY，询问树上所有节点的权值，以及从根节点到该节点的路径权值之和
3. STOP，停止操作，STOP操作一定出现在最后
中序遍历和后序遍历的输入保证叶子节点的权值各不相同。但是，之后如果存在UPDATE操作，则UPDATE操作可能会使得两个或两个以上的叶子节点的权值相同。

输入
测试数据有多组
对于每组测试数据，
第一行输入这棵二叉树中序遍历的结果
第二行输入这棵二叉树后序遍历的结果
接下来每一行输入一种操作，直到输入STOP操作时结束本组测试数据的输入。其中，QUERY操作次数 <= 2，总操作数 <= 104
输入一直处理到文件尾(EOF)

输出
对于每组测试数据：
对于QUERY操作，按中序遍历输出节点的权值，以及从根节点到该节点路径权值之和。这里，我们认为根节点到其本身的路径权值之和为根节点的权值

样例输入
3 2 1 4 5 7 6
3 1 2 5 6 7 4
UPDATE 5 99
UPDATE 6 123
UPDATE 1 37
QUERY
UPDATE 1 36
QUERY
STOP
7 8 11 3 5 16 12 18
8 3 11 7 16 18 12 5
QUERY
STOP
255
255
STOP
样例输出
37 43
2 6
1 7
4 4
99 226
123 127
6 133
36 42
2 6
1 7
4 4
99 226
123 127
6 133

7 12
8 31
11 23
3 26
5 5
16 33
12 17
18 35

提示
*/

#include <iostream>
#include <string>
#include <map>

struct Node
{
    int data;
    Node *left, *right, *parent;
    Node() { left = right = parent = NULL; }
    Node(Node *parent) : Node() { this->parent = parent; }
};

void free_node(Node *node)
{
    if (node != NULL)
    {
        free_node(node->left);
        free_node(node->right);
        delete node;
    }
}

int in[10000], suf[10000], count;
std::map<int, Node *> map;

void read_arr(std::string &str, int *arr)
{
    int item = count = 0;
    for (char c : str)
    {
        if (c == ' ')
        {
            *arr++ = item;
            ++count;
            item = 0;
        }
        else
            item = item * 10 + c - '0';
    }
    if (item)
    {
        *arr = item;
        ++count;
    }
}

int index_of(int *arr, int value, int start_index = 0)
{
    for (int i = start_index; i < count; ++i)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

void build_tree(Node *node, int in_left, int in_right, int suf_left, int suf_right)
{
    if (in_left == in_right)
    {
        node->data = in[in_left];
        map[in_left] = node;
    }
    else if (in_left < in_right)
    {
        int data = suf[suf_right];
        int index = index_of(in, data, in_left);
        int lcount = index - in_left;

        node->left = new Node(node);
        node->right = new Node(node);
        build_tree(node->left, in_left, index - 1, suf_left, suf_left + lcount - 1);
        build_tree(node->right, index + 1, in_right, suf_left + lcount, suf_right - 1);

        node->data = data;
        map[index] = node;
    }
}

int main()
{
    std::string in_s, suf_s, cmd;
    while (std::getline(std::cin, in_s))
    {
        std::getline(std::cin, suf_s);

        read_arr(suf_s, suf);
        read_arr(in_s, in);

        map.clear();
        Node *head = new Node();
        build_tree(head, 0, count - 1, 0, count - 1);

        while (true)
        {
            std::cin >> cmd;
            if (cmd == "STOP")
            {
                std::cout << std::endl;
                getchar();
                break;
            }
            else if (cmd == "UPDATE")
            {
                int a, b;
                std::cin >> a >> b;
                map[a - 1]->data = b;
            }
            else if (cmd == "QUERY")
            {
                for (int i = 0; i < count; ++i)
                {
                    std::cout << map[i]->data << ' ';
                    int weight = 0;
                    for (Node *n = map[i]; n != NULL; n = n->parent)
                        weight += n->data;
                    std::cout << weight << std::endl;
                }
            }
        }

        free_node(head);
    }

    return 0;
}