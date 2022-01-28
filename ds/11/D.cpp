/*
问题 D: 货币套汇（图路径）
时间限制: 1 Sec  内存限制: 128 MB
提交: 102  解决: 68
[提交][状态][讨论版]
题目描述
套汇是指利用货币汇兑率的差异将一个单位的某种货币转换为大于一个单位的同种货币。例如，假定1 美元可以买0.7 英镑，1 英镑可以买9.5 法郎，1法郎可以买到0.16美元。通过货币兑换，一个商人可以从1 美元开始买入，得到0.7×9.5×0.16=1.064美元，从而获得6.4%的利润。 给定n种货币c1 ,c2 ,... ,cn的有关兑换率，试设计一个有效算法，确定货币间是否存在套汇的可能性。

提示：判断图上是否出现正环,即环上所有的边相乘大于1

输入
第一行：测试数据组数

每组测试数据格式为：

第一行：正整数n (1< =n< =30)，正整数m，分别表示n种货币和m种不同的货币兑换率。

2~n+1行，n种货币的名称。

n+2~n+m+1行，每行有3 个数据项ci，rij 和cj ，表示货币ci 和cj的兑换率为 rij。

输出
对每组测试数据，如果存在套汇的可能则输出YES

如果不存在套汇的可能，则输出NO。

样例输入
2
3 3
USDollar
BritishPound
FrenchFranc
USDollar 0.5 BritishPound
BritishPound 10.0 FrenchFranc
FrenchFranc 0.21 USDollar
3 6
USDollar
BritishPound
FrenchFranc
USDollar 0.5 BritishPound
USDollar 4.9 FrenchFranc
BritishPound 10.0 FrenchFranc
BritishPound 1.99 USDollar
FrenchFranc 0.09 BritishPound
FrenchFranc 0.19 USDollar
样例输出
YES
NO
提示
*/

#include <iostream>

#define MAX_NUM 20
using namespace std;

class Matrix
{
private:
    double matrix[MAX_NUM][MAX_NUM];
    string node[MAX_NUM];
    int node_num, arc_num, conn_num, flag, Visit[MAX_NUM];
    double value;
    void dfs(int v);

public:
    Matrix(int n)
    {
        node_num = n;
        conn_num = 0;
        flag = 0;
    }

    int getIndex(string s);
    void getMatrix();
    void display();
    void dfsTraverse();
};

int Matrix::getIndex(string s)
{
    for (int i = 0; i < node_num; i++)
    {
        if (node[i] == s)
            return i;
    }
    return -1;
}

void Matrix::getMatrix()
{
    for (int i = 0; i < node_num; i++)
        for (int j = 0; j < node_num; j++)
            matrix[i][j] = 0;

    cin >> arc_num;
    for (int i = 0; i < node_num; i++)
    {
        string s1;
        cin >> s1;
        node[i] = s1;
    }
    for (int i = 0; i < arc_num; i++)
    {
        string s1, s2;
        double currency;
        int index1, index2;
        cin >> s1 >> currency >> s2;
        index1 = getIndex(s1);
        index2 = getIndex(s2);
        matrix[index1][index2] = currency;
    }
}

void Matrix::dfsTraverse()
{
    int v, k, i;
    for (k = 0; k < node_num; k++)
    {
        int counter = 0;
        value = 1.0;
        v = k;
        for (i = 0; i < node_num; i++)
        {
            if (i == v)
                Visit[i] = 2;
            else
                Visit[i] = 0;
        }

        do
        {
            if (Visit[v] == 0 || Visit[v] == 2)
            {
                counter++;
                if (counter > 1)
                    break;
                dfs(v);
            }
            v = (v + 1) % node_num;
        } while (v != k);
    }

    if (flag == 1)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}

void Matrix::dfs(int v)
{
    int w, i, k;
    if (Visit[v] == 0)
        Visit[v] = 1;

    int *AdjVex = new int[node_num];
    for (i = 0; i < node_num; i++)
        AdjVex[i] = -1;

    k = 0;
    for (i = 0; i < node_num; i++)
    {
        if (matrix[v][i] != 0)
        {
            AdjVex[k] = i;
            k++;
        }
    }

    i = 0;
    for (w = AdjVex[0]; w != -1; w = AdjVex[i])
    {
        if (Visit[w] == 0)
        {
            value = value * matrix[v][w];
            dfs(w);
        }

        else if (Visit[w] == 2)
        {
            double temp_value = value;
            temp_value = temp_value * matrix[v][w];
            if (temp_value > 1.0)
            {
                flag = 1;
            }
        }
        i++;
    }

    delete[] AdjVex;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Matrix m(n);
        m.getMatrix();
        m.dfsTraverse();
    }
    return 0;
}