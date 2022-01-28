/*
问题 C: DS队列--组队列
时间限制: 1 Sec  内存限制: 128 MB
提交: 356  解决: 235
[提交][状态][讨论版]
题目描述
组队列是队列结构中一种常见的队列结构，在很多地方有着广泛应用。组队列是是指队列内的元素分组聚集在一起。组队列包含两种命令：

1、 ENQUEUE，表示当有新的元素进入队列，首先会检索是否有同一组的元素已经存在，如果有，则新元素排在同组的最后，如果没有则插入队列末尾。

2、 DEQUEUE，表示队列头元素出队

3、 STOP，停止操作

建议使用C++自带的队列对象queue，编程更方便

输入
第1行输入一个t(t<=10)，表示1个队列中有多少个组

第2行输入一个第1组的元素个数和数值

第3行输入一个第2组的元素个数和数值

以此类推输入完t组以定义同组元素之后，开始输入多个操作命令(<200)，对空的组队列进行操作，例如输入ENQUEUE 100，表示把元素100插入队列

输出
DEQUEUE出队的元素

样例输入
2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
STOP
样例输出
101 102 103
提示
 3 101 102 103
 3 201 202 203
 3 301 302 303 
 ENQUEUE 201  ==>>> | 201 |
 ENQUEUE 301  ==>>> | 201 | 301 |
 ENQUEUE 102  ==>>> | 201 | 301 | 102 |
 ENQUEUE 101  ==>>> | 201 | 301 | 102 101 |
 ENQUEUE 203  ==>>> | 201 203 | 301 | 102 101 |
 ENQUEUE 302  ==>>> | 201 203 | 301 302 | 102 101 |






可以看到队列分组，先入队的组在队列中靠前，出队也靠前：



DEQUEUE 输出 201，队列变为 | 203 | 301 302 | 102 101 | …
*/

#include <iostream>
#include <queue>

using namespace std;

struct nums
{
    int len, *p;
};

struct queue_num
{
    int number, order;
};

int main()
{
    int t;
    cin >> t;

    nums *a = new nums[t];

    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        a[i].len = n;
        a[i].p = new int[n];
        for (int k = 0; k < a[i].len; k++)
            cin >> a[i].p[k];
    }

    queue<queue_num> q[10];
    queue<queue_num> qq;

    while (1)
    {
        string input;
        cin >> input;
        if (input == "ENQUEUE")
        {
            int x;
            cin >> x;
            queue_num y;
            for (int i = 0; i < t; i++)
            {
                for (int k = 0; k < a[i].len; k++)
                {
                    if (x == a[i].p[k])
                    {
                        y.number = x;
                        y.order = i;
                    }
                }
            }
            if (q[0].empty() == true)
            {
                q[0].push(y);
            }
            else
            {
                int j = 0;
                for (int i = 0; i < 10; i++)
                {
                    if (q[i].empty() != true)
                    {
                        if (q[i].front().order == y.order)
                            q[i].push(y);
                    }
                    else if (q[i].empty() == true)
                    {
                        j = i;
                        break;
                    }
                }
                if (j != 0)
                    q[j].push(y);
            }
        }
        else if (input == "DEQUEUE")
        {
            for (int i = 0; i < 10; i++)
            {
                if (q[i].empty() != true)
                {
                    qq.push(q[i].front());
                    q[i].pop();
                    break;
                }
            }
        }
        else if (input == "STOP")
        {
            while (!qq.empty())
            {
                cout << qq.front().number << " ";
                qq.pop();
            }
            break;
        }
    }
    return 0;
}