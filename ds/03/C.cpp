/*
问题 C: DS线性表—多项式相加
时间限制: 1 Sec  内存限制: 128 MB
提交: 314  解决: 163
[提交][状态][讨论版]
题目描述
对于一元多项式  p(x)=p0+p1x+p2x2+ … +pnxn  ，每个项都有系数和指数两部分，例如p2x2的系数为p2,指数为2。

编程实现两个多项式的相加。

例如5+x+2x2+3x3，-5-x+6x2+4x4，两者相加结果：8x2+3x3+4x4

其中系数5和-5都是x的0次方的系数，相加后为0，所以不显示。x的1次方同理不显示。

可用顺序表或单链表实现。

输入
第1行：输入t表示有t组测试数据

第2行：输入n表示有第1组的第1个多项式包含n个项

第3行：输入第一项的系数和指数，以此类推输入n行

接着输入m表示第1组的第2个多项式包含m项

同理输入第2个多项式的m个项的系数和指数

参考上面输入第2组数据，以此类推输入t组

假设所有数据都是整数

输出
对于每1组数据，先用两行输出两个原来的多项式，再用一行输出运算结果，不必考虑结果全为0的情况


输出格式参考样本数据，格式要求包括：

1.如果指数或系数是负数，用小括号括起来。

2.如果系数为0，则该项不用输出。

3.如果指数不为0，则用符号^表示，例如x的3次方，表示为x^3。

4.多项式的每个项之间用符号+连接，每个+两边加1个空格隔开。

样例输入
2
4
5 0
1 1
2 2
3 3
4
-5 0
-1 1
6 2
4 4
3
-3 0
-5 1
2 2
4
9 -1
2 0
3 1
-2 2
样例输出
5 + 1x^1 + 2x^2 + 3x^3
(-5) + (-1)x^1 + 6x^2 + 4x^4
8x^2 + 3x^3 + 4x^4
(-3) + (-5)x^1 + 2x^2
9x^(-1) + 2 + 3x^1 + (-2)x^2
9x^(-1) + (-1) + (-2)x^1

提示
*/

#include <iostream>

struct ExpressionNode
{
    int coe, idx;
    ExpressionNode *next;
    ExpressionNode() : ExpressionNode(0, 0){};
    ExpressionNode(int coe, int idx)
    {
        this->coe = coe;
        this->idx = idx;
        this->next = NULL;
    }
};

class Expression
{
private:
    ExpressionNode *head;

public:
    Expression()
    {
        head = new ExpressionNode();
    }

    ~Expression()
    {
        while (head->next != NULL)
        {
            ExpressionNode *node = head->next;
            head->next = node->next;
            delete node;
        }
        delete head;
    }

    ExpressionNode *first()
    {
        return head->next;
    }

    void insert(int coe, int idx)
    {
        ExpressionNode *p = head;
        while (p->next != NULL && p->next->idx < idx)
            p = p->next;
        if (p->next == NULL)
            p->next = new ExpressionNode(coe, idx);
        else
        {
            ExpressionNode *node = new ExpressionNode(coe, idx);
            node->next = p->next;
            p->next = node;
        }
    }

    ExpressionNode *get(int idx)
    {
        ExpressionNode *p = first();
        while (p != NULL && p->idx != idx)
            p = p->next;
        return p;
    }

    Expression &operator+=(Expression &other)
    {
        ExpressionNode *p = other.first();
        while (p != NULL)
        {
            int c = p->coe;
            int i = p->idx;
            p = p->next;

            ExpressionNode *node = get(i);
            if (node == NULL)
                insert(c, i);
            else
                node->coe += c;
        }
        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, Expression &exp)
{
    ExpressionNode *p = exp.first();
    bool first = true;
    while (p != NULL)
    {
        int coe = p->coe;
        int idx = p->idx;
        p = p->next;
        if (coe == 0)
            continue;
        if (first)
            first = false;
        else
            os << " + ";
        if (coe < 0)
            os << '(';
        os << coe;
        if (coe < 0)
            os << ')';
        if (idx == 0)
            continue;
        os << "x^";
        if (idx < 0)
            os << '(';
        os << idx;
        if (idx < 0)
            os << ')';
    }
    return os;
}

int main()
{
    int t, n;
    std::cin >> t;

    while (t--)
    {
        Expression exp;
        std::cin >> n;
        while (n--)
        {
            int coe, idx;
            std::cin >> coe >> idx;
            exp.insert(coe, idx);
        }
        std::cout << exp << std::endl;

        Expression exp2;
        std::cin >> n;
        while (n--)
        {
            int coe, idx;
            std::cin >> coe >> idx;
            exp2.insert(coe, idx);
        }
        std::cout << exp2 << std::endl;

        exp += exp2;
        std::cout << exp << std::endl;
    }

    return 0;
}
