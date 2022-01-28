/*
问题 E: DS堆栈--字符替换
时间限制: 1 Sec  内存限制: 128 MB
提交: 55  解决: 47
[提交][状态][讨论版]
题目描述
在一个行编辑处理程序中，用户将输入一行字符。若用户输入#，表示将#之前的字符替换为@，#本身不算字符输入。

请使用C++自带的stack栈进行编程。必须使用堆栈来实现，其他方法0分！

stack类使用的参考代码

n包含头文件<stack>  ：  #include <stack>

n创建一个堆栈对象s（注意stack是模板类）：stack <char>  s; //堆栈的数据类型是字符型
n把一个字符ct压入堆栈： s.push(ct);
n把栈顶元素弹出：s.pop();
n获取栈顶元素，放入变量c2： c2 = s.top();
n判断堆栈是否空： s.empty()，如果为空则函数返回true，如果不空则返回false
输入
第一行输入一个t，表示下面将有t行字符

第二行输入t行字符，若输入字符中有#，则检查#的前一个字符，如果该字符不是@，则替换为@；如果该字符已经是@，则执行退格操作把@删除。输入的字符串不含空格

输出
输出每一行字符的最终结果

样例输入
2
szubjcs#szu.edu.cn
AA9###china
样例输出
szubjc@szu.edu.cn
A@china
提示
*/

#include <iostream>
#include <string>
#include <stack>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        std::string str;
        std::cin >> str;

        std::stack<char> s;
        for (char c : str)
        {
            if (c == '#')
            {
                if (s.size())
                {
                    if (s.top() == '@')
                        s.pop();
                    else
                        s.top() = '@';
                }
            }
            else
                s.push(c);
        }

        std::stack<char> reverse;
        while (!s.empty())
        {
            reverse.push(s.top());
            s.pop();
        }

        while (!reverse.empty())
        {
            std::cout << reverse.top();
            reverse.pop();
        }

        std::cout << std::endl;
    }

    return 0;
}