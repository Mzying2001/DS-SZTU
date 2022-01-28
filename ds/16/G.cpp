/*
问题 G: DS二叉平衡树构建
时间限制: 1 Sec  内存限制: 128 MB
提交: 136  解决: 96
[提交][状态][讨论版]
题目描述







在初始为空的平衡二叉树中依次插入n个结点，请输出最终的平衡二叉树。

要求实现平衡二叉树，不可以使用各类库函数。
AVL代码参考模板：

#include <iostream>
using namespace std;

#define LH 1 // 左高 
#define EH 0 // 等高 
#define RH -1 // 右高 

class BiNode
{
    public:
        int key; // 关键值
        int bf; // 平衡因子 
        BiNode *lChild, *rChild;
        BiNode(int kValue, int bValue)
       {

           key = kValue;
           bf = bValue;
           lChild = NULL;
           rChild = NULL;
       }

       ~BiNode()
      {
           key = 0;
           bf = 0;
           lChild = NULL;
           rChild = NULL;
       }
};

// 二叉排序树
class BST
{
     private:
         BiNode *root; // 根结点指针 
         void rRotate(BiNode *&p);
         void lRotate(BiNode *&p);
         void leftBalance(BiNode *&t);
         void rightBalance(BiNode *&t);
         int insertAVL(BiNode *&t, int key, bool &taller); // 插入元素并做平衡处理
         void inOrder(BiNode *p);
     public:
         BST();
         void insertAVL(int key); // 二叉排序树插入元素 
         ~BST();
         void inOrder(); // 中序遍历 
};

// 以p为根的二叉排序树作右旋处理 
void BST::rRotate(BiNode *&p)
{
    // 参考课本236页算法9.9
}

// 以p为根的二叉排序树作左旋处理 
void BST::lRotate(BiNode *&p)
{
    // 参考课本236页算法9.10
}

// t为根的二叉排序树作左平衡旋转处理
void BST::leftBalance(BiNode *&t)
{
     // 参考课本238页算法9.12
}

// t为根的二叉排序树作右平衡旋转处理
void BST::rightBalance(BiNode *&t)
{
     // 参考课本238页算法9.12
}


int BST::insertAVL(BiNode *&t, int key, bool &taller)
{

     // 参考课本237页算法9.11
}

void BST::inOrder(BiNode *p)
{
    if(p)
    {
        inOrder(p->lChild);
        cout << p->key << ':' << p->bf << ' ';
        inOrder(p->rChild);
    }

    return;
}

// 二叉排序树初始化
BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    root = NULL;
}

// 插入元素并作平衡处理
void BST::insertAVL(int key)
{
    bool taller = false;
    insertAVL(root, key, taller);
}


// 中序遍历
void BST::inOrder()
{
    inOrder(root);
}

int main(void)
{
    int t;
    cin >> t;
    while(t --)
    {
        // 构建二叉平衡树，并在插入元素时做平衡处理 
        int n, elem;
        cin >> n;
        BST tree;
        while(n --)
        {
           cin >> elem;
           tree.insertAVL(elem);
        }
        tree.inOrder();
        cout << endl;
    }

    return 0;
} 


输入
第一行输入测试数据组数t；
每组测试数据，第一行输入结点数n, 第二行输入n个结点值。
输出
对每组测试数据，按中序遍历的顺序输出树中，结点值及平衡因子（测试数据没有空树），即结点值：平衡因子，不同结点之间间隔一个空格。

样例输入
8
3
64 5 1
3
64 5 13
6
64 78 5 1 13 15
6
64 78 5 1 13 10
3
64 78 100
3
64 80 70
6
64 30 80 90 70 68
6
64 30 80 90 70 75
样例输出
1:0 5:0 64:0
5:0 13:0 64:0
1:0 5:1 13:0 15:0 64:0 78:0
1:0 5:0 10:0 13:0 64:-1 78:0
64:0 78:0 100:0
64:0 70:0 80:0
30:0 64:0 68:0 70:0 80:-1 90:0
30:0 64:1 70:0 75:0 80:0 90:0
提示
*/

// #include <cstdio>

// inline int max(int a, int b)
// {
//     return a > b ? a : b;
// }

// class AvlNode
// {
// public:
//     int value;
//     AvlNode *left, *right;

//     AvlNode()
//     {
//         left = right = NULL;
//     }

//     AvlNode(int value) : AvlNode()
//     {
//         this->value = value;
//     }

//     ~AvlNode()
//     {
//         if (left != NULL)
//             delete left;
//         if (right != NULL)
//             delete right;
//     }

//     int Deepth()
//     {
//         return max(left == NULL ? 0 : left->Deepth(), right == NULL ? 0 : right->Deepth()) + 1;
//     }

//     int LeftDeepth()
//     {
//         return left == NULL ? 0 : left->Deepth();
//     }

//     int RightDeepth()
//     {
//         return right == NULL ? 0 : right->Deepth();
//     }

//     void LeftRotate()
//     {
//         AvlNode *newNode = new AvlNode(value);
//         AvlNode *tmp = right;

//         newNode->left = left;
//         newNode->right = right->left;
//         value = right->value;
//         right = right->right;
//         left = newNode;

//         tmp->left = tmp->right = NULL;
//         delete tmp;
//     }

//     void RightRotate()
//     {
//         AvlNode *newNode = new AvlNode(value);
//         AvlNode *tmp = left;

//         newNode->right = right;
//         newNode->left = left->right;
//         value = left->value;
//         left = left->left;
//         right = newNode;

//         tmp->left = tmp->right = NULL;
//         delete tmp;
//     }

//     void Add(AvlNode *node)
//     {
//         if (node == NULL)
//             return;

//         if (node->value < value)
//         {
//             if (left == NULL)
//                 left = node;
//             else
//                 left->Add(node);
//         }
//         else
//         {
//             if (right == NULL)
//                 right = node;
//             else
//                 right->Add(node);
//         }

//         if (RightDeepth() - LeftDeepth() > 1)
//         {
//             if (right != NULL && right->LeftDeepth() > right->RightDeepth())
//             {
//                 right->RightRotate();
//             }
//             LeftRotate();
//             return;
//         }

//         if (LeftDeepth() - RightDeepth() > 1)
//         {
//             if (left != NULL && left->RightDeepth() > left->RightDeepth())
//             {
//                 left->LeftRotate();
//             }
//             RightRotate();
//         }
//     }

//     void Add(int value)
//     {
//         Add(new AvlNode(value));
//     }
// };

// void in_order(AvlNode *node, bool &first)
// {
//     if (node != NULL)
//     {
//         in_order(node->left, first);
//         if (!first)
//             putchar(' ');
//         first = false;
//         printf("%d:%d", node->value, node->LeftDeepth() - node->RightDeepth());
//         in_order(node->right, first);
//     }
// }

// inline void print_node(AvlNode *node)
// {
//     bool first = true;
//     in_order(node, first);
//     putchar('\n');
// }

// int main()
// {
//     freopen("in.txt", "r", stdin);

//     int t, n;
//     scanf("%d", &t);
//     while (t--)
//     {
//         scanf("%d", &n);

//         AvlNode *avl = NULL;
//         while (n--)
//         {
//             int val;
//             scanf("%d", &val);
//             if (avl == NULL)
//                 avl = new AvlNode(val);
//             else
//                 avl->Add(val);
//         }

//         print_node(avl);
//         delete avl;
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

#define LH 1  // 左高
#define EH 0  // 等高
#define RH -1 // 右高

class BiNode
{
public:
    int key; // 关键值
    int bf;  // 平衡因子
    BiNode *lChild, *rChild;
    BiNode(){};
    BiNode(int kValue, int bValue)
    {

        key = kValue;
        bf = bValue;
        lChild = NULL;
        rChild = NULL;
    }

    ~BiNode()
    {
        key = 0;
        bf = 0;
        lChild = NULL;
        rChild = NULL;
    }
};

// 二叉排序树
class BST
{
private:
    BiNode *root; // 根结点指针
    void rRotate(BiNode *&p);
    void lRotate(BiNode *&p);
    void leftBalance(BiNode *&t);
    void rightBalance(BiNode *&t);
    int insertAVL(BiNode *&t, int key, bool &taller); // 插入元素并做平衡处理
    void inOrder(BiNode *p);

public:
    BST();
    void insertAVL(int key); // 二叉排序树插入元素
    ~BST();
    void inOrder(); // 中序遍历
};

// 以p为根的二叉排序树作右旋处理
void BST::rRotate(BiNode *&p)
{
    // 参考课本236页算法9.9
    auto lc = p->lChild;
    p->lChild = lc->rChild;
    lc->rChild = p;
    p = lc;
}

// 以p为根的二叉排序树作左旋处理
void BST::lRotate(BiNode *&p)
{
    // 参考课本236页算法9.10
    auto rc = p->rChild;
    p->rChild = rc->lChild;
    rc->lChild = p;
    p = rc;
}

// t为根的二叉排序树作左平衡旋转处理
void BST::leftBalance(BiNode *&t)
{
    BiNode *l, *lr;
    l = t->lChild;
    switch (l->bf)
    {
    case LH:
        t->bf = l->bf = EH;
        rRotate(t);
        break;
    case RH:
        lr = l->rChild;
        switch (lr->bf)
        {
        case LH:
            t->bf = RH;
            l->bf = EH;
            break;
        case EH:
            t->bf = l->bf = EH;
            break;
        case RH:
            t->bf = EH;
            l->bf = LH;
            break;
        }
        lr->bf = EH;
        lRotate(t->lChild);
        rRotate(t);
    }
}

// t为根的二叉排序树作右平衡旋转处理
void BST::rightBalance(BiNode *&t)
{
    // 参考课本238页算法9.12
    auto rc = t->rChild;
    switch (rc->bf)
    {
    case RH:
        t->bf = rc->bf = EH;
        lRotate(t);
        break;

    case LH:
        auto rl = rc->lChild;
        switch (rl->bf)
        {
        case RH:
            t->bf = LH;
            rc->bf = EH;
            break;

        case EH:
            t->bf = rc->bf = EH;
            break;

        case LH:
            t->bf = EH;
            rc->bf = RH;
            break;
        }
        rl->bf = EH;
        rRotate(t->rChild);
        lRotate(t);
    }
}

int BST::insertAVL(BiNode *&t, int key, bool &taller)
{
    if (!t)
    {
        t = new BiNode;
        t->key = key;
        t->lChild = t->rChild = NULL;
        t->bf = EH;
        taller = true;
    }
    else
    {
        if (key == t->key)
        {
            taller = false;
            return false;
        }
        if (key < t->key)
        {
            if (!insertAVL(t->lChild, key, taller))
                return false;
            if (taller)
            {
                switch (t->bf)
                {
                case LH:
                    leftBalance(t);
                    taller = false;
                    break;
                case EH:
                    t->bf = LH;
                    taller = true;
                    break;
                case RH:
                    t->bf = EH;
                    taller = false;
                    break;
                }
            }
        }
        else
        {
            if (!insertAVL(t->rChild, key, taller))
                return false;
            if (taller)
            {
                switch (t->bf)
                {
                case LH:
                    t->bf = EH;
                    taller = false;
                    break;
                case EH:
                    t->bf = RH;
                    taller = true;
                    break;
                case RH:
                    rightBalance(t);
                    taller = false;
                    break;
                }
            }
        }
    }
    return true;
}

void BST::inOrder(BiNode *p)
{
    if (p)
    {
        inOrder(p->lChild);
        cout << p->key << ':' << p->bf << ' ';
        inOrder(p->rChild);
    }

    return;
}

// 二叉排序树初始化
BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    root = NULL;
}

// 插入元素并作平衡处理
void BST::insertAVL(int key)
{
    bool taller = false;
    insertAVL(root, key, taller);
}

// 中序遍历
void BST::inOrder()
{
    inOrder(root);
}

int main(void)
{
    // freopen("in.txt", "r", stdin);

    int t;
    cin >> t;
    while (t--)
    {
        // 构建二叉平衡树，并在插入元素时做平衡处理
        int n, elem;
        cin >> n;
        BST tree;
        while (n--)
        {
            cin >> elem;
            tree.insertAVL(elem);
        }
        tree.inOrder();
        cout << endl;
    }

    return 0;
}
