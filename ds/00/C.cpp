/*
问题 C: Date(类与对象)
时间限制: 1 Sec  内存限制: 128 MB
提交: 458  解决: 248
[提交][状态][讨论版]
题目描述
下面是一个日期类的定义，请在类外实现其所有的方法，并在主函数中生成对象测试之。



注意，在判断明天日期时，要加入跨月、跨年、闰年的判断

例如9.月30日的明天是10月1日，12月31日的明天是第二年的1月1日

2月28日的明天要区分是否闰年，闰年则是2月29日，非闰年则是3月1日

输入
测试数据的组数t

第一组测试数据的年 月 日

..........

要求第一个日期的年月日初始化采用构造函数，第二个日期的年月日初始化采用setDate方法，第三个日期又采用构造函数，第四个日期又采用setDate方法，以此类推。

输出
输出今天的日期

输出明天的日期

样例输入
4
2012 1 3
2012 2 28
2012 3 31
2012 4 30
样例输出
Today is 2012/01/03
Tomorrow is 2012/01/04
Today is 2012/02/28
Tomorrow is 2012/02/29
Today is 2012/03/31
Tomorrow is 2012/04/01
Today is 2012/04/30
Tomorrow is 2012/05/01
提示
*/

#include <iostream>

class Date
{
    int year, month, day;

public:
    Date();
    Date(int y, int m, int d);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int y, int m, int d);
    void print();
    void addOneDay();
};

Date::Date()
{
    this->setDate(0, 1, 1);
}

Date::Date(int y, int m, int d)
{
    this->setDate(y, m, d);
}

int Date::getYear()
{
    return this->year;
}

int Date::getMonth()
{
    return this->month;
}

int Date::getDay()
{
    return this->day;
}

void Date::setDate(int y, int m, int d)
{
    this->year = y;
    this->month = m;
    this->day = d;
}

void Date::print()
{
    printf("%d/%02d/%02d", this->year, this->month, this->day);
}

void Date::addOneDay()
{
    int &year = this->year;
    int &month = this->month;
    int &day = this->day;

    switch (month)
    {
    case 2:
    {
        if (day == 28)
        {
            if (year % 400 == 0 || year % 4 == 0)
            {
                day++;
            }
            else
            {
                month++;
                day = 1;
            }
        }
        else if (day == 29)
        {
            month++;
            day = 1;
        }
        else
        {
            day++;
        }
    }
    break;

    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if (day == 31)
        {
            month++;
            day = 1;
        }
        else
        {
            day++;
        }
    }
    break;

    case 4:
    case 6:
    case 9:
    case 11:
    {
        if (day == 30)
        {
            month++;
            day = 1;
        }
        else
        {
            day++;
        }
    }
    break;
    }

    if (month == 12)
    {
        year++;
        month = 1;
    }
}

int main()
{
    int t, y, m, d;
    std::cin >> t;

    while (t--)
    {
        std::cin >> y >> m >> d;
        Date date(y, m, d);

        std::cout << "Today is ";
        date.print();
        std::cout << std::endl;

        std::cout << "Tomorrow is ";
        date.addOneDay();
        date.print();
        std::cout << std::endl;
    }

    return 0;
}
