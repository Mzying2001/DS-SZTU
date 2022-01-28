/*
问题 D: DS二叉树—二叉树镜面反转
时间限制: 1 Sec  内存限制: 128 MB
提交: 363  解决: 200
[提交][状态][讨论版]
题目描述
假设二叉树用二叉链表存储，用先序序列结果创建。输入二叉树的先序序列，请你先创建二叉树，并对树做个镜面反转，再输出反转后的二叉树的先序遍历、中序遍历、后序遍历和层序遍历的序列。所谓镜面反转，是指将所有非叶结点的左右孩子对换。

--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
输入
测试次数t

每组测试数据是一个二叉树的先序遍历序列，#表示空树

输出
对每棵二叉树，输出镜面反转后的先序、中序、后序和层次遍历序列。如果空树，输出四个NULL（后面不加空格）。如下：

NULL

NULL

NULL

NULL

样例输入
3
41#32###65##7##
AB#C##D##
AB##C##
样例输出
4 6 7 5 1 3 2 
7 6 5 4 3 2 1 
7 5 6 2 3 1 4 
4 6 1 7 5 3 2 
A D B C 
D A C B 
D C B A 
A D B C 
A C B 
C A B 
C B A 
A C B 
提示
*/

// #include <iostream>

// char buf[1024], tree[1024];
// int len, tree_max_index;

// void build_tree(int &i, int j)
// {
//     if (i < len)
//     {
//         tree[j] = buf[i];
//         if (j > tree_max_index)
//             tree_max_index = j;
//         if (buf[i++] != '#')
//         {
//             build_tree(i, j * 2 + 1);
//             build_tree(i, j * 2 + 2);
//         }
//     }
// }

// int str_len(char *s)
// {
//     int ans = 0;
//     while (*s++)
//         ++ans;
//     return ans;
// }

// void rpreorder(int i = 0)
// {
//     if (tree[i] != '#')
//     {
//         printf("%c ", tree[i]);
//         rpreorder(i * 2 + 2);
//         rpreorder(i * 2 + 1);
//     }
// }

// void rinorder(int i = 0)
// {
//     if (tree[i] != '#')
//     {
//         rinorder(i * 2 + 2);
//         printf("%c ", tree[i]);
//         rinorder(i * 2 + 1);
//     }
// }

// void rsuforder(int i = 0)
// {
//     if (tree[i] != '#')
//     {
//         rsuforder(i * 2 + 2);
//         rsuforder(i * 2 + 1);
//         printf("%c ", tree[i]);
//     }
// }

// void rarrorder(int i = 0)
// {
//     for (int i = 0;; i = i * 2 + 1)
//     {
//         if (i > tree_max_index)
//             break;
//         for (int j = i * 2; j >= i; --j)
//         {
//             if (j <= tree_max_index && tree[j] != '#')
//                 printf("%c ", tree[j]);
//         }
//     }
// }

// int main()
// {
//     int t;
//     scanf("%d", &t);

//     while (t--)
//     {
//         scanf("%s", buf);
//         len = str_len(buf);

//         if (len == 0 || buf[0] == '#')
//         {
//             printf("NULL\nNULL\nNULL\nNULL\n");
//             continue;
//         }

//         int tmp = 0;
//         tree_max_index = 0;
//         build_tree(tmp, 0);

//         rpreorder();
//         putchar('\n');
//         rinorder();
//         putchar('\n');
//         rsuforder();
//         putchar('\n');
//         rarrorder();
//         putchar('\n');
//     }

//     return 0;
// }

#include <iostream>

using namespace std;

class BiTreeNode
{
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode *Parent;
    BiTreeNode() : LeftChild(NULL), RightChild(NULL), data(' '), Parent(NULL) {}
    //~BiTreeNode();
};

class BiTree
{
private:
    BiTreeNode *Root;
    int pos;
    string strTree;
    BiTreeNode *CreateBiTree();
    void PreOrder(BiTreeNode *t);
    void InOrder(BiTreeNode *t);
    void PostOrder(BiTreeNode *t);
    void LevelOrder(BiTreeNode *t, int i);
    void MirrorTree(BiTreeNode *t);
    int LeafDepth(BiTreeNode *t);

public:
    BiTree();
    //~BiTree();
    void CreateTree(string TreeArray);
    void PreOrder();
    void InOrder();
    void PostOrder();
    void LevelOrder();
    void MirrorTree();
    bool CheckTree();
};
BiTree::BiTree()
{
    pos = 0;
    strTree = "";
}

void BiTree::PreOrder()
{
    PreOrder(Root);
}

void BiTree::PreOrder(BiTreeNode *t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
    else
        return;
}

void BiTree::InOrder()
{
    InOrder(Root);
}

void BiTree::InOrder(BiTreeNode *t)
{
    if (t != NULL)
    {
        InOrder(t->LeftChild);
        cout << t->data << " ";
        InOrder(t->RightChild);
    }
    else
        return;
}

void BiTree::PostOrder()
{
    PostOrder(Root);
}

void BiTree::PostOrder(BiTreeNode *t)
{
    if (t != NULL)
    {
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        cout << t->data << " ";
    }
    else
        return;
}

void BiTree::CreateTree(string TreeArray)
{
    pos = 0;
    strTree.assign(TreeArray);
    Root = CreateBiTree();
}

BiTreeNode *BiTree::CreateBiTree()
{
    BiTreeNode *T;
    char c;
    c = strTree[pos++];
    if (c == '#')
        T = NULL;
    else
    {
        T = new BiTreeNode();
        T->data = c;
        T->LeftChild = CreateBiTree();
        if (T->LeftChild != NULL)
            T->LeftChild->Parent = T;
        T->RightChild = CreateBiTree();
        if (T->RightChild != NULL)
            T->RightChild->Parent = T;
    }
    return T;
}

void BiTree::LevelOrder()
{
    for (int i = 0; i < 10; i++)
    {
        LevelOrder(Root, i);
    }
}

void BiTree::LevelOrder(BiTreeNode *t, int i)
{
    if (t != NULL)
    {
        if (LeafDepth(t) == i)
        {
            cout << t->data << " ";
        }
        LevelOrder(t->LeftChild, i);
        LevelOrder(t->RightChild, i);
    }
    else
        return;
}

void BiTree::MirrorTree()
{
    MirrorTree(Root);
}

void BiTree::MirrorTree(BiTreeNode *t)
{
    if (t != NULL)
    {
        BiTreeNode *p = t->LeftChild;
        t->LeftChild = t->RightChild;
        t->RightChild = p;
        MirrorTree(t->LeftChild);
        MirrorTree(t->RightChild);
    }
    else
        return;
}

bool BiTree::CheckTree()
{
    if (Root == NULL)
        return true;
    else
        return false;
}

int BiTree::LeafDepth(BiTreeNode *t)
{
    int depth = 0;
    BiTreeNode *T = t;
    while (1)
    {
        if (T->Parent != NULL)
        {
            T = T->Parent;
            depth++;
        }
        else
        {
            return depth;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    string str;
    while (t--)
    {
        cin >> str;
        BiTree bt;
        bt.CreateTree(str);
        if (bt.CheckTree())
        {
            cout << "NULL" << endl;
            cout << "NULL" << endl;
            cout << "NULL" << endl;
            cout << "NULL" << endl;
        }
        else
        {
            bt.MirrorTree();
            bt.PreOrder();
            cout << endl;
            bt.InOrder();
            cout << endl;
            bt.PostOrder();
            cout << endl;
            bt.LevelOrder();
            cout << endl;
        }
    }
}