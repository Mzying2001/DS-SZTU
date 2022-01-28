/*
问题 E: DS栈—波兰式，逆波兰式
时间限制: 1 Sec  内存限制: 128 MB
提交: 309  解决: 149
[提交][状态][讨论版]
题目描述
       表达式有三种表示方法，分别为：

    前缀表示(波兰式)：运算符+操作数1+操作数2

    中缀表示：操作数1+运算符+操作数2

    后缀表示(逆波兰式)：操作数1+操作数2+运算符

    例如：a +b * (c -d ) - e/f

    波兰式：-+a*b-cd/ef     （运算符在操作数的前面，用递归计算波兰式）

    中缀式：a+b*c-d-e/f  

    逆波兰式：abcd-*+ef/-   （运算符在操作数的后面，用栈计算逆波兰式）

       中缀表示就是原表达式去掉扣号。       

     根据表达式求波兰式、逆波兰式都是教材第三章表达式求值的思想。     

      求波兰式，需要操作数栈(注意不是计算结果入栈，有计算式入栈)，运算符栈。区别在于从后往前扫描表达式，‘(’ 换成')','('换成‘)’。栈顶运算符优先级>新读入运算符优先级出栈，教材第三章表3.1中的相同运算符优先级>（从左往右计算）改为<，例如栈顶为‘+‘，新读入的为‘+’，则栈顶优先级<新读入的优先级。

     求逆波兰式，只需要运算符栈。操作数直接输出，操作符按表3.1优先级顺序出栈，输出。

       输入表达式，求其波兰式和逆波兰式。

输入
 测试次数

每组测试数据一行，一个合法表达式

输出
 对每组测试数据，输出两行

第一行，表达式的波兰表示

第二行，表达式的逆波兰表示

不同组测试数据间以空行分隔。

样例输入
2
4+2*3-10/5
12+3*5+(2+10)*5 
样例输出
- + 4 * 2 3 / 10 5
4 2 3 * + 10 5 / -

+ + 12 * 3 5 * + 2 10 5
12 3 5 * + 2 10 + 5 * +
提示
*/

#include <iostream>
#include <stack>

using namespace std;

struct Input
{
    int number;
    char op;
};

int getnumber(char c)
{
    return c - '0';
}

bool JudgeNumber(char c)
{
    if ((c >= '0') && (c <= '9'))
        return true;
    else
        return false;
}

bool JudgeOP(char c)
{
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '(') || (c == ')'))
        return true;
    else
        return false;
}

bool CompareLevel(char c1, char c2, int k)
{
    if (c1 == '+')
    {
        if (c2 == '+')
        {
            if (k == 1)
                return false;
            else
                return true;
        }
        else if (c2 == '-')
        {
            if (k == 1)
                return false;
            else
                return true;
        }
        else if (c2 == '*')
        {
            return false;
        }
        else if (c2 == '/')
        {
            return false;
        }
    }
    else if (c1 == '-')
    {
        if (c2 == '+')
        {
            if (k == 1)
                return false;
            else
                return true;
        }
        else if (c2 == '-')
        {
            if (k == 1)
                return false;
            else
                return true;
        }
        else if (c2 == '*')
        {
            return false;
        }
        else if (c2 == '/')
        {
            return false;
        }
    }
    else if (c1 == '*')
    {
        if (c2 == '+')
        {
            return true;
        }
        else if (c2 == '-')
        {
            return true;
        }
        else if (c2 == '*')
        {
            if (k == 1)
                return false;
            else
                return true;
        }
        else if (c2 == '/')
        {
            if (k == 1)
                return false;
            else
                return true;
        }
    }
    else if (c1 == '/')
    {
        if (c2 == '+')
        {
            return true;
        }
        else if (c2 == '-')
        {
            return true;
        }
        else if (c2 == '*')
        {
            if (k == 1)
                return false;
            else
                return true;
        }
        else if (c2 == '/')
        {
            if (k == 1)
                return false;
            else
                return true;
        }
    }
}

void PNchange(Input *input, int len)
{
    stack<Input> output;
    stack<Input> OPTR;

    for (int i = 0; i < len; i++)
    {
        if ((input[i].number != -999) && (input[i].op == 'N'))
        {
            output.push(input[i]);
        }
        if ((input[i].number == -999) && (input[i].op == ')'))
        {
            OPTR.push(input[i]);
        }
        if ((input[i].number == -999) && (input[i].op != 'N') && (input[i].op != '(') && (input[i].op != ')'))
        {
            if (OPTR.empty() == true)
            {
                OPTR.push(input[i]);
            }
            else
            {
                if ((OPTR.top().op == ')') || (CompareLevel(OPTR.top().op, input[i].op, 1) == false))
                {
                    OPTR.push(input[i]);
                }
                else
                {
                    output.push(OPTR.top());
                    OPTR.pop();
                    i--;
                    continue;
                }
            }
        }
        if ((input[i].number == -999) && (input[i].op == '('))
        {
            while (OPTR.top().op != ')')
            {
                output.push(OPTR.top());
                OPTR.pop();
                if (OPTR.empty() == true)
                    break;
            }
            if (OPTR.empty() != true)
            {
                if (OPTR.top().op == ')')
                    OPTR.pop();
            }
        }
    }
    if (OPTR.empty() != true)
    {
        while (OPTR.empty() != true)
        {
            output.push(OPTR.top());
            OPTR.pop();
        }
    }

    int k = 0;
    while (output.empty() != true)
    {
        if (k == 0)
        {
            if ((output.top().number != -999) && (output.top().op == 'N'))
                cout << output.top().number;
            else if ((output.top().number == -999) && (output.top().op != 'N'))
                cout << output.top().op;
            output.pop();
            k++;
        }
        else
        {
            if ((output.top().number != -999) && (output.top().op == 'N'))
                cout << " " << output.top().number;
            else if ((output.top().number == -999) && (output.top().op != 'N'))
                cout << " " << output.top().op;
            output.pop();
        }
    }
    cout << endl;
}

void RPNchange(Input *input, int len)
{
    stack<Input> output;
    stack<Input> OPTR;

    for (int i = len - 1; i >= 0; i--)
    {
        if ((input[i].number != -999) && (input[i].op == 'N'))
        {
            output.push(input[i]);
        }
        if ((input[i].number == -999) && (input[i].op == '('))
        {
            OPTR.push(input[i]);
        }
        if ((input[i].number == -999) && (input[i].op != 'N') && (input[i].op != '(') && (input[i].op != ')'))
        {
            if (OPTR.empty() == true)
            {
                OPTR.push(input[i]);
            }
            else
            {
                if ((OPTR.top().op == '(') || (CompareLevel(OPTR.top().op, input[i].op, 2) == false))
                {
                    OPTR.push(input[i]);
                }
                else
                {
                    output.push(OPTR.top());
                    OPTR.pop();
                    i++;
                    continue;
                }
            }
        }
        if ((input[i].number == -999) && (input[i].op == ')'))
        {
            while (OPTR.top().op != '(')
            {
                output.push(OPTR.top());
                OPTR.pop();
                if (OPTR.empty() == true)
                    break;
            }
            if (OPTR.empty() != true)
                OPTR.pop();
        }
    }
    if (OPTR.empty() != true)
    {
        while (OPTR.empty() != true)
        {
            output.push(OPTR.top());
            OPTR.pop();
        }
    }

    stack<Input> output1;
    while (output.empty() != true)
    {
        output1.push(output.top());
        output.pop();
    }
    int k = 0;
    while (output1.empty() != true)
    {
        if (k == 0)
        {
            if ((output1.top().number != -999) && (output1.top().op == 'N'))
                cout << output1.top().number;
            else if ((output1.top().number == -999) && (output1.top().op != 'N'))
                cout << output1.top().op;
            output1.pop();
            k++;
        }
        else
        {
            if ((output1.top().number != -999) && (output1.top().op == 'N'))
                cout << " " << output1.top().number;
            else if ((output1.top().number == -999) && (output1.top().op != 'N'))
                cout << " " << output1.top().op;
            output1.pop();
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Input *input = new Input[100];
        string ip;
        cin >> ip;
        int n = 0;
        int k = 1;
        int j = 0;

        for (int i = ip.length() - 1; i >= 0; i--)
        {
            n = 0;
            k = 1;
            while (JudgeNumber(ip[i]))
            {
                int sum = getnumber(ip[i]);
                for (int h = 1; h < k; h++)
                    sum = sum * 10;
                n += sum;
                k++;
                if (i > 0)
                    i--;
                else
                    break;
            }
            if (k != 1)
            {
                input[j].number = n;
                input[j].op = 'N';
                j++;
            }
            if (JudgeOP(ip[i]))
            {
                input[j].op = ip[i];
                input[j].number = -999;
                j++;
            }
        }
        PNchange(input, j);
        RPNchange(input, j);
        cout << endl;
        delete[] input;
    }
}