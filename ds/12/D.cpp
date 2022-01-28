/*
问题 D: 拓扑排序-STL版
时间限制: 1 Sec  内存限制: 128 MB
提交: 110  解决: 85
[提交][状态][讨论版]
题目描述
已知有向图，顶点从0开始编号，求它的求拓扑有序序列。

拓扑排序算法：给出有向图邻接矩阵
1.逐列扫描矩阵，找出入度为0且编号最小的顶点v

2.输出v，并标识v已访问

3.把矩阵第v行全清0

重复上述步骤，直到所有顶点输出为止

/////////////////////////////////////////////////
// STL::vector基本用法
1)
vector<int>::push_back(1); //将1增加到数组尾部
vector<E>::push_back(e); //将类型为E的一个对象e增加到数组尾部.其中类型E可以自行定义，如Vertex类，int类等。
2.1)
vector<int> vec; 
int x = vec[1];  //读取组数v（索引从0开始）的第1个元素
2.2)
vector<int> v; 
int& x = v[1]; //引用组数v的第1个元素，注意此处的引用&的用法
 x = 10; //修改组数v的第1个元素为10
3)

vector<vector<int> > adjMat; //声明一个矩阵对象adjMat
vector<int> row;  //声明一个vector（动态数组）对象row表示矩阵的一行
int j=0;
for(; j<n; ++j) {
    int edge;
    cin >> edge;
    row.push_back(edge); //将边信息增加到数组row的最后
}

this->adjMat.push_back(row); //将row增加到数组adjMat的最后
//////////////////////////////////////////////////////////////////////////////////////////

// 参考代码框架

#include <iostream>
#include <vector>
using namespace std;
class Graph {
public:
    vector<bool> isFinished;      //索引号所指示的顶点是否已处理过
    vector<vector<int> > adjMat;  //邻接矩阵
    int n;                        //顶点数 as 成员变量
public:
    void readAdjMatrix() {
        //从输入读入邻接矩阵，存入this->adjMat
        cin >> this->n;           //顶点数
        int i=0;
        for(; i<n; ++i) {
            //TODO：设置this->isFinished数组：每个顶点未曾访问过
            //提示：调用vector::push_back方法
            vector<int> row;
            int j=0;
            for(; j<n; ++j) {
                int edge;
                cin >> edge;    //读入顶点对i,j之间是否有一条边
                //TODO：将边信息增加入row
            }
            //TODO：将row增加入this->adjMat
            //提示：以row为参数，调用adjMat的push_back方法
        }
    }
    bool isZeroInDegrees(int vertexNo) {
    //判定顶点vertexNo是否没有入度
        int i=0;
        //this->adjMat[i][vertexNo] == 0
        //表示顶点i与vertexNo之间没有边相连
        for(; i<n && this->adjMat[i][vertexNo] == 0; ++i);
        //TODO：返回true if 顶点vertexNo没有入度; false [otherwise]
    }
    int select() {
    //从所有顶点中，选出一个顶点i，满足：
    //1) i没有处理过，即isFinished[i]=false
    //2) i的入度为0
        int i = 0;
        for (; i < n; ++i) {
            //TODO：若顶点i的已经处理过，则pass
            //TODO：若顶点度>0，则pass
            //提示：调用isZeroInDegrees
            //TODO: 设置顶点i已经处理过，即isFinished[i]为正确值
            //TODO: 返回i
        }
        //TODO: 返回-1, 表示未找到满足1)+2)条件的顶点
    }
    void update(int rootNo) {
    //更新顶点rootNo的出弧，即将顶点rootNo从图中断开
        int j=0;
        for(;j<n; ++j) {
            //TODO： 设置adjMat[rootNo][j]为0
        }
    }
    /////////////////////////////////////////////////////
    // 拓扑排序主算法
    void topologySort() {
        int i=0;
        for(; i<n; ++i) {  //遍历n次：即按拓扑序，依次选择（排出）n个顶点
            int root;  // 声明顶点索引号（编号）用于存放本次选出的顶点
            //TODO： 调用select方法，并将其返回值存入root
            //TODO： 若root=-1，则break;
            // root=-1表示没有可以排出的顶点
            //TODO: 以root为参数，调用update方法
            //TODO：输出当前选出的顶点root 和一个空格
        }
        //TODO：输出一行
    }
    void main() {
        readAdjMatrix();
        topologySort();
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        Graph g;
        g.main();
    }
    return 0;
}
输入
第一行输入一个整数t，表示有t个有向图

第二行输入n，表示图有n个顶点

第三行起，输入n行整数，表示图对应的邻接矩阵

以此类推输入下一个图的顶点数和邻接矩阵

输出
每行输出一个图的拓扑有序序列

样例输入
2
5
0 1 0 1 1
0 0 1 0 0
0 0 0 0 1
0 0 1 0 0
0 0 0 0 0
7
0 0 0 0 0 0 0
1 0 1 1 0 0 0
1 0 0 0 0 0 0
1 0 1 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 0 0 1 0 1 0
样例输出
0 1 3 2 4 
4 6 5 1 3 2 0 
提示
*/

#include <cstdio>
#include <vector>

class Graph
{
private:
    int _n;
    std::vector<int *> _matrix;
    std::vector<bool> _visited;

public:
    Graph(int n)
    {
        _n = n;
        _matrix.resize(n);
        _visited.resize(n);
        for (int i = 0; i < n; i++)
        {
            _matrix[i] = new int[n];
            _visited[i] = false;
        }
    }

    ~Graph()
    {
        for (auto item : _matrix)
            delete[] item;
    }

    void Read()
    {
        for (int i = 0; i < _n; i++)
            for (int j = 0; j < _n; j++)
                scanf("%d", _matrix[i] + j);
    }

    void TopologicalSort()
    {
        for (int k = 0; k < _n; k++)
        {
            int target;
            for (int i = 0; i < _n; i++)
            {
                if (_visited[i])
                    continue;
                bool flag = true;
                for (int j = 0; j < _n; j++)
                {
                    if (_matrix[j][i] == 1)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    target = i;
                    break;
                }
            }

            _visited[target] = true;
            printf("%d ", target);
            for (int i = 0; i < _n; i++)
                _matrix[target][i] = _matrix[i][target] = -1;
        }
        putchar('\n');
    }
};

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        Graph g(n);
        g.Read();
        g.TopologicalSort();
    }
    return 0;
}