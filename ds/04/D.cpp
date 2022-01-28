/*
问题 D: DS堆栈--迷宫求解
时间限制: 1 Sec  内存限制: 128 MB
提交: 676  解决: 177
[提交][状态][讨论版]
题目描述
给出一个N*N的迷宫矩阵示意图，从起点[0,0]出发，寻找路径到达终点[N-1, N-1]

要求使用堆栈对象来实现，具体算法参考课本3.2.4节51页

输入
第一行输入t，表示有t个迷宫

第二行输入n，表示第一个迷宫有n行n列

第三行起，输入迷宫每一行的每个方格的状态，0表示可通过，1表示不可通过

输入n行

以此类推输入下一个迷宫

输出
逐个输出迷宫的路径

如果迷宫不存在路径，则输出no path并回车

如果迷宫存在路径，将路径中每个方格的x和y坐标输出，从起点到终点，每输出四个方格就换行，最终以单词END结尾，具体格式参考示范数据

输出的代码参考如下：

//path是保存路径的堆栈，堆栈中每个元素都包含x坐标和y坐标，用属性xp和yp表示

//path1是一个临时堆栈，把path的数据倒序输出到path1，使得路径按正序输出

	if (!path.empty())	//找到路径

	{	//......若干代码，实现path的数据导入path1

		i=0;  //以下是输出路径的代码

		while (!path1.empty())

		{	cpos = path1.top();

			if ( (++i)%4 == 0 ) 

				cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--"<<endl;

			else

				cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--";

			path1.pop();

		}

		cout<<"END"<<endl;

	}

	else

		cout<<"no path"<<endl; //找不到路径输出no path

样例输入
2
8
0 0 0 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 0 1 0 0 0
1 1 0 0 0 0 0 1
0 0 1 1 0 1 1 0
0 0 0 0 0 0 1 1
1 1 1 1 1 0 0 1
0 0 0 0 1 0 0 0
7
0 0 0 1 1 1 1
1 0 0 1 0 0 1
1 0 0 1 0 0 0
1 1 0 0 0 0 1
0 0 1 1 0 1 0
1 0 0 0 0 1 0
0 0 0 0 1 1 0
样例输出
[0,0]--[0,1]--[0,2]--[1,2]--
[1,3]--[2,3]--[3,3]--[3,4]--
[4,4]--[5,4]--[5,5]--[6,5]--
[6,6]--[7,6]--[7,7]--END
no path
提示
*/

#include <iostream>
#include <stack>

#define MAXN 128

int matrix[MAXN][MAXN];

enum STATUS
{
    OK = 0,
    NO = 1
};

enum DIRECTION
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

struct step
{
    int i, j;
    DIRECTION dir;

    step(int i, int j, DIRECTION dir = RIGHT)
    {
        this->i = i;
        this->j = j;
        this->dir = dir;
    }
};

inline void get_matrix(int n)
{
    for (int i = 0; i < MAXN; ++i)
    {
        for (int j = 0; j < MAXN; ++j)
            matrix[i][j] = NO;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            std::cin >> matrix[i][j];
    }
}

void print_path(std::stack<step> &path)
{
    if (path.empty())
        std::cout << "no path" << std::endl;
    else
    {
        int i = 0;
        while (!path.empty())
        {
            step &s = path.top();
            std::cout << '[' << s.i - 1 << ',' << s.j - 1 << "]--";
            if (++i % 4 == 0)
                std::cout << std::endl;
            path.pop();
        }
        std::cout << "END" << std::endl;
    }
}

int main()
{
    int t, n;
    std::cin >> t;

    while (t--)
    {
        std::cin >> n;
        get_matrix(n);

        if (matrix[1][1] == NO)
        {
            std::cout << "no path" << std::endl;
            continue;
        }

        std::stack<step> path;
        path.push(step(1, 1));

        while (!path.empty())
        {
            step &s = path.top();
            matrix[s.i][s.j] = NO;

            if (s.i == n && s.j == n)
                break;

            switch (s.dir)
            {
            case RIGHT:
            {
                if (matrix[s.i][s.j + 1] == OK)
                    path.push(step(s.i, s.j + 1));
                else
                    s.dir = DOWN;
            }
            break;

            case DOWN:
            {
                if (matrix[s.i + 1][s.j] == OK)
                    path.push(step(s.i + 1, s.j));
                else
                    s.dir = LEFT;
            }
            break;

            case LEFT:
            {
                if (matrix[s.i][s.j - 1] == OK)
                    path.push(step(s.i, s.j - 1));
                else
                    s.dir = UP;
            }
            break;

            case UP:
            {
                if (matrix[s.i - 1][s.j] == OK)
                    path.push(step(s.i - 1, s.j));
                else
                    path.pop();
            }
            break;
            }
        }

        std::stack<step> reverse;
        while (!path.empty())
        {
            reverse.push(path.top());
            path.pop();
        }

        print_path(reverse);
    }

    return 0;
}