/*题目描述
以表格形式输出:当x=1°,2°…,10°时，sinx、cosx和 tanx的值。要求:输出时，数据的宽度为10，左对齐，保留小数点后5位。
输入
无
输出
三角函数的值

样例输出 Copy
x sin(x) cos(x) tan(x)
1  : 0.01745   0.99985   0.01746
2  : 0.03490   0.99939   0.03492
3  : 0.05234   0.99863   0.05241
4  : 0.06976   0.99756   0.06993
5  : 0.08716   0.99619   0.08749
6  : 0.10453   0.99452   0.10510
7  : 0.12187   0.99255   0.12278
8  : 0.13917   0.99027   0.14054
9  : 0.15643   0.98769   0.15838
10 : 0.17365   0.98481   0.17633*/
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    double PI = acos(-1);
    cout << "x sin(x) cos(x) tan(x)\n";

    for (int i = 1; i <= 10; i++)
    {

        cout << setw(3) << left << i << ": " << fixed << setprecision(5) << setw(10) << sin(i*PI/ 180) << setprecision(5) << setw(10) << cos(PI * i / 180) << setprecision(5) << setw(10) << tan(PI * i / 180) << endl;
    }
}