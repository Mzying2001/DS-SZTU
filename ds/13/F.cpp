/*
问题 F: DS二叉排序树之删除
时间限制: 1 Sec  内存限制: 128 MB
提交: 384  解决: 165
[提交][状态][讨论版]
题目描述
给出一个数据序列，建立二叉排序树，并实现删除功能

对二叉排序树进行中序遍历，可以得到有序的数据序列

输入
第一行输入t，表示有t个数据序列

第二行输入n，表示首个序列包含n个数据

第三行输入n个数据，都是自然数且互不相同，数据之间用空格隔开

第四行输入m，表示要删除m个数据

从第五行起，输入m行，每行一个要删除的数据，都是自然数

以此类推输入下一个示例

输出
第一行输出有序的数据序列，对二叉排序树进行中序遍历可以得到

从第二行起，输出删除第m个数据后的有序序列，输出m行

以此类推输出下一个示例的结果

样例输入
1
6
22 33 55 66 11 44
3
66
22
77
样例输出
11 22 33 44 55 66 
11 22 33 44 55 
11 33 44 55 
11 33 44 55 
提示
当删除数据不在序列中，那么删除操作等于不执行，所以输出序列不变化


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

//     AvlNode *Find(int value)
//     {
//         if (value == this->value)
//             return this;

//         if (value < this->value)
//             return left == NULL ? NULL : left->Find(value);
//         else
//             return right == NULL ? NULL : right->Find(value);
//     }

//     AvlNode *FindParent(int value)
//     {
//         if ((left != NULL && left->value == value) || (right != NULL && right->value == value))
//         {
//             return this;
//         }
//         else
//         {
//             if (value < this->value && this->left != NULL)
//                 return left->FindParent(value);
//             else if (value >= this->value && right != NULL)
//                 return right->FindParent(value);
//             else
//                 return NULL;
//         }
//     }
// };

// void Remove(AvlNode **root_p, int value)
// {
//     AvlNode *root = (root_p == NULL ? NULL : *root_p);
//     if (root == NULL)
//         return;

//     AvlNode *targetNode = root->Find(value);
//     if (targetNode == NULL)
//         return;

//     if (root->left == NULL && root->right == NULL)
//     {
//         *root_p = NULL;
//         return;
//     }

//     AvlNode *parent = root->FindParent(value);
//     if (targetNode->left == NULL && targetNode->right == NULL)
//     {
//         if (parent->left != NULL && parent->left->value == value)
//         {
//             delete parent->left;
//             parent->left = NULL;
//         }
//         else if (parent->right != NULL && parent->right->value == value)
//         {
//             delete parent->right;
//             parent->right = NULL;
//         }
//     }
//     else if (targetNode->left != NULL && targetNode->right != NULL)
//     {

//     }
// }

// void in_order(AvlNode *node)
// {
//     if (node != NULL)
//     {
//         in_order(node->left);
//         printf("%d ", node->value);
//         in_order(node->right);
//     }
// }

// inline void print_node(AvlNode *node)
// {
//     in_order(node);
//     putchar('\n');
// }

// int main()
// {
//     int t, n, m;
//     scanf("%d", &t);

//     while (t--)
//     {
//         scanf("%d", &n);
//         AvlNode *avl = NULL;

//         for (int i = 0; i < n; i++)
//         {
//             int value;
//             scanf("%d", &value);
//             if (avl == NULL)
//                 avl = new AvlNode(value);
//             else
//                 avl->Add(value);
//         }
//         print_node(avl);

//         scanf("%d", &m);
//         while (m--)
//         {
//             int value;
//             scanf("%d", &value);
//             avl->Add(value);
//             print_node(avl);
//         }

//         delete avl;
//     }

//     return 0;
// }

#include <iostream>

using namespace std;

class BSTNode
{
public:
    int key;
    BSTNode *Parent;
    BSTNode *Lchild;
    BSTNode *Rchild;
    BSTNode() : key(0), Parent(NULL), Lchild(NULL), Rchild(NULL) {}
};

class BSTree
{
private:
    BSTNode *Root;
    void InOrder(BSTNode *t, int n);
    BSTNode *Search_BST(BSTNode *T, int key);
    BSTNode *Insert_BST(BSTNode *T, int key);

public:
    int search_times;
    BSTree();
    void InOrder();
    BSTNode *Search_BST(int key);
    void Insert_BST(int key);
    void Delete_BST(int key);
    void Create_BST(int *item, int n);
};

BSTree::BSTree()
{
    Root = NULL;
    search_times = 0;
}

void BSTree::InOrder()
{
    InOrder(Root, 1);
}
void BSTree::InOrder(BSTNode *t, int n)
{
    if (n == 1)
    {
        if (t != NULL)
        {
            InOrder(t->Lchild, 1);
            cout << t->key << " ";
            InOrder(t->Rchild, 1);
        }
        else
            return;
    }
    else if (n == 2)
    {
        if (t != NULL)
        {
            InOrder(t->Lchild, 2);
            if (t->Lchild != NULL)
                t->Lchild->Parent = t;
            if (t->Rchild != NULL)
                t->Rchild->Parent = t;
            InOrder(t->Rchild, 2);
        }
        else
            return;
    }
}

BSTNode *BSTree::Search_BST(int key)
{
    search_times = 0;
    return Search_BST(Root, key);
}
BSTNode *BSTree::Search_BST(BSTNode *T, int key)
{
    if (T == NULL)
        return NULL;
    else
    {
        if (T->key == key)
        {
            search_times++;
            return T;
        }
        else if (T->key > key)
        {
            search_times++;
            Search_BST(T->Lchild, key);
        }
        else
        {
            search_times++;
            Search_BST(T->Rchild, key);
        }
    }
}

void BSTree::Insert_BST(int key)
{
    Root = Insert_BST(Root, key);
}

BSTNode *BSTree::Insert_BST(BSTNode *T, int key)
{
    if (T == NULL)
    {
        T = new BSTNode;
        T->key = key;
        return T;
    }
    else
    {
        if (T->key == key)
            return NULL;
        else if (T->key > key)
            T->Lchild = Insert_BST(T->Lchild, key);
        else
            T->Rchild = Insert_BST(T->Rchild, key);
        return T;
    }
}

void BSTree::Delete_BST(int key)
{
    BSTNode *T = Search_BST(key);
    if (T == NULL)
    {
        return;
    }
    if ((T->Lchild == NULL) && (T->Rchild == NULL))
    {
        if (T->Parent->Lchild == T)
            T->Parent->Lchild = NULL;
        else if (T->Parent->Rchild == T)
            T->Parent->Rchild = NULL;
    }
    else if ((T->Lchild != NULL) && (T->Rchild != NULL))
    {
        BSTNode *t = T->Rchild;
        while (t->Lchild != NULL)
            t = t->Lchild;
        T->key = t->key;

        if (t->Rchild != NULL)
            *t = *t->Rchild;
        else
        {
            if (t->Parent->Lchild == t)
                t->Parent->Lchild = NULL;
            else if (t->Parent->Rchild == t)
                t->Parent->Rchild = NULL;
        }
    }
    else
    {
        if (T->Lchild != NULL)
        {
            *T = *T->Lchild;
        }
        else if (T->Rchild != NULL)
        {
            *T = *T->Rchild;
        }
    }
}

void BSTree::Create_BST(int *item, int n)
{
    for (int i = 0; i < n; i++)
    {
        Insert_BST(item[i]);
    }
    InOrder(Root, 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int *item = new int[n];
        for (int i = 0; i < n; i++)
            cin >> item[i];

        BSTree BST;
        BST.Create_BST(item, n);
        BST.InOrder();
        cout << endl;

        int m;
        cin >> m;

        int key;
        while (m--)
        {
            cin >> key;
            BST.Delete_BST(key);
            BST.InOrder();
            cout << endl;
        }
    }
    return 0;
}