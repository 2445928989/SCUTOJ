/*题目描述
小雪编写了递归函数int f(int n)来计算斐波那契数列a[n]=a[n-1]+a[n-2]，a[1]=a[2]=1，但是小雪还想搞清楚计算时函数递归调用的顺序，于是考虑将函数f的声明修改为int f(int n, int m)，其中形参m是用来标注当前调用层级的，在main函数中调用f时传递给m的值应为0，在f函数中递归调用f时传递给m的值应为当前的m值加一。为了展示出调用顺序，小雪打算在每次刚进入函数f时在函数中打印出m个’-‘字符，紧接着打印出字符串“f(n)”，字符串内的n为其当前取值，然后换行。在main函数中得到函数f返回的斐波那契数列计算结果后，还要将其打印出来。请尝试实现小雪的想法。
输入
多组输入，每行一个整数n
输出
按题目描述输出计算斐波那契数列第n个数a[n]的函数调用顺序，并输出a[n]的值
样例输入 Copy
1
2
5
样例输出 Copy
f(1)
1
f(2)
1
f(5)
-f(4)
--f(3)
---f(2)
---f(1)
--f(2)
-f(3)
--f(2)
--f(1)
5*/

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int fun(int m, int n) {
    for (int i = 0; i < m; i++)cout << "-";
    cout << "f(" << n << ")" << endl;
    if (n == 1 || n == 2)return 1;
    else return fun(m + 1, n - 1) + fun(m + 1, n - 2);
}
int n;
int main()
{
    while (cin >> n) {
        cout << fun(0, n) << endl;
    }
}
