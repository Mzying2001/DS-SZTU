/*
问题 E: DS二叉排序树之查找
时间限制: 1 Sec  内存限制: 128 MB
提交: 151  解决: 132
[提交][状态][讨论版]
题目描述
给出一个数据序列，建立二叉排序树，并实现查找功能

对二叉排序树进行中序遍历，可以得到有序的数据序列

输入
第一行输入t，表示有t个数据序列

第二行输入n，表示首个序列包含n个数据

第三行输入n个数据，都是自然数且互不相同，数据之间用空格隔开

第四行输入m，表示要查找m个数据

从第五行起，输入m行，每行一个要查找的数据，都是自然数

以此类推输入下一个示例

输出
第一行输出有序的数据序列，对二叉排序树进行中序遍历可以得到

从第二行起，输出查找结果，如果查找成功输出查找次数，如果查找失败输出-1

以此类推输出下一个示例的结果

样例输入
1
6
22 33 55 66 11 44
7
11
22
33
44
55
66
77
样例输出
11 22 33 44 55 66 
2
1
2
4
3
4
-1
提示

*/

#include <iostream>

using namespace std;

class BSTNode
{
public:
    int key;
    BSTNode *Lchild;
    BSTNode *Rchild;
    BSTNode() : key(0), Lchild(NULL), Rchild(NULL) {}
};

class BSTree
{
private:
    BSTNode *Root;
    void InOrder(BSTNode *t);
    BSTNode *Search_BST(BSTNode *T, int key);
    BSTNode *Insert_BST(BSTNode *T, int key);

public:
    int search_times;
    BSTree();
    void InOrder();
    BSTNode *Search_BST(int key);
    void Insert_BST(int key);
    void Create_BST(int *item, int n);
};

BSTree::BSTree()
{
    Root = NULL;
    search_times = 0;
}

void BSTree::InOrder()
{
    InOrder(Root);
}

void BSTree::InOrder(BSTNode *t)
{
    if (t != NULL)
    {
        InOrder(t->Lchild);
        cout << t->key << " ";
        InOrder(t->Rchild);
    }
    else
        return;
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

void BSTree::Create_BST(int *item, int n)
{
    for (int i = 0; i < n; i++)
    {
        Insert_BST(item[i]);
    }
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
            if (BST.Search_BST(key) != NULL)
                cout << BST.search_times << endl;
            else
                cout << -1 << endl;
        }
    }

    return 0;
}