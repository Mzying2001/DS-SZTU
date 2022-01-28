/*
问题 D: DS队列----银行单队列多窗口模拟
时间限制: 1 Sec  内存限制: 128 MB
提交: 271  解决: 191
[提交][状态][讨论版]
题目描述
假设银行有K个窗口提供服务，窗口前设一条黄线，所有顾客按到达时间在黄线后排成一条长龙。当有窗口空闲时，下一位顾客即去该窗口处理事务。当有多个窗口可选择时，假设顾客总是选择编号最小的窗口。

本题要求输出前来等待服务的N位顾客的平均等待时间、最长等待时间、最后完成时间。

输入
输入第1行给出正整数N（≤1000），为顾客总人数；随后N行，每行给出一位顾客的到达时间T和事务处理时间P，并且假设输入数据已经按到达时间先后排好了顺序；最后一行给出正整数K（≤10），为开设的营业窗口数。

输出
在一行中输出平均等待时间（输出到小数点后1位）、最长等待时间、最后完成时间，之间用1个空格分隔，行末不能有多余空格。

样例输入
9
0 20
1 15
1 61
2 10
10 5
10 3
30 18
31 25
31 2
3
样例输出
6.2 17 62

提示
*/

#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

struct customer
{
    int T, P;
    double WT;
};

int main()
{
    int n;
    cin >> n;

    customer *c = new customer[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].T;
        cin >> c[i].P;
        c[i].WT = 999;
    }

    int k;
    cin >> k;
    int *w = new int[k];
    for (int j = 0; j < k; j++)
    {
        w[j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (w[j] <= c[i].T)
            {
                if (w[j] == 0)
                    w[j] += c[i].P + c[i].T;
                else
                    w[j] = c[i].P + c[i].T;
                c[i].WT = 0;
                break;
            }
        }
        if (c[i].WT == 999)
        {
            int *nwt = new int[k];
            for (int j = 0; j < k; j++)
            {
                nwt[j] = w[j] - c[i].T;
            }
            int min;
            int h;
            min = nwt[0];
            h = 0;
            for (int j = 0; j < k; j++)
            {
                if (min > nwt[j])
                {
                    min = nwt[j];
                    h = j;
                }
            }
            c[i].WT = w[h] - c[i].T;
            w[h] += c[i].P;
        }
    }

    double sum = 0;
    int maxt = 0;
    for (int i = 0; i < n; i++)
    {
        sum += c[i].WT;
        if (maxt < c[i].WT)
            maxt = c[i].WT;
    }

    double at;
    at = sum / n;
    int finalt = 0;
    for (int j = 0; j < k; j++)
    {
        if (finalt < w[j])
            finalt = w[j];
    }

    cout << fixed << setprecision(1) << at << " ";
    cout << maxt << " " << finalt << endl;

    return 0;
}