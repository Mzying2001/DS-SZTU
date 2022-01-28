/*
问题 B: DS堆栈--行编辑
时间限制: 1 Sec  内存限制: 128 MB
提交: 327  解决: 219
[提交][状态][讨论版]
题目描述
使用C++的STL堆栈对象，编写程序实现行编辑功能。行编辑功能是：当输入#字符，则执行退格操作；如果无字符可退就不操作，不会报错

本程序默认不会显示#字符，所以连续输入多个#表示连续执行多次退格操作

每输入一行字符打回车则表示字符串结束

注意：必须使用堆栈实现，而且结果必须是正序输出

输入
第一行输入一个整数t，表示有t行字符串要输入
第二行起输入一行字符串，共输入t行

输出
每行输出最终处理后的结果，如果一行输入的字符串经过处理后没有字符输出，则直接输出NULL

样例输入
4
chinaa#
sb#zb#u
##shen###zhen###
chi##a#####
样例输出
china
szu
sz
NULL
提示
*/

#include <iostream>
#include <string>
#include <stack>

int main()
{
    int n;
    std::cin >> n;

    while (n--)
    {
        std::string str;
        std::cin >> str;

        std::stack<char> s;
        for (char c : str)
        {
            if (c == '#')
            {
                if (!s.empty())
                    s.pop();
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

        if (reverse.empty())
        {
            std::cout << "NULL";
        }
        else
        {
            while (!reverse.empty())
            {
                std::cout << reverse.top();
                reverse.pop();
            }
        }
        std::cout << std::endl;
    }

    return 0;
}