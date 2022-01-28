/*
问题 D: DS链表—学生宿舍管理
时间限制: 1 Sec  内存限制: 128 MB
提交: 178  解决: 133
[提交][状态][讨论版]
题目描述
假设某校有20间宿舍，宿舍编号101，102，...,120。每间只住一名学生。初始部分宿舍已用。用两个链表（已用宿舍链表和可用宿舍链表）维护宿舍的管理，实现宿舍分配、宿舍交回。

约定已用宿舍链表按宿舍号升序链接。初始可用宿舍链表也按宿舍号升序链接。

宿舍分配从可用宿舍链表中摘取第一间宿舍分配给学生。学生交回的宿舍挂在可用宿舍链表最后。

备注：使用list容器或静态链表。不用考虑宿舍分配和交回不成功的情况。

输入
初始宿舍状态，第一行输入n，表示已用宿舍n间

后跟n行数据，每行格式为：宿舍号 学生姓名

操作次数m，后跟m行操作，操作格式如下：

assign 学生  //为学生分配宿舍，从可用宿舍链表头摘取一间宿舍，

                    //按宿舍号升序挂在已用宿舍链表中。

return  宿舍号   //学生退宿舍，删除已用宿舍链表中对应结点，

                         //挂在可用宿舍链表尾部。

display_free   //输出可用宿舍链表信息。

display_used   //输出已用宿舍链表信息。



输出
 display_free依次输出当前可用宿舍链表中的宿舍号，具体格式见样例。

 display_used依次输出当前已用宿舍链表中的学生和宿舍号，具体格式见样例。

样例输入
5
李明  103
张三  106
王五  107
钱伟  112
章立  118
8
assign 李四
assign 赵六
return 118
return 101
assign 马山
display_used
assign 林立
display_free
样例输出
赵六(102)-李明(103)-马山(104)-张三(106)-王五(107)-钱伟(112)
108-109-110-111-113-114-115-116-117-119-120-118-101
提示
list是一种序列式容器, list实际上就构成了一个双向循环链,

List类使用的参考代码

包含头文件<list>  ：  #include <list>

List定义和初始化：

    list<int>lst1;          //创建空list

    list<int> lst2(5);       //创建含有5个元素的list

    list<int>lst3(3,2);  //创建含有3个元素的list

    list<int>lst4(lst2);    //使用lst2初始化lst4

    list<int>lst5(lst2.begin(),lst2.end());  //同lst4


创建一个list对象l（注意list是模板类）：list<char>  l; //堆栈的数据类型是字符型

把一个字符ct添加到链表末尾： s.push_back(ct);

把一个字符ct插入到链表头部： s.push_front(ct);

获取链表第一个元素和最后一个元素：front()和back()，获取链表第一个元素，放入变量c2： c2 = s.front();

删除链表第一个元素和最后一个元素pop_front()和pop_back();

判断 判断list是否为空:empty()： l.empty()，如果为空则函数返回true，如果不空则返回false

begin() 返回指向第一个元素的迭代器 

end() 返回末尾的迭代器

rbegin() 返回指向第一个元素的逆向迭代器 

rend() 指向list末尾的逆向迭代器


程序示列：

#include <iostream> 

using namespace std;

typedef list<int> LISTINT; 

    

 void main() 

 { 

   //用LISTINT创建一个list对象 

   LISTINT listOne; 

   //声明i为迭代器 

   LISTINT::iterator i; 

    

   listOne.push_front(3); 

   listOne.push_front(2); 

   listOne.push_front(1); 

    

   listOne.push_back(4); 

   listOne.push_back(5); 

   listOne.push_back(6); 

    

   cout << "listOne.begin()--- listOne.end():" << endl; 

   for (i = listOne.begin(); i != listOne.end(); ++i) 

     cout << *i << " "; 

   cout << endl;    //正向输出

    

   LISTINT::reverse_iterator ir; 

   cout << "listOne.rbegin()---listOne.rend():" << endl; 

   for (ir = listOne.rbegin(); ir != listOne.rend(); ir++) { 

     cout << *ir << " "; 

   }   

   cout << endl;    //反向输出

}

*/

#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>

struct dorm
{
    int room;
    std::string student;
};

int main()
{
    int n, m;
    std::cin >> n;

    std::list<dorm> free;
    std::map<int, dorm> used;

    std::set<int> temp;
    while (n--)
    {
        dorm d;
        std::cin >> d.student >> d.room;
        used[d.room] = d;
        temp.insert(d.room);
    }

    for (int i = 101; i <= 120; ++i)
    {
        if (!temp.count(i))
        {
            dorm d;
            d.room = i;
            free.push_back(d);
        }
    }

    std::cin >> m;
    std::string cmd;
    while (m--)
    {
        std::cin >> cmd;
        if (cmd == "assign")
        {
            dorm d = free.front();
            free.pop_front();
            std::cin >> d.student;
            used[d.room] = d;
        }
        else if (cmd == "return")
        {
            int room;
            std::cin >> room;
            dorm d = used[room];
            used.erase(room);
            free.push_back(d);
        }
        else if (cmd == "display_free")
        {
            bool first = true;
            for (auto &item : free)
            {
                if (first)
                    first = false;
                else
                    std::cout << '-';
                std::cout << item.room;
            }
            std::cout << std::endl;
        }
        else if (cmd == "display_used")
        {
            bool first = true;
            for (auto &item : used)
            {
                if (first)
                    first = false;
                else
                    std::cout << '-';
                std::cout << item.second.student << '(' << item.first << ')';
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
