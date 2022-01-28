/*
问题 D: Point_Array
题目描述
上面是我们曾经练习过的一个习题，请在原来代码的基础上作以下修改：1、增加自写的拷贝构造函数；2、增加自写的析构函数；3、将getDisTo方法的参数修改为getDisTo(const Point &p)；4、根据下面输出的内容修改相应的构造函数。
然后在主函数中根据用户输入的数目建立Point数组，求出数组内距离最大的两个点之间的距离值。
输入
测试数据的组数 t
第一组点的个数
第一个点的 x 坐标   y坐标
第二个点的 x坐标  y坐标
............
输出
输出第一组距离最大的两个点以及其距离
...........
在C++中，输出指定精度的参考代码如下：
#include <iostream>
#include <iomanip> //必须包含这个头文件
using namespace std;
void main( )
{ double a =3.141596;
  cout<<fixed<<setprecision(3)<<a<<endl;  //输出小数点后3位
样例输入
2
4
0 0
5 0
5 5
2 10
3
-1 -8
0 9
5 0
样例输出
Constructor.
Constructor.
Constructor.
Constructor.
The longeset distance is 10.44,between p[1] and p[3].
Distructor.
Distructor.
Distructor.
Distructor.
Constructor.
Constructor.
Constructor.
The longeset distance is 17.03,between p[0] and p[1].
Distructor.
Distructor.
Distructor.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

class Point
{
    double x, y;

public:
    Point()
    {
        std::cout << "Constructor." << std::endl;
    }

    Point(double x_value, double y_value)
    {
        this->setXY(x_value, y_value);
        std::cout << "Constructor." << std::endl;
    }

    ~Point()
    {
        std::cout << "Distructor." << std::endl;
    }

    double getX()
    {
        return this->x;
    }

    double getY()
    {
        return this->y;
    }

    void setXY(double x_value, double y_value)
    {
        this->setX(x_value);
        this->setY(y_value);
    }

    void setX(double x_value)
    {
        this->x = x_value;
    }

    void setY(double y_value)
    {
        this->y = y_value;
    }

    double getDisTo(Point &p)
    {
        return sqrt((this->x - p.getX()) * (this->x - p.getX()) + (this->y - p.getY()) * (this->y - p.getY()));
    }
};

int main()
{
    int t, len;
    std::cin >> t;

    while (t--)
    {
        std::cin >> len;
        Point **arr = new Point *[len];

        for (int i = 0; i < len; ++i)
        {
            int x, y;
            std::cin >> x >> y;
            arr[i] = new Point(x, y);
        }

        double max_len = 0.0;
        int max_i = 0, max_j = 0;

        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                double dis = arr[i]->getDisTo(*arr[j]);
                if (dis > max_len)
                {
                    max_len = dis;
                    max_i = i;
                    max_j = j;
                }
            }
        }

        std::cout << "The longeset distance is "
                  << std::fixed << std::setprecision(2) << max_len
                  << ",between p[" << max_i << "] and p[" << max_j << "].\n";

        for (int i = 0; i < len; ++i)
            delete arr[i];
        delete[] arr;
    }

    return 0;
}
