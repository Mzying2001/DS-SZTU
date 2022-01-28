/*
问题 D: 火车站(stack)
时间限制: 1 Sec  内存限制: 128 MB
提交: 227  解决: 158
[提交][状态][讨论版]
题目描述
火车站只有一条铁路，所有的火车都停在那里。所以所有的火车都是从一边进站，从另一边出站。如果A列先进入铁路，然后B列在A列离开之前进入铁路，那么A列在B列离开之前不能离开。下图说明了问题所在。车站里最多有9列火车，所有的火车都有一个ID（编号从1到N），火车按照O1的顺序进入火车，火车是否可以按照O2的顺序驶出。



输入
输入包含几个测试用例。

每个测试用例由一个整数（列车数）和两个字符串组成。两个字符串分别为列车入站顺序和列车出站顺序。

输出
如果不能按照指定顺序出站，输出“No”。

如果可以，输出“Yes”，然后输出出入站顺序（对于进入铁路的列车，应输出“in”，对于出铁路的列车，应输出“out”）。在每个测试用例之后打印一行包含“FINISH”。

样例输入
3
3 123 321 
3 abc cab
3 123 123
样例输出
Yes
in
in
in
out
out
out
FINISH
No
FINISH
Yes
in
out
in
out
in
out
FINISH

提示
*/

#include <cstdio>
#include <queue>
#include <stack>

#define IN 1
#define OUT 0

int main()
{
    // freopen("in.txt", "r", stdin);

    char in[10], out[10];
    int t, len;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s%s", &len, in, out);

        std::queue<bool> result;
        std::stack<char> stack;
        char *pIn = in, *pOut = out;

        while (*pOut)
        {
            while (*pIn && *pIn != *pOut)
            {
                stack.push(*pIn++);
                result.push(IN);
            }

            if (!*pIn)
                break;
            
            if (*pIn == *pOut)
            {
                pIn++, pOut++;
                result.push(IN);
                result.push(OUT);
            }

            while (!stack.empty() && stack.top() == *pOut)
            {
                result.push(OUT);
                stack.pop();
                pOut++;
            }
        }
        if (stack.empty() && !*pOut)
        {
            puts("Yes");
            while (!result.empty())
            {
                puts(result.front() == IN ? "in" : "out");
                result.pop();
            }
        }
        else
        {
            puts("No");
        }
        puts("FINISH");
    }

    return 0;
}