/*题目描述
输入两个整数,找到两个整数之间(包括这两个整数)约数最多的数以及约数的数量

例:

9-12之间约数最多的是12，有6个约数
11-18之间约束最多的是12,18，有6个约数，取较大值18

输入
两个整数X1,X2,(1 <= X1 < X2 <= 1000)

输出
约束最多的数及其约数的数量，用空格隔开，如果有多个最大约数的数，输出最大的那个数字

样例输入 Copy
1 12
11 18
100 1000
样例输出 Copy
12 6
18 6
840 32*/

#include<iostream>
using namespace std;
int main()
{
    int x1, x2;
    while (cin >> x1 >> x2) {
        int biggest = 0, max = 0;

        for (int i = x1; i <= x2; i++) {
            int a = 0;
            for (int j = 1; j <= i; j++) {
                if (i % j == 0)a++;
            }
            if (a >= max)biggest = i, max = a;
        }
        cout << biggest << " " << max << endl;
    }
    system("pause");
    return 0;
}