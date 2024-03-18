/*题目描述
用类成员结构修改第4 题的程序，使其实现相同的功能。定义Point 类和 Line 类，表示点和线；定义setPoint 类，包含两个 Line 类成员和一个表示直线交点的Point 成员，并定义类中求直线交点的成员函数。编写每个类相应的成员函数和测试用的主函数。
输入
两条直线的斜率和截距
输出
两条直线的方程和交点

其中括号和逗号都是英文

样例输入 Copy
5 1
8 9
样例输出 Copy
y = 5x + 1
y = 8x + 9
(-2.66667, -12.3333)*/
#include <iostream>
#include <string>
using namespace std;
class Point
{
    friend class setPoint;

private:
    double x;
    double y;
};
class Line
{
    friend class setPoint;

private:
    double a;
    double b;

public:
    void setLine(double a1, double b1)
    {
        a = a1;
        b = b1;
    }
    void print()
    {
        cout << "y = " << a << "x + " << b << endl;
    }
};
class setPoint
{
private:
    Line l1;
    Line l2;
    Point p;

public:
    void setp(double a, double b, double c, double d)
    {
        l1.setLine(a, b);
        l2.setLine(c, d);
        l1.print();
        l2.print();
    }
    void printp()
    {
        p.x = (l2.b - l1.b) / (l1.a - l2.a);
        p.y = l1.a * p.x + l1.b;
        cout << "(" << p.x << "," << p.y << ")\n";
    }
};
int main()
{
    double a, b, c, d;
    setPoint sp;
    while (cin >> a >> b >> c >> d)
    {
        sp.setp(a, b, c, d);
        sp.printp();
    }
    system("pause");
}