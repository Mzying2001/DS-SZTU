/*
问题 D: DS二叉排序树之创建和插入
时间限制: 1 Sec  内存限制: 128 MB
提交: 207  解决: 145
[提交][状态][讨论版]
题目描述
给出一个数据序列，建立二叉排序树，并实现插入功能

对二叉排序树进行中序遍历，可以得到有序的数据序列

输入
第一行输入t，表示有t个数据序列

第二行输入n，表示首个序列包含n个数据

第三行输入n个数据，都是自然数且互不相同，数据之间用空格隔开

第四行输入m，表示要插入m个数据

从第五行起，输入m行，每行一个要插入的数据，都是自然数且和前面的数据不等

以此类推输入下一个示例

输出
第一行输出有序的数据序列，对二叉排序树进行中序遍历可以得到

从第二行起，输出插入第m个数据后的有序序列，输出m行

以此类推输出下一个示例的结果

 

样例输入
1
6
22 33 55 66 11 44
3
77
50
10
样例输出
11 22 33 44 55 66 
11 22 33 44 55 66 77 
11 22 33 44 50 55 66 77 
10 11 22 33 44 50 55 66 77 
提示
*/

#include <cstdio>

inline int max(int a, int b)
{
    return a > b ? a : b;
}

class AvlNode
{
public:
    int value;
    AvlNode *left, *right;

    AvlNode()
    {
        left = right = NULL;
    }

    AvlNode(int value) : AvlNode()
    {
        this->value = value;
    }

    ~AvlNode()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
    }

    int Deepth()
    {
        return max(left == NULL ? 0 : left->Deepth(), right == NULL ? 0 : right->Deepth()) + 1;
    }

    int LeftDeepth()
    {
        return left == NULL ? 0 : left->Deepth();
    }

    int RightDeepth()
    {
        return right == NULL ? 0 : right->Deepth();
    }

    void LeftRotate()
    {
        AvlNode *newNode = new AvlNode(value);
        AvlNode *tmp = right;

        newNode->left = left;
        newNode->right = right->left;
        value = right->value;
        right = right->right;
        left = newNode;

        tmp->left = tmp->right = NULL;
        delete tmp;
    }

    void RightRotate()
    {
        AvlNode *newNode = new AvlNode(value);
        AvlNode *tmp = left;

        newNode->right = right;
        newNode->left = left->right;
        value = left->value;
        left = left->left;
        right = newNode;

        tmp->left = tmp->right = NULL;
        delete tmp;
    }

    void Add(AvlNode *node)
    {
        if (node == NULL)
            return;

        if (node->value < value)
        {
            if (left == NULL)
                left = node;
            else
                left->Add(node);
        }
        else
        {
            if (right == NULL)
                right = node;
            else
                right->Add(node);
        }

        if (RightDeepth() - LeftDeepth() > 1)
        {
            if (right != NULL && right->LeftDeepth() > right->RightDeepth())
            {
                right->RightRotate();
            }
            LeftRotate();
            return;
        }

        if (LeftDeepth() - RightDeepth() > 1)
        {
            if (left != NULL && left->RightDeepth() > left->RightDeepth())
            {
                left->LeftRotate();
            }
            RightRotate();
        }
    }

    void Add(int value)
    {
        Add(new AvlNode(value));
    }
};

void in_order(AvlNode *node)
{
    if (node != NULL)
    {
        in_order(node->left);
        printf("%d ", node->value);
        in_order(node->right);
    }
}

inline void print_node(AvlNode *node)
{
    in_order(node);
    putchar('\n');
}

int main()
{
    int t, n, m;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        AvlNode *avl = NULL;

        for (int i = 0; i < n; i++)
        {
            int value;
            scanf("%d", &value);
            if (avl == NULL)
                avl = new AvlNode(value);
            else
                avl->Add(value);
        }
        print_node(avl);

        scanf("%d", &m);
        while (m--)
        {
            int value;
            scanf("%d", &value);
            avl->Add(value);
            print_node(avl);
        }

        delete avl;
    }

    return 0;
}