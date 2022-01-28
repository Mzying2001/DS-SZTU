/*
问题 B: 扑克排序
时间限制: 1 Sec  内存限制: 128 MB
提交: 58  解决: 35
[提交][状态][讨论版]
题目描述
一叠数值不同的扑克牌（不超过13张），每次只能拿最顶端的一张插入到任意位置。至少操作多少次，扑克牌能够从上到下是从大到小的顺序。

输入
多组数据，每组第一行为n，扑克牌个数。第二行n个空格隔开的正整数，（这些数是1~13），为这叠扑克牌从下到上的数值。

输出
每组数据输出一行，至少按规则操作的次数。

样例输入
3
1 3 2
5
1 3 5 2 6
样例输出
1
2
提示
*/

#include <cstdio>

int main()
{
    // freopen("in.txt", "r", stdin);

    int arr[13], len;
    while (scanf("%d", &len) != EOF)
    {
        for (int i = 0; i < len; i++)
            scanf("%d", arr + i);
        
        int tmp = 1;
        for (int i = 1; i < len; i++)
        {
            if (arr[i] >= arr[i - 1])
                tmp++;
            else
                break;
        }

        printf("%d\n", len - tmp);
    }

    return 0;
}