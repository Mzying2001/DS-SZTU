/*
问题 C: 判断矩形是否重叠(结构)
时间限制: 1 Sec  内存限制: 128 MB
提交: 196  解决: 133
[提交][状态][讨论版]
题目描述
用具有x,y两个整型变量成员的结构类型SPoint来表示坐标点。用SRect结构类型来描述矩形，其中包含p1和p2两个SPoint成员分别表示矩形对角线上的两个点。

编写判断两个矩形是否重叠的函数。

输入
判断次数

矩形1的对角线顶点坐标x1、y1、x2、y2

矩形2的对角线顶点坐标x1、y1、x2、y2

......

输出
是否重叠

样例输入
3
1 5 2 9
1 3 2 4
5 6 7 8
5 7 7 7
2 5 1 0
9 4 2 9
样例输出
not overlapped
overlapped
overlapped
提示
两个矩形的边均与x轴或y轴平行，即轴对齐的矩形。


*/

#include <iostream>

struct SPoint
{
    int x, y;
};

class SRect
{
public:
    SPoint p1, p2;

    SRect(int x1, int y1, int x2, int y2)
    {
        if (x1 > x2)
            std::swap(x1, x2);
        if (y1 > y2)
            std::swap(y1, y2);
        p1 = {x1, y1};
        p2 = {x2, y2};
    }

    bool isOverlap(SRect &other)
    {
        bool flag = (p2.x < other.p1.x) ||
                    (p1.x > other.p2.x) ||
                    (p2.y < other.p1.y) ||
                    (p1.y > other.p2.y);
        return !flag;
    }
};

int main()
{
    int t, n;
    std::cin >> t;

    while (t--)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        SRect a(x1, y1, x2, y2);
        std::cin >> x1 >> y1 >> x2 >> y2;
        SRect b(x1, y1, x2, y2);
        std::cout << (a.isOverlap(b) ? "overlapped" : "not overlapped") << std::endl;
    }

    return 0;
}
