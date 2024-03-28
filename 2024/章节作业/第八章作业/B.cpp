/*题目描述
试写出你所能想到的所有形状(包括二维的和三维的)，生成一个形状层次类体系。生成的类体系以 shape 作为基类，并由此派生出 TwoDimShape 类和 ThreeDimShape 类。它们的派生类是不同的形状类。定义类体系中的每个类，并用main 函数进行测试。
注：题目中的形状包括：三角形、正方形、正方体、球。
给出main函数如下：
int main() {
    double a, b, c, d, e;

    cout << "Please enter the height and base of the triangle:" << endl;

    cin >> a >> b;
    Triangle t(a, b);
    double area;
    area = t.area();
    t.display();
    cout << area << endl;

    cout << "Please enter the side length of the square:" << endl;
    cin >> c;
    Square s(c);
    area = s.area();
    s.display();
    cout << area << endl;

    cout << "Please enter the side length of the cube:" << endl;
    cin >> d;
    Squarer sr(d);
    area = sr.area();
    sr.display();
    cout << area << endl;

    cout << "Please enter the radius of the ball:" << endl;
    cin >> e;
    Ball br(e);
    area = br.area();
    br.display();
    cout << area << endl;

    return 0;
}
输入
依次是：三角形的高和底、正方形的边长、正方体的边长、球的半径
输出
依次输出上述形状的面积和体积，示例输出如下：
样例输入 Copy
2 4
5.2
2.2
2.5
样例输出 Copy
Please enter the height and base of the triangle:
Area of Triangle is4
Please enter the side length of the square:
Area of Square is27.04
Please enter the side length of the cube:
Superficial area of Cube is10.648
Please enter the radius of the ball:
Superficial area of Ball is65.4167*/
#include <iostream>
using namespace std;
class shape
{
public:
};
class TwoDimShape : public shape
{
public:
};
class ThreeDimShape : public shape
{
public:
};
class Triangle : public TwoDimShape // 三角形
{
public:
    double a, b;
    Triangle(double x, double y)
    {
        a = x, b = y;
    }
    double area()
    {
        return a * b / 2.0;
    }
    void display()
    {
        cout << "Area of Triangle is";
    }
};
class Square : public TwoDimShape // 正方形
{
public:
    double a;
    Square(double x)
    {
        a = x;
    }
    double area()
    {
        return a * a;
    }
    void display()
    {
        cout << "Area of Square is";
    }
};
class Squarer : public ThreeDimShape // 正方体
{
public:
    double a;
    Squarer(double x)
    {
        a = x;
    }
    double area()
    {
        return a * a * a;
    }
    void display()
    {
        cout << "Superficial area of Cube is";
    }
};
class Ball : public ThreeDimShape // 球体
{
public:
    double r;
    const double pi = 3.14;
    Ball(double x)
    {
        r = x;
    }
    double area()
    {
        return 4.0 / 3.0 * pi * r * r * r;
    }
    void display()
    {
        cout << "Superficial area of Ball is";
    }
};

int main()
{
    double a, b, c, d, e;

    cout << "Please enter the height and base of the triangle:" << endl;

    cin >> a >> b;
    Triangle t(a, b);
    double area;
    area = t.area();
    t.display();
    cout << area << endl;

    cout << "Please enter the side length of the square:" << endl;
    cin >> c;
    Square s(c);
    area = s.area();
    s.display();
    cout << area << endl;

    cout << "Please enter the side length of the cube:" << endl;
    cin >> d;
    Squarer sr(d);
    area = sr.area();
    sr.display();
    cout << area << endl;

    cout << "Please enter the radius of the ball:" << endl;
    cin >> e;
    Ball br(e);
    area = br.area();
    br.display();
    cout << area << endl;

    return 0;
}