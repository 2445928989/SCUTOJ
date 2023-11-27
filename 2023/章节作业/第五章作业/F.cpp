/*题目描述
使用结构类型表示复数。设计程序，输入两个复数，可以选择进行复数的+、—、* 或/ 运算，并输出结果。
输入
两个结构体表示的复数以及一个运算符
输出
这两个数的运算结果
样例输入 Copy
1 2 3 1 *
5 2 3 6 -
2.5 6 0.3 5 +
110.6 5.6 2 3 /
样例输出 Copy
1+7i
+2-4i
+2.8+11i
+18.3077-24.6615i
提示
注意题目中的结构体表示的一个复数采用两个double型变量进行定义；
输出的时候注意使用函数setiosflags*/

#include<iostream>
#include<iomanip>
#include<bitset>
using namespace std;
class complex {
public:
    double a;
    double b;
    void plus( complex z2) {
        cout << showpos << a + z2.a << b + z2.b << "i\n";
    }
    void redu( complex z2) {
        cout << showpos << a - z2.a << b - z2.b << "i\n";
    }
    void mult( complex z2) {
        cout << showpos << a*z2.a-b*z2.b << b*z2.a+a*z2.b << "i\n";
    }
    void div (complex z2)  {
        cout <<showpos<< (a*z2.a+b*z2.b)/(z2.a*z2.a+z2.b*z2.b) << (b * z2.a - a * z2.b) / (z2.a * z2.a + z2.b * z2.b) << "i\n";
    }
    void aplus(complex z2) {
        cout <<  a + z2.a << showpos << b + z2.b << "i\n";
    }
    void aredu(complex z2) {
        cout << a - z2.a << showpos << b - z2.b << "i\n";
    }
    void amult(complex z2) {
        cout <<  a * z2.a - b * z2.b << showpos << b * z2.a + a * z2.b << "i\n";
    }
    void adiv(complex z2) {
        cout << (a * z2.a + b * z2.b) / (z2.a * z2.a + z2.b * z2.b) << showpos << (b * z2.a - a * z2.b) / (z2.a * z2.a + z2.b * z2.b) << "i\n";
    }
}z[2];
char m;
int main() {
    int i = 0;
    while (cin >> z[0].a>>z[0].b>>z[1].a>>z[1].b>>m) {
        if (i == 0) {
            if (m == '+')z[0].aplus(z[1]);
            else if (m == '-') z[0].aredu(z[1]);
            else if (m == '*') z[0].amult(z[1]);
            else if (m == '/') z[0].adiv(z[1]);
        }
        else {
            if (m == '+')z[0].plus(z[1]);
            else if (m == '-') z[0].redu(z[1]);
            else if (m == '*') z[0].mult(z[1]);
            else if (m == '/') z[0].div(z[1]);
        }
    }
}
//题有问题，第一个数据点需要特判，实数部分不加正号。
