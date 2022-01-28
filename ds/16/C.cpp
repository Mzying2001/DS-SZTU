/*
问题 C: 键盘坏了 （线性结构)
时间限制: 1 Sec  内存限制: 128 MB
提交: 47  解决: 17
[提交][状态][讨论版]
题目描述
键盘坏了QAQ，会时不时的自动按下Home键和END键，你能告诉我敲击后的文本长什么样子嘛 T^T

输入
测试数据有多组，每组包括一行字符串（长度 <= 105），其中'['代表敲击了Home键，']'代表敲击了END键

输出
对于每组数据输出敲击后的文本

样例输入
This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
样例输出
BeijuThis_is_a__text
Happy_Birthday_to_Tsinghua_University
提示

*/

#include <cstdio>
#include <list>

char buf[int(1e5) + 1];

struct Span
{
    int begin, end;
};

int main()
{
    // freopen("in.txt", "r", stdin);

    std::list<Span> list;
    while (scanf("%s", buf) != EOF)
    {
        list.push_back({0, 0});
        bool flag = 1;
        for (int i = 0; buf[i]; i++)
        {
            char c = buf[i];
            if (c == '[')
            {
                list.push_front({i + 1, i + 1});
                flag = 1;
            }
            else if (c == ']')
            {
                list.push_back({i + 1, i + 1});
                flag = 0;
            }
            else
            {
                Span &s = flag ? list.front() : list.back();
                s.end++;
            }
        }
        for (auto item : list)
        {
            for (int i = item.begin; i < item.end; i++)
                putchar(buf[i]);
        }
        putchar('\n');
        list.clear();
    }
    return 0;
}
