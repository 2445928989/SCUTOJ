/*题目描述
改写第8章习题中程序设计第2题的程序，把 Shape 类定义为抽象类，提供有共同操作界面的纯虚函数。TwoDimShape 类和 ThreeDimShape 类仍然是抽象类，只有第三层具体类才提供全部函数的实现。在测试函数中使用基类指针实现不同派生类对象的操作。
最后通过以下形式的main函数测试代码：
int main() {
    Shape* c = new Circle(3);
    c->show_name();
    c->calculate();
    c->show_area();
    c->show_volume();
    delete c;

    Shape* s = new Rectangle(5, 6);
    s->show_name();
    s->calculate();
    s->show_area();
    s->show_volume();
    delete s;

    Shape* b = new Ball(2);
    b->show_name();
    b->calculate();
    b->show_area();
    b->show_volume();
    delete b;

    Shape* cu = new Rectangular(7, 8, 9);
    cu->show_name();
    cu->calculate();
    cu->show_area();
    cu->show_volume();
    delete cu;

    return 0;
}
输出
main函数中的四种形状中，二维图形的面积，三维图像的面积和体积，如下：

必须使用的关键字
class
样例输出 Copy
Circle
Radius: 3
Area: 28.26
Rectangle
Length: 5, Width: 6
Area: 30
Ball
Radius: 2
Surface Area: 50.24
Volume: 33.4933
Rectangular
Length: 7, Width: 8, Height: 9
Surface Area: 382
Volume: 504
提示
注意圆周率使用3.14*/

#include <iostream>
using namespace std;
const double PI = 3.14;
class Shape
{
protected:
    double volumn;
    double area;

public:
    virtual void show_name() = 0;
    virtual void calculate() = 0;
    virtual void show_area() = 0;
    virtual void show_volume() = 0;
};
class Circle : public Shape
{
private:
    double r;

public:
    virtual void show_name()
    {
        cout << "Circle\nRadius: " << r << endl;
    }
    virtual void calculate()
    {
        area = r * r * PI;
    }
    virtual void show_area()
    {
        cout << "Area: " << area << endl;
    };
    virtual void show_volume()
    {
    }
    Circle(double x)
    {
        r = x;
    }
};
class Rectangle : public Shape
{
private:
    double a, b;

public:
    virtual void show_name()
    {
        cout << "Rectangle\nLength: " << a << ", Width: " << b << endl;
    }
    virtual void calculate()
    {
        area = a * b;
    }
    virtual void show_area()
    {
        cout << "Area: " << area << endl;
    };
    virtual void show_volume()
    {
    }
    Rectangle(double x, double y)
    {
        a = x;
        b = y;
    }
};
class Ball : public Shape
{
private:
    double r;

public:
    virtual void show_name()
    {
        cout << "Ball\nRadius: " << r << endl;
    }
    virtual void calculate()
    {
        area = r * r * PI * 4;
        volumn = 4.0 / 3 * PI * r * r * r;
    }
    virtual void show_area()
    {
        cout << "Surface Area: " << area << endl;
    };
    virtual void show_volume()
    {
        cout << "Volume: " << volumn << endl;
    }
    Ball(double x)
    {
        r = x;
    }
};
class Rectangular : public Shape
{
private:
    double a, b, c;

public:
    virtual void show_name()
    {
        cout << "Rectangular\nLength: " << a << ", Width: " << b << ", Height: " << c << endl;
    }
    virtual void calculate()
    {
        area = (a * b + b * c + c * a) * 2;
        volumn = a * b * c;
    }
    virtual void show_area()
    {
        cout << "Surface Area: " << area << endl;
    };
    virtual void show_volume()
    {
        cout << "Volume: " << volumn << endl;
    }
    Rectangular(double x, double y, double z)
    {
        a = x;
        b = y;
        c = z;
    }
};
int main()
{
    Shape *c = new Circle(3);
    c->show_name();
    c->calculate();
    c->show_area();
    c->show_volume();
    delete c;

    Shape *s = new Rectangle(5, 6);
    s->show_name();
    s->calculate();
    s->show_area();
    s->show_volume();
    delete s;

    Shape *b = new Ball(2);
    b->show_name();
    b->calculate();
    b->show_area();
    b->show_volume();
    delete b;

    Shape *cu = new Rectangular(7, 8, 9);
    cu->show_name();
    cu->calculate();
    cu->show_area();
    cu->show_volume();
    delete cu;

    return 0;
}