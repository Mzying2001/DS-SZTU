/*
问题 E: 字符串操作（string）
时间限制: 3 Sec  内存限制: 128 MB
提交: 131  解决: 65
[提交][状态][讨论版]
题目描述
给定n个字符串（从1开始编号），每个字符串中的字符位置从0开始编号，长度为1-500，现有如下若干操作：

copy N X L：取出第N个字符串第X个字符开始的长度为L的字符串。

add S1 S2：判断S1，S2是否为0-99999之间的整数，若是则将其转化为整数做加法，若不是，则作字符串加法，返回的值为一字符串。  

find S N：在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。  

rfind S N：在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。  

insert S N X：在第N个字符串的第X个字符位置中插入S字符串。

reset S N：将第N个字符串变为S。

print N：打印输出第N个字符串。

printall：打印输出所有字符串。

over：结束操作。

其中N，X，L可由find与rfind操作表达式构成，S，S1，S2可由copy与add操作表达式构成。

提示：本题练习string类使用，所有的操作可调用string的方法实现。

输入
 第一行为一个整数n（n在1-20之间）  接下来n行为n个字符串，字符串不包含空格及操作命令等。  接下来若干行为一系列操作，直到over结束。

输出
 根据操作提示输出对应字符串。

样例输入
3
329strjvc
Opadfk48
Ifjoqwoqejr
insert copy 1 find 2 1 2 2 2
print 2
reset add copy 1 find 3 1 3 copy 2 find 2 2 2 3
print 3
insert a 3 2
printall
over
样例输出
Op29adfk48
358
329strjvc
Op29adfk48
35a8
提示
*/

#include <iostream>
#include <string>
#include <cctype>

std::string strs[11];
int strsCount;

std::string copy(int n, int x, int l)
{
    std::string ret = "";
    while (l--)
        ret += strs[n][x++];
    return ret;
}

bool isInt(std::string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

int toInt(std::string str)
{
    int ans = 0;
    for (char c : str)
        ans = ans * 10 + c - '0';
    return ans;
}

std::string add(std::string &s1, std::string &s2)
{
    if (s1.size() <= 5 && s2.size() <= 5 && isInt(s1) && isInt(s2))
    {
        int sum = toInt(s1) + toInt(s2);
        return std::to_string(sum);
    }
    return s1 + s2;
}

int indexOf(std::string &source, std::string &target)
{
    for (int i = 0; i < source.size() - target.size(); ++i)
    {
        bool flag = true;
        for (int j = 0; j < target.size(); ++j)
        {
            if (target[j] != source[i + j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return i;
    }
    return -1;
}

int find(std::string &s, int n)
{
    std::string &nstr = strs[n];
    int index = indexOf(nstr, s);
    return index == -1 ? s.size() : index;
}

int rIndexOf(std::string &source, std::string &target)
{
    for (int i = source.size() - target.size() - 1; i >= 0; --i)
    {
        bool flag = true;
        for (int j = 0; j < target.size(); ++j)
        {
            if (target[j] != source[i + j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return i;
    }
    return -1;
}

int rFind(std::string &s, int n)
{
    std::string &nstr = strs[n];
    int index = rIndexOf(nstr, s);
    return index == -1 ? s.size() : index;
}

void insert(std::string &s, int n, int x)
{
    strs[n].insert(x, s);
}

void reset(std::string &s, int n)
{
    strs[n] = s;
}

void print(int n)
{
    std::cout << strs[n] << std::endl;
}

void printAll()
{
    for (int i = 1; i <= strsCount; ++i)
        print(i);
}

std::string parse()
{
    std::string cmd;
    std::cin >> cmd;
    if (isInt(cmd))
    {
        return cmd;
    }
    else if (cmd == "copy")
    {
        int n = toInt(parse());
        int x = toInt(parse());
        int l = toInt(parse());
        return copy(n, x, l);
    }
    else if (cmd == "add")
    {
        std::string s1 = parse();
        std::string s2 = parse();
        return add(s1, s2);
    }
    else if (cmd == "find")
    {
        std::string s = parse();
        int n = toInt(parse());
        return std::to_string(find(s, n));
    }
    else if (cmd == "rfind")
    {
        std::string s = parse();
        int n = toInt(parse());
        return std::to_string(rFind(s, n));
    }
    else if (cmd == "insert")
    {
        std::string s = parse();
        int n = toInt(parse());
        int x = toInt(parse());
        insert(s, n, x);
    }
    else if (cmd == "reset")
    {
        std::string s = parse();
        int n = toInt(parse());
        reset(s, n);
    }
    else if (cmd == "print")
    {
        int n = toInt(parse());
        print(n);
    }
    else if (cmd == "printall")
    {
        printAll();
    }
    return cmd;
}

int main()
{
    std::cin >> strsCount;
    for (int i = 1; i <= strsCount; ++i)
        std::cin >> strs[i];

    while (true)
    {
        if (parse() == "over")
            break;
    }

    return 0;
}
