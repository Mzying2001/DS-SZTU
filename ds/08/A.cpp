/*
问题 A: DS二叉树--后序遍历非递归算法
时间限制: 1 Sec  内存限制: 128 MB
提交: 271  解决: 236
[提交][状态][讨论版]
题目描述
求一颗树的后序遍历的非递归算法
要求：必须是非递归算法，使用堆栈对象来实现
建树方法采用“先序遍历+空树用0表示”的方法
算法流程：

输入
第一行输入一个整数t，表示有t个测试数据

第二行起输入二叉树先序遍历的结果，空树用字符‘0’表示，输入t行

输出
逐行输出每个二叉树的后序遍历结果

样例输入
3
AB0C00D00
ABC00D00EF000
ABCD0000E0F00
样例输出
CBDA
CDBFEA
DCBFEA
提示
*/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class BiTreeNode
{
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode() : LeftChild(NULL), RightChild(NULL), data(' ') {}
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
    void LevelOrder(BiTreeNode *t);
    void PostOrder_stack(BiTreeNode *t);

public:
    BiTree();
    //~BiTree();
    void CreateTree(string TreeArray);
    void PreOrder();
    void InOrder();
    void PostOrder();
    void LevelOrder();
    void PostOrder_stack();
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
        cout << t->data;
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
        cout << t->data;
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
        cout << t->data;
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
    if (c == '0')
        T = NULL;
    else
    {
        T = new BiTreeNode();
        T->data = c;
        T->LeftChild = CreateBiTree();
        T->RightChild = CreateBiTree();
    }
    return T;
}

void BiTree::LevelOrder()
{
    LevelOrder(Root);
}

void BiTree::LevelOrder(BiTreeNode *t)
{
    queue<BiTreeNode *> tq;
    BiTreeNode *p = t;
    if (p != NULL)
    {
        tq.push(p);
    }
    while (!tq.empty())
    {
        p = tq.front();
        tq.pop();
        if (p != NULL)
        {
            cout << p->data;
            tq.push(p->LeftChild);
            tq.push(p->RightChild);
        }
    }
}

void BiTree::PostOrder_stack()
{
    PostOrder_stack(Root);
}

void BiTree::PostOrder_stack(BiTreeNode *t)
{
    stack<BiTreeNode *> s1;
    stack<int> s2;
    int tag;
    BiTreeNode *p = t;
    do
    {
        while (1)
        {
            if (p != NULL)
            {
                s1.push(p);
                tag = 0;
                s2.push(tag);
                p = p->LeftChild;
            }
            else
                break;
        }

        if (s1.empty())
            break;
        if (p == NULL)
        {
            tag = s2.top();
            if (tag == 0)
            {
                s2.top() = 1;
                p = s1.top()->RightChild;
            }
            else
            {
                p = s1.top();
                s1.pop();
                s2.pop();
                cout << p->data;
                p = NULL;
            }
        }
    } while (!s1.empty());
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
        bt.PostOrder_stack();
        cout << endl;
    }
}