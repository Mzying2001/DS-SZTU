/*
问题 D: 判断点线位置(结构)
时间限制: 1 Sec  内存限制: 128 MB
提交: 159  解决: 131
[提交][状态][讨论版]
题目描述
用具有x,y两个整型变量成员的结构类型SPoint来表示坐标点。用SLine结构类型来描述线段，其中包含p1和p2两个SPoint成员。

编写函数direction(const SLine &ab, const SPoint &c)，利用向量ab与ac叉乘的值判断点c与直线ab的位置关系。
输入
判断次数

线的两点坐标x1、y1、x2、y2

点坐标x、y

......

输出
位置关系

样例输入
3
1 5 2 9
1 3
5 6 7 8
6 7
2 3 1 0
3 3
样例输出
clockwise
intersect
anti clockwise
提示

向量a(x1,y1)与向量b(x2,y2)的叉乘定义为a.x*b.y-a.y*b.x,若结果小于0，表示向量b在向量a的顺时针方向；若结果大于0，表示向量b在向量a的逆时针方向；若等于0，表示向量a与向量b平行。


*/

#include <iostream>

struct SPoint
{
    int x, y;
};

struct SLine
{
    SPoint p1, p2;
};

void direction(const SLine &ab, const SPoint &c)
{
    int ax = ab.p2.x - ab.p1.x;
    int ay = ab.p2.y - ab.p1.y;
    int bx = c.x - ab.p1.x;
    int by = c.y - ab.p1.y;

    int res = ax * by - ay * bx;
    if (res == 0)
        std::cout << "intersect";
    else if (res > 0)
        std::cout << "anti clockwise";
    else
        std::cout << "clockwise";
    std::cout << std::endl;
}

int main()
{
    int t, n;
    std::cin >> t;

    while (t--)
    {
        int x1, y1, x2, y2, a, b;
        std::cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
        SLine ab = {{x1, y1}, {x2, y2}};
        SPoint c = {a, b};
        direction(ab, c);
    }

    return 0;
}
