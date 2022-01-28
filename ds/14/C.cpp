/*
问题 C: DS二叉树--二叉搜索树模拟
时间限制: 1 Sec  内存限制: 128 MB
提交: 284  解决: 81
[提交][状态][讨论版]
题目描述
二叉搜索树（Binary Search Tree，BST），是一种具有以下属性的二进制树：

每个节点都有一个Key值，可用于相互比较。
对于树中的每个节点，其左子树中的每个Key值均小于其自己的Key值。
对于树中的每个节点，其右子树中的每个Key值都等于或大于其自己的Key值。
现在我们需要模拟一个BST，我们只需要一种操作：插入。

首先，我们有一个空的BST。输入是一个数字序列。我们需要一个接一个地按以下规则插入：

如果插入的值小于根的值，则将其插入到左子树中。

如果插入的值大于或等于根的值，则将其插入到右子树中。

每次输入后，我们需要输出前序，中序，后序遍历序列。

看下面的例子：

整数是5个整数的序列：3 6 9 5 1

在每个整数插入后，树的结构如下所示：





输入
输入的第一个整数是 T，即测试用例的数量。
每个测试用例都有两行。
第一行包含一个整数 N，（1 <=N <= 1000），需要在BST中插入数字的数量。
第二行包含以空格分隔的 N 个整数，每个整数的范围为[0,230]。

输出
每个测试用例的输出必须包含三行：先序，中序和后序遍历序列。

每行中的数字应以单个空格分隔，并且不应在行末输出任何内容！

每组数据末尾输出一个空行（输出多组数据的话末尾用空行隔开）。

样例输入
1
5
3 6 9 5 1
样例输出
3 1 6 5 9
1 3 5 6 9
1 5 9 6 3
提示
*/

#include <cstdio>
#include <queue>

struct BSTNode
{
    int value;
    BSTNode *left, *right;
    BSTNode() { left = right = NULL; }
    BSTNode(int value) : BSTNode() { this->value = value; }

    ~BSTNode()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
    }

    void Insert(BSTNode *node)
    {
        if (node->value < value)
        {
            if (left != NULL)
                left->Insert(node);
            else
                left = node;
        }
        else
        {
            if (right != NULL)
                right->Insert(node);
            else
                right = node;
        }
    }

    void Insert(int value)
    {
        Insert(new BSTNode(value));
    }
};

void pre_order(BSTNode *node, std::queue<int> &q)
{
    if (node != NULL)
    {
        q.push(node->value);
        pre_order(node->left, q);
        pre_order(node->right, q);
    }
}

void in_order(BSTNode *node, std::queue<int> &q)
{
    if (node != NULL)
    {
        in_order(node->left, q);
        q.push(node->value);
        in_order(node->right, q);
    }
}

void suf_order(BSTNode *node, std::queue<int> &q)
{
    if (node != NULL)
    {
        suf_order(node->left, q);
        suf_order(node->right, q);
        q.push(node->value);
    }
}

void output(std::queue<int> &q)
{
    for (int i = 0; !q.empty(); i++)
    {
        printf(" %d" + !i, q.front());
        q.pop();
    }
    putchar('\n');
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);

        BSTNode *root = NULL;
        std::queue<int> q;

        while (n--)
        {
            int value;
            scanf("%d", &value);
            if (root == NULL)
                root = new BSTNode(value);
            else
                root->Insert(value);
        }

        pre_order(root, q);
        output(q);
        in_order(root, q);
        output(q);
        suf_order(root, q);
        output(q);
        putchar('\n');
        delete root;
    }

    return 0;
}