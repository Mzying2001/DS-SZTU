/*
问题 B: 平衡树上的第k小
时间限制: 1 Sec  内存限制: 256 MB
提交: 224  解决: 107
[提交][状态][讨论版]
题目描述
二种操作：

1 Key 表示插入一个新数据Key；
2 K 输出当前数据从小到大排列的第 K个数，并删除这个数，不存在则输出-1。
要求使用平衡树实现

输入
每组数据第一行n表示有n个操作

接下来n行操作内容

1 <= n <= 10^5

输出
按操作规则输出对应内容

样例输入
8
1 1
1 2
1 3
1 4
1 5
2 2
2 2
2 6
样例输出
2
3
-1
提示
*/

// #include <cstdio>
// #include <vector>

// struct BSTNode
// {
//     int value;
//     BSTNode *left, *right;
//     BSTNode() { left = right = NULL; }
//     BSTNode(int value) : BSTNode() { this->value = value; }

//     ~BSTNode()
//     {
//         if (left != NULL)
//             delete left;
//         if (right != NULL)
//             delete right;
//     }

//     void Insert(BSTNode *node)
//     {
//         if (node->value < value)
//         {
//             if (left != NULL)
//                 left->Insert(node);
//             else
//                 left = node;
//         }
//         else
//         {
//             if (right != NULL)
//                 right->Insert(node);
//             else
//                 right = node;
//         }
//     }

//     void Insert(int value)
//     {
//         Insert(new BSTNode(value));
//     }

//     BSTNode *Find(int value)
//     {
//         if (value == this->value)
//             return this;
//         if (value < this->value)
//         {
//             if (left == NULL)
//                 return NULL;
//             else
//                 return left->Find(value);
//         }
//         else
//         {
//             if (right == NULL)
//                 return NULL;
//             else
//                 return right->Find(value);
//         }
//     }

//     BSTNode *FindParent(int value, BSTNode *parent = NULL)
//     {
//         if (value == this->value)
//             return parent;
//         if (value < this->value)
//         {
//             if (left == NULL)
//                 return NULL;
//             else
//                 return left->FindParent(value, this);
//         }
//         else
//         {
//             if (right == NULL)
//                 return NULL;
//             else
//                 return right->FindParent(value, this);
//         }
//     }
// };

// struct BST
// {
//     BSTNode *root;
//     BST() { root = NULL; }

//     ~BST()
//     {
//         if (root != NULL)
//             delete root;
//     }

//     void Insert(int value)
//     {
//         if (root == NULL)
//             root = new BSTNode(value);
//         else
//             root->Insert(value);
//     }

//     int RemoveRightMin(BSTNode *node)
//     {
//         BSTNode *target = node;
//         while (target->left != NULL)
//             target = target->left;
//         int value = target->value;
//         this->Remove(target->value);
//         return value;
//     }

//     bool Remove(int value)
//     {
//         if (root == NULL)
//             return false;

//         BSTNode *target = root->Find(value);
//         if (target == NULL)
//             return false;

//         BSTNode *parent = root->FindParent(value);
//         if (target->left == NULL && target->right == NULL)
//         {
//             if (parent->left == target)
//                 parent->left = NULL;
//             else
//                 parent->right = NULL;
//             delete target;
//         }
//         else if (target->left != NULL && target->right != NULL)
//         {
//             target->value = this->RemoveRightMin(target->right);
//         }
//         else
//         {
//             if (target->left != NULL)
//             {
//                 if (parent == NULL)
//                 {
//                     root = target->left;
//                     return true;
//                 }
//                 if (parent->left->value == value)
//                     parent->left = target->left;
//                 else
//                     parent->right = target->left;
//             }
//             else
//             {
//                 if (parent == NULL)
//                 {
//                     root = target->right;
//                     return true;
//                 }
//                 if (parent->left != NULL && parent->left->value == value)
//                 {
//                     parent->left = target->right;
//                 }
//                 else
//                 {
//                     parent->right = target->right;
//                 }
//             }
//         }
//         return true;
//     }
// };

// void in_order(BSTNode *node, std::vector<int> &v)
// {
//     if (node != NULL)
//     {
//         in_order(node->left, v);
//         v.push_back(node->value);
//         in_order(node->right, v);
//     }
// }

// int main()
// {
//     BST tree;
//     std::vector<int> v;

//     freopen("./in.txt", "r", stdin);

//     int n, cmd, k;
//     scanf("%d", &n);
//     while (n--)
//     {
//         scanf("%d%d", &cmd, &k);
//         if (cmd == 1)
//         {
//             tree.Insert(k);
//         }
//         else
//         {
//             if (k > v.size())
//             {
//                 puts("-1");
//                 continue;
//             }
//             printf("%d\n", v[k - 1]);
//             tree.Remove(k);
//         }
//         v.clear();
//         in_order(tree.root, v);
//     }

//     return 0;
// }

#include <iostream>

using namespace std;
const int maxn = (int)1e5 + 10;

struct Node
{
    int key = -1;
    int data = -1;
    int left = -1;
    int right = -1;
    int height = -1;
    int left_count = -1, right_count = -1;
    void Init() {}
    void Init(int _k, int _d = 0)
    {
        Init();
        key = _k;
        data = _d;
    }
    Node() { Init(); }
    Node(int k_, int d_ = 0) { Init(k_, d_); }
};

Node tr[maxn];
int root, tp;

inline int UpdateHeight(int now)
{
    int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
    int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
    tr[now].left_count = tr[now].left == -1 ? 0 : tr[tr[now].left].left_count + tr[tr[now].left].right_count + 1;
    tr[now].right_count = tr[now].right == -1 ? 0 : tr[tr[now].right].left_count + tr[tr[now].right].right_count + 1;
    return tr[now].height = (lh > rh ? lh : rh) + 1;
}

inline int HeightDiff(int now)
{
    int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
    int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
    return lh - rh;
}

int LL(int an)
{
    int bn = tr[an].left;
    int dn = tr[bn].right;
    tr[bn].right = an;
    tr[an].left = dn;
    UpdateHeight(an);
    UpdateHeight(bn);
    return bn;
}

int RR(int an)
{
    int bn = tr[an].right;
    int dn = tr[bn].left;
    tr[bn].left = an;
    tr[an].right = dn;
    UpdateHeight(an);
    UpdateHeight(bn);
    return bn;
}

int LR(int an)
{
    tr[an].left = RR(tr[an].left);
    return LL(an);
}

int RL(int an)
{
    tr[an].right = LL(tr[an].right);
    return RR(an);
}

void Insert(int &now, int key, int data = 0)
{
    if (now == -1)
    {
        now = ++tp;
        tr[now].Init(key, data);
    }
    else if (key < tr[now].key)
    {
        Insert(tr[now].left, key, data);
        if (HeightDiff(now) == 2)
            now = (key < tr[tr[now].left].key ? LL(now) : LR(now));
    }
    else if (key > tr[now].key)
    {
        Insert(tr[now].right, key, data);
        if (HeightDiff(now) == -2)
            now = (key > tr[tr[now].right].key ? RR(now) : RL(now));
    }
    UpdateHeight(now);
}

void Delete(int &now, int key)
{
    if (now == -1)
        return;
    else if (key < tr[now].key)
        Delete(tr[now].left, key);
    else if (key > tr[now].key)
        Delete(tr[now].right, key);
    else
    {
        if (tr[now].left == -1)
            now = tr[now].right;
        else if (tr[now].right == -1)
            now = tr[now].left;
        else
        {
            int nd;
            for (nd = tr[now].left;; nd = tr[nd].right)
                if (tr[nd].right == -1)
                    break;
            tr[now].key = tr[nd].key;
            tr[now].data = tr[nd].data;
            Delete(tr[now].left, tr[nd].key);
        }
    }
    if (now == -1)
        return;
    UpdateHeight(now);
    if (HeightDiff(now) == 2)
        now = (HeightDiff(tr[now].left) >= 0 ? LL(now) : LR(now));
    else if (HeightDiff(now) == -2)
        now = (HeightDiff(tr[now].right) <= 0 ? RR(now) : RL(now));
}

int search(int now, int k)
{
    if (now == -1)
        return -1;
    if (tr[now].left_count + 1 > k)
        return search(tr[now].left, k);
    else if (tr[now].left_count + 1 < k)
        return search(tr[now].right, k - (tr[now].left_count + 1));
    else
    {
        int res = tr[now].key;
        Delete(root, tr[now].key);
        return res;
    }
}

int main()
{
    int n, op, key;
    while (scanf("%d", &n) != EOF)
    {
        for (root = tp = -1; n--;)
        {
            cin >> op;
            if (op == 1)
            {
                cin >> key;
                Insert(root, key);
            }
            else if (op == 2)
            {
                cin >> key;
                cout << search(root, key) << endl;
            }
        }
        return 0;
    }
}