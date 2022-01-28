/*
问题 C: DS堆栈--括号匹配
时间限制: 1 Sec  内存限制: 128 MB
提交: 834  解决: 231
[提交][状态][讨论版]
题目描述
处理表达式过程中需要对括号匹配进行检验，括号匹配包括三种：“(”和“)”，“[”和“]”，“{”和“}”。例如表达式中包含括号如下：

(	)	[	(	)	(	[	]	)	]	{	}
1	2	3	4	5	6	7	8	9	10	11	12
从上例可以看出第1和第2个括号匹配，第3和第10个括号匹配，4和5匹配，6和9匹配，7和8匹配，11和12匹配。从中可以看到括号嵌套的的情况是比较复杂的，使用堆栈可以很方便的处理这种括号匹配检验，可以遵循以下规则：

1、 当接收第1个左括号，表示新的一组匹配检查开始；随后如果连续接收到左括号，则不断进堆栈。

2、 当接受第1个右括号，则和最新进栈的左括号进行匹配，表示嵌套中1组括号已经匹配消除

3、 若到最后，括号不能完全匹配，则说明输入的表达式有错

建议使用C++自带的stack对象来实现

stack类使用的参考代码

n包含头文件<stack>  ：  #include <stack>

n创建一个堆栈对象s（注意stack是模板类）：stack <char>  s; //堆栈的数据类型是字符型
n把一个字符ct压入堆栈： s.push(ct);
n把栈顶元素弹出：s.pop();
n获取栈顶元素，放入变量c2： c2 = s.top();
n判断堆栈是否空： s.empty()，如果为空则函数返回true，如果不空则返回false

输入
第一行输入一个t，表示下面将有t组测试数据。接下来的t行的每行输入一个表达式，表达式只考虑英文半角状态输入，无需考虑中文全角输入

输出
对于每一行的表达式，检查括号是否匹配，匹配则输入ok，不匹配则输出error

样例输入
2
(a+b)[4*5+(-6)]
[5*8]/{(a+b)-6
样例输出
ok
error
提示
算法流程


1、初始化，i=0，建立堆栈，栈为空

2、输入表达式，建立指针指向表达式的头部

3、读入表达式的第i个字符

4、如果第i个字符是左括号，入栈

5、如果第i个字符是右括号，检查栈顶元素是否匹配

   A.如果匹配，弹出栈顶元素

   B.如果不匹配，报错退出

6、i++，指向下一个字符，是否已经表达式末尾

   A. 未到末尾，重复步骤3

   B. 已到达末尾

      a. 堆栈为空，输出ok

      b. 堆栈不为空，输出error
*/

#include <iostream>
#include <string>
#include <stack>
#include <map>

std::string all = "()[]{}";
std::map<char, char> map = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        std::string input;
        std::cin >> input;

        std::string str = "";
        for (char c : input)
        {
            if (all.find(c) != std::string::npos)
                str += c;
        }

        if (str.empty())
        {
            std::cout << "ok";
        }
        else if (str.length() % 2)
        {
            std::cout << "error";
        }
        else
        {
            bool flag = true;
            std::stack<char> s;
            for (char c : str)
            {
                if (map.count(c))
                    s.push(c);
                else
                {
                    if (s.empty() || map[s.top()] != c)
                    {
                        std::cout << "error";
                        flag = false;
                        break;
                    }
                    s.pop();
                }
            }
            if (flag)
                std::cout << (s.empty() ? "ok" : "error");
        }

        std::cout << std::endl;
    }

    return 0;
}