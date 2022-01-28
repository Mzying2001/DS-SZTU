/*
问题 E: 广度优先搜索-STL对象版
时间限制: 1 Sec  内存限制: 128 MB
提交: 62  解决: 50
[提交][状态][讨论版]
题目描述
广度优先搜索-STL对象版

给出一个图的邻接矩阵，对图进行深度优先搜索，从顶点0开始

注意：图n个顶点编号从0到n-1

/////////////////////////////////////////////////////////////////////////////////////////////////////////

基本STL的用法：

1）

vector<int>::push_back(1); //将1增加到数组尾部
vector<E>::push_back(e); //将类型为E的一个对象e增加到数组尾部.其中类型E可以自行定义，如Vertex类，int类等。
2.1)
vector<int> vec; 
int x = vec[1];  //读取组数v（索引从0开始）的第1个元素
2.2)
vector<int> v; 
int& x = v[1]; //引用组数v的第1个元素，注意此处的引用&的用法
 x = 10; //修改组数v的第1个元素为10
3.1）
queue<int> my_queue;
my_queue.push(0); //将0增加到队列尾部
3.2）
int root = my_queue.front(); //读取队列的首元素
my_queue.pop(); //弹出队列的首元素




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

代码框架如下：

#include <iostream>
#include <vector>
#include <queue>   //使用队列存放所有待打印（访问）结点
using namespace std;
class Graph {
public:
    vector<vector<int> > adjMat; //领接矩阵，adjMat[i,j]=1 if 顶点索引i,j之间有一条边，
    //adjMat[i,j]=0 if if 顶点索引i,j之间没有一条边
    int n; //顶点个数
    vector<bool> isVisited; //记录每个顶点（索引号值为[0,n)）是否已经按BFS方式访问过
public:
    void printAdjMat() { //用于调试
        int i=0;
        for(; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
    void readAdjMat() {
        cin >> this->n;               //将结点总数读入成员变量n中
        int i=0;
        for(; i<n; ++i) {
            //TODO: 将false增加到isVisited数组：表示顶点i没有访问过
            vector<int> row;  //邻接矩阵的一行
            int j=0;
            for(; j<n; ++j) {
                int edge;
                //TODO：将[i,j]的边信息（0或1）读入变量edge中
                //TODO：将edge增加到row的末尾
            }
            //TODO：将当前行row增加到adjMat的末尾
        }
        //printAdjMat(); 调试一下，if 上述读入代码有误
    }
    void update(queue<int>& my_queue, int rootNo) {
    //更新队列my_queue（存放所有待打印结点），即
    //将rootNo的所有相邻顶点（没有访问过），按索引号从小到大顺序
    //进入my_queue队列
        int j=0;
        for(; j<n; ++j) {
            //TODO: 若顶点j已访问过，则pass
            //TODO: 若顶点rootNo和j之间没有边，则pass
            //TODO： 设置顶点j已经访问过。提示：设置isVisited数组
            //TODO： 将顶点j增加到队列my_queue最后
        }
    }
    void bfs(int startNo = 0) {
        //TODO：设置顶点startNo已经访问过
        //声明队列my_queue: 存放所有待打印的顶点
        //注意：my_queue中的元素（顶点索引）k
        // 满足这个条件：isVisited[k]=true ---- !!!!
        queue<int> my_queue;
        //TODO: 将startNo增加到my_queue之中
        /////////////////////////////////////////////
        //BFS 主算法
        while (!my_queue.empty()) {
            int root; //声明待打印顶点索引变量
            //TODO: 从队列my_queue队首取出
            // 1个元素，并存入root变量
            //TODO：从弹出my_queue队首的第1个元素
            //TODO：打印root，并加一个空格
            //TODO：以my_queue，root为参数调用update方法
        }
        //TODO：打印一个回车
    }
    void main() {
    //BSF入口点
        readAdjMat(); //读邻接矩阵
        bfs();        //做BFS遍历
    }
};
int main() {
    int t;
    cin >> t;
    while(t--) {
        Graph g;
        g.main();       //调用Graph对象的入口点
    }
    return 0;
}
输入
第一行输入t，表示有t个测试实例

第二行输入n，表示第1个图有n个结点

第三行起，每行输入邻接矩阵的一行，以此类推输入n行

第i个结点与其他结点如果相连则为1，无连接则为0，数据之间用空格隔开

以此类推输入下一个示例

输出
每行输出一个图的广度优先搜索结果，结点编号之间用空格隔开

样例输入
2
4
0 0 1 1
0 0 1 1
1 1 0 1
1 1 1 0
5
0 0 0 1 1
0 0 1 0 0
0 1 0 1 1
1 0 1 0 0
1 0 1 0 0
样例输出
0 2 3 1 
0 3 4 2 1 
提示

*/

#include <iostream>
#include <queue>

using namespace std;

class Graph
{
    int count, **arr;
    bool *vis;
    queue<int> q;
    void BFS(int v);

public:
    Graph();
    ~Graph();
    void bfs();
};

Graph::Graph()
{
    cin >> count;
    arr = new int *[count];
    vis = new bool[count];
    for (int i = 0; i < count; i++)
    {
        vis[i] = false;
        arr[i] = new int[count];
        for (int j = 0; j < count; j++)
            cin >> arr[i][j];
    }
}

Graph::~Graph()
{
    delete vis;
    for (int i = 0; i < count; i++)
        delete arr[i];
    delete[] arr;
}

void Graph::BFS(int v)
{
    if (!vis[v])
    {
        cout << v << ' ';
        vis[v] = true;
        for (int i = 0; i < count; i++)
        {
            if (arr[v][i] == 1)
                q.push(i);
        }

        while (!q.empty())
        {
            BFS(q.front());
            if (!q.empty())
                q.pop();
        }
    }
}

void Graph::bfs()
{
    for (int i = 0; i < count; i++)
        BFS(i);
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Graph g;
        g.bfs();
    }

    return 0;
}
