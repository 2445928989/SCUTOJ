/*题目描述
输入三个整数，按从小到大的顺序输出它们的值，输出结果用一个空格间隔
输入
三个整数a, b, c
输出
从小到大排列
a b c
样例输入 Copy
2 5 0
-1 5 3
-20 33 15
样例输出 Copy
0 2 5
-1 3 5
-20 15 33*/

#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{   
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a > b && a > c) {
            if (b > c) {
                printf("%d %d %d\n", c, b, a);
            }
            else {
                printf("%d %d %d\n", b, c, a);
            }
        }
        else if (b > c && b > a) {
            if (a > c) {
                printf("%d %d %d\n", c, a, b);
            }
            else {
                printf("%d %d %d\n", a, c, b);
            }
        }
        else if (c > a && c > b) {
            if (b > a) {
                printf("%d %d %d\n",a , b, c);
            }
            else {
                printf("%d %d %d\n", b, a, c);
            }
        }
        else {
            if (a < b) {
                printf("%d %d %d\n", a, c, b);
            }
            else if (b < a) {
                printf("%d %d %d\n", b, c, a);
            }
            else if (c < a) {
                printf("%d %d %d\n", c, b, a);
            }
            else {
                printf("%d %d %d\n", a, b, c);
            }
        }
    }
    system("pause");
    return 0;
}
