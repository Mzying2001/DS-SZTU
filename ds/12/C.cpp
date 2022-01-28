/*
问题 C: 图的最短路径-STL版
时间限制: 1 Sec  内存限制: 128 MB
提交: 116  解决: 80
[提交][状态][讨论版]
题目描述
给出一个图的邻接矩阵，输入顶点v，用迪杰斯特拉算法求顶点v到其它顶点的最短路径。

/////////////////////////////////////////////////////////////////////////////////////////////////////////

基本STL的用法：


class Vertex {
public:
    int indexNo;
    string label;
    int distance;
    bool isVisited;
};
void foo() {
    vector<Vertex> v;
    Vertex& x = v[1];      //引用组数v的第1个元素，注意此处的引用&的用法
    x.isVisited = 10;      //修改组数v的第1个元素的isVisited属性值=10
    x.label = "V0";        //修改组数v的第1个元素的label属性值="V0"
}


/////////////////////////////////////////////////////////////////////////////////////
// 代码框架
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//定义无穷大距离
#define MAX_DIS 0x7FFFFF

class Vertex {
public:
    int indexNo;   //顶点索引号：顶点位于顶点数组的下标取值[0,n)
    string label;  //顶点的标签
    int distance;  //顶点到源点的距离
    bool isVisited; //顶点是否已经按Dijkstra算法处理过（不用再处理了）
    vector<int> path; //顶点到源点的路径

    Vertex(int indexNo, const string& label="", int distance=MAX_DIS) {
        this->label = label;
        this->distance = distance;

        this->indexNo = indexNo;
        this->isVisited = false;
    }
    void updatePath(const vector<int>& prePath) {
        this->path = prePath;   //复制源结点到前一个结点的路径
                                //TODO: 增加本结点到路径数组this->path中
    }

    //打印输出本结点信息
    //输入：顶点数组（供查询用）、源结点索引号（顶点数组下标）
    void displayPath(vector<Vertex>& vertexes, int sourceNo) {

        //0-1-5----[0 1 ]
        cout << vertexes[sourceNo].label; //0
        cout << "-";
        cout << this->label; //1

        cout << "-";
        if (this->distance >= MAX_DIS) {
                                    //TODO: 如果源结点到本结点距离无穷大，则（按题目要求）输出-1
            return;
        }
        cout << this->distance; //5
        cout << "----";

        cout << "[";
        int i=0;
        int size = this->path.size();
        for(; i<size; ++i) {
                                    //TODO: 如果源结点到本结点距离<无穷大，则（按题目要求）输出标签和空格
        }
        cout << "]";
        cout << endl;
    }
};

//打印顶点信息，供调试用
ostream& operator<<(ostream& out, const Vertex& v) {
    out << v.indexNo << "_" << v.label << ": " << v.distance << " ";
    return out;
}

/////////////////////////////////////////////////////
class Graph {
public:
    vector<Vertex> vertexes; //顶点数组：存放顶点信息
    vector<vector<int> > adjMat;  //邻接矩阵：存放每对结点距离，若1对结点i,j之间无边相连，则adjMat[i,j]=0
public:

    void printVertexes() {  //用于调试
        int i=0;
        int n = vertexes.size();
        for(; i<n; ++i) {
            cout << vertexes[i];
        }
        cout << endl;
    }

    int getNo(string& label) {
        //TODO： 遍历顶点数组vertexes，找到标签属性=label的顶点索引号
        //并返回。
        int i=0;
        //int n = vertexes.size();


    }
    void readVertexes() {
    //读入每个顶点信息
        int n;
        cin >> n;

        int indexNo=0;
        for(; indexNo<n; ++indexNo) {
            string label;
            //TODO： 读入标签到label变量

            //Vertex(int indexNo, const string& label="", int distance=MAX_DIS)
            //TODO： 创建顶点对象v

            this->vertexes.push_back(v);  //把v加入顶点数组
        }

    }
    void readAdjMat() {
    //读取距离矩阵，并存放成员变量adjMat
        int n = this->vertexes.size();

        int i=0;
        for(; i<n; ++i) {

            vector<int> row;  //创建矩阵的一行对象row
            int j=0;
            for(; j<n; ++j) {
                int dis;
                //TODO: 读取输入的顶点i,j之间的距离，存入变量dis
                //TODO: 将dis插入row
            }

            //TODO: 将矩阵的一行row附加到邻接矩阵adjMat中

        }
    }

    void update(int rootNo) {
    //将顶点rootNo选入visited集合之后，
    //更新与rootNo关联的所有结点（未访问）：到源点的距离、路径信息
        int i=0;
        int n = vertexes.size();

        Vertex& root = vertexes[rootNo];   //获取rootNo对应顶点对象，便于下面代码写作
        int rootDis = root.distance;

        for(; i<n; ++i) {
            Vertex& v = vertexes[i]; //获取当前顶点对象，便于下面代码写作

            if (v.isVisited)
                //TODO:  如果v已经访问过，则pass

            // TODO: 如果rootNo到i 之间没有边，则pass


            //计算顶点i：到源点的新距离
            int newDis = rootDis + this->adjMat[rootNo][i];
            if (newDis < v.distance) {
                v.distance = newDis;  //更新顶点i的距离信息

                //TODO: 更新顶点i的路径信息， 提示：调用v对象的一个方法
            }
        }
    }

    int select() {
    //从未曾访问的顶点集合中，选择距离源点最短的顶点（其索引号为minNo）
    //返回 minNo
        int minDis = MAX_DIS;
        int minNo = -1;

        int i=0;
        int n = vertexes.size();
        for(; i<n; ++i) {
            Vertex& v = vertexes[i];

            //TODO：如果顶点i已经访问过，则pass

            if (v.distance < minDis) {
                //TODO：记录顶点i的距离和编号到minDis、minNo中

            }
        }

        //TODO：检查minNo是否为-1,
        //若是，则返回-1

        //获得有效的顶点编号
        vertexes[minNo].isVisited = true;
        return minNo;
    }

    void readSourceNo() {
    //从输入读取源结点标签，执行Dijikstra算法

        /////////////////////////////////////////////
        //1）读取源点
        string slabel;
        cin >> slabel;

        int sourceNo;  //源结点索引
        //TODO： 调用一个Graph的成员函数返回标签=slabel的顶点索引号
        //并将编号存入sourceNo

        /////////////////////////////////////////////
        //2） 初始化源点
        Vertex& source = vertexes[sourceNo];  //获取源点对象source，便于下面代码写作
        //TODO：设置source的isVisited为true
        //TODO：设置source到源点的距离为0
        //TODO: 设置source到源点的路径为[sourceNo]

        //TODO: 以sourceNo为参数调用update成员函数

        //////////////////////////////////////////////
        //3）Dikstra主算法
        int i=0;
        int n = vertexes.size();
        for(; i<(n-1); ++i) {

            int v;  //当前未访问过的顶点集合中，距离源点的距离最短的顶点索引号为v

            //TODO：调用select方法，并将返回值存入v

            //TODO: v=-1，则退出for循环

            //TODO:将v作为参数，调用update方法
        }

        /////////////////////////////////////////////
        // 4）打印除源点外的其它顶点信息（按顶点索引号顺序打印）
        string sourceLabel = source.label;
        for(i=0; i<n; ++i) {
            //TODO：如果i=sourceNo，则pass

            Vertex& v = vertexes[i];  //获取当前顶点对象v，便于下述代码写作
            //TODO：调用v的一个方法，打印输出源点到顶点v的距离、路径
        }
    }

    void main() {
        readVertexes();  //读取顶点数组
        readAdjMat();    //读取距离矩阵
        readSourceNo();  //读取源点、并执行Dijkstra算法
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
第一行输入t，表示有t个测试实例

第二行输入顶点数n和n个顶点信息

第三行起，每行输入邻接矩阵的一行，以此类推输入n行

第i个结点与其它结点如果相连则为距离，无连接则为0，数据之间用空格

隔开。第四行输入v0，表示求v0到其他顶点的最短路径距离

以此类推输入下一个示例

输出
对每组测试数据，输出：

每行输出v0到某个顶点的最短距离和最短路径

每行格式：v0编号-其他顶点编号-最短路径值----[最短路径]。没有路径输出：v0编号-其他顶点编号--1。具体请参考示范数据

样例输入
2
5 0 1 2 3 4
0 5 0 7 15
0 0 5 0 0
0 0 0 0 1
0 0 2 0 0
0 0 0 0 0
0
6 V0 V1 V2 V3 V4 V5
0 0 10 0 30 100
0 0 5 0 0 0
0 0 0 50 0 0
0 0 0 0 0 10
0 0 0 20 0 60
0 0 0 0 0 0
V0
样例输出
0-1-5----[0 1 ]
0-2-9----[0 3 2 ]
0-3-7----[0 3 ]
0-4-10----[0 3 2 4 ]
V0-V1--1
V0-V2-10----[V0 V2 ]
V0-V3-50----[V0 V4 V3 ]
V0-V4-30----[V0 V4 ]
V0-V5-60----[V0 V4 V3 V5 ]
提示

*/

#include <iostream>
#include <string>

#define MAX int(1e9)
using namespace std;

class Graph
{
private:
    int count, **matrix;
    string *names, *paths, start;

public:
    Graph()
    {
        cin >> count;
        names = new string[count];
        paths = new string[count];

        for (int i = 0; i < count; i++)
        {
            cin >> names[i];
            matrix = new int *[count];
        }

        for (int i = 0; i < count; i++)
        {
            matrix[i] = new int[count];
            for (int j = 0; j < count; j++)
            {
                cin >> matrix[i][j];
                if (matrix[i][j] == 0)
                    matrix[i][j] = MAX;
            }
        }

        cin >> start;
    }

    int indexOf(string a)
    {
        for (int i = 0; i < count; i++)
            if (a == names[i])
                return i;
        return -1;
    }

    void dijkstra()
    {
        int i, j, Current, min;
        bool *final = new bool[count];
        int *dest = new int[count];
        int index = indexOf(start);

        for (int i = 0; i < count; i++)
        {
            paths[i] = start + " ";
            dest[i] = matrix[index][i];
            final[i] = false;
        }

        dest[index] = 0;
        final[index] = true;
        for (i = 0; i < count - 1; i++)
        {
            min = MAX;
            Current = -1;
            for (j = 0; j < count; j++)
            {
                if (final[j] == false && min > dest[j])
                {
                    Current = j;
                    min = dest[j];
                }
            }
            if (Current != -1)
            {
                final[Current] = true;
                paths[Current] += names[Current] + " ";
                for (int q = 0; q < count; q++)
                {
                    if (final[q] == false && min + matrix[Current][q] < dest[q])
                    {
                        dest[q] = min + matrix[Current][q];
                        paths[q] = paths[Current];
                    }
                }
            }
        }

        for (int i = 1; i < count; i++)
        {
            cout << names[0] << "-" << names[i];
            if (dest[i] >= MAX)
            {
                cout << "--1" << endl;
                continue;
            }
            cout << "-" << dest[i] << "----[" << paths[i] << "]" << endl;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Graph g;
        g.dijkstra();
    }
    return 0;
}
