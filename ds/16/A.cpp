/*
问题 A: 基数排序（内部排序）
时间限制: 1 Sec  内存限制: 128 MB
提交: 103  解决: 87
[提交][状态][讨论版]
题目描述
给定一组数据，对其进行基数升序排序。

输入
测试次数t

每组测试数据一行：数字个数n，后跟n个数字（整数）

注：如果序列中有负数，则每个数字加上最小负数的绝对值，使序列中的数均大于等于0。排序后再减去最小负数的绝对值。

输出
对每组测试数据，输出每趟分配、收集的结果。若分配中该位没有数字，输出NULL。具体输出格式见样例。每组测试数据间以空行分隔。

如果序列中有负数，最后输出减去最小负数绝对值的序列值。

样例输入
2
10 278 109 63 930 589 184 505 269 8 83
6 57 0 93 19 18 99
样例输出
0:->930->^
1:NULL
2:NULL
3:->63->83->^
4:->184->^
5:->505->^
6:NULL
7:NULL
8:->278->8->^
9:->109->589->269->^
930 63 83 184 505 278 8 109 589 269
0:->505->8->109->^
1:NULL
2:NULL
3:->930->^
4:NULL
5:NULL
6:->63->269->^
7:->278->^
8:->83->184->589->^
9:NULL
505 8 109 930 63 269 278 83 184 589
0:->8->63->83->^
1:->109->184->^
2:->269->278->^
3:NULL
4:NULL
5:->505->589->^
6:NULL
7:NULL
8:NULL
9:->930->^
8 63 83 109 184 269 278 505 589 930

0:->0->^
1:NULL
2:NULL
3:->93->^
4:NULL
5:NULL
6:NULL
7:->57->^
8:->18->^
9:->19->99->^
0 93 57 18 19 99
0:->0->^
1:->18->19->^
2:NULL
3:NULL
4:NULL
5:->57->^
6:NULL
7:NULL
8:NULL
9:->93->99->^
0 18 19 57 93 99
提示
*/

#include <cstdio>

int **newMatrix(int count)
{
    int **ret = new int *[10];
    for (int i = 0; i < 10; i++)
        ret[i] = new int[count];
    return ret;
}

void delMatrix(int **matrix)
{
    for (int i = 0; i < 10; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void showMatrix(int **matrix, int *matrixItemCount)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d:", i);
        if (matrixItemCount[i])
        {
            for (int j = 0; j < matrixItemCount[i]; j++)
                printf("->%d", matrix[i][j]);
            puts("->^");
        }
        else
        {
            puts("NULL");
        }
    }
}

int arr[1024], len;

void showArr()
{
    for (int i = 0; i < len; i++)
        printf(" %d" + !i, arr[i]);
    putchar('\n');
}

void radixSort()
{
    int **matrix = newMatrix(len);
    int *matrixItemCount = new int[10];
    for (int i = 0; i < 10; i++)
        matrixItemCount[i] = 0;

    int max = -1e9, min = 1e9;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int off = min < 0 ? -min : 0;

    int maxLen = 0;
    for (int tmp = max + off; tmp; tmp /= 10)
        maxLen++;

    for (int k = 0, n = 1; k < maxLen; k++, n *= 10)
    {
        for (int i = 0; i < len; i++)
        {
            int tmp = (arr[i] + off) / n % 10;
            matrix[tmp][matrixItemCount[tmp]++] = (arr[i] + off);
        }

        showMatrix(matrix, matrixItemCount);

        int index = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < matrixItemCount[i]; j++)
                arr[index++] = matrix[i][j] - off;
            matrixItemCount[i] = 0;
        }

        showArr();
    }

    delete matrixItemCount;
    delMatrix(matrix);
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &len);
        for (int i = 0; i < len; i++)
            scanf("%d", arr + i);
        radixSort();
        putchar('\n');
    }

    return 0;
}