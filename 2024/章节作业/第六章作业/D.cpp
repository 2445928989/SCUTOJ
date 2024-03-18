/*题目描述
定义一个表示点的结构类型 Point 和一个由直线方程y=ax十b确定的直线类 Line。 结构类型 Point有两个成员x和y，分别表示点的横坐标和纵坐标。Line 类有两个数据成员a和b，分别表示直线方程中的系教。Line 类有一个成员函数 print 用于显示直线方程。友元函数 setPoint(Line &l1,Line &l2)用于求两条直线的交点。在 main 两数中，建立两个直线对象，分别调用 print 函数显示两条直线的方程，并调用函数 setPoint求这两条直线的交点。
输入
两条直线的斜率和截距
输出
两条直线的方程和交点

其中括号和逗号都是英文

样例输入 Copy
5 1
1 5
样例输出 Copy
y = 5x + 1
y = 1x + 5
(1,6)*/
#include <iostream>
#include <string>
using namespace std;
struct Point
{
    double x;
    double y;
};
class Line
{
    void friend setPoint(Line &l1, Line &l2);

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
void setPoint(Line &l1, Line &l2)
{
    Point p;
    p.x = (l2.b - l1.b) / (l1.a - l2.a);
    p.y = l1.a * p.x + l1.b;
    cout << "(" << p.x << "," << p.y << ")\n";
}
int main()
{
    double a, b, c, d;
    Line l1, l2;
    while (cin >> a >> b >> c >> d)
    {
        l1.setLine(a, b);
        l2.setLine(c, d);
        l1.print();
        l2.print();
        setPoint(l1, l2);
    }
    system("pause");
}