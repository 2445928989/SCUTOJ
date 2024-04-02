/*题目描述
使用虚函数编写程序，求球体和圆柱体的体积及表面积。由于球体和圆柱体都可以看作由圆继承而来，因此，可以把圆类 Circle 作为基类。在 Circle 类中定义一个数据成员 radius 及两个虚函数 area 和 volume。 由 Circle 类派生 Sphere 类和 Column 类。在派生类中对虚函数 area 和 volume 重新定义，分别求球体和圆柱体的体积及表面积。设计好类以后，请使用以下main函数测试：
int main() {
    circle* p;
    double rsphere;
    double rcolumn, hcolumn;
    cin >> rsphere >> rcolumn >> hcolumn;
    sphere sobj(rsphere);
    p = &sobj;

    cout << "球体:" << endl;
    cout << "体积 = " << p->volume() << endl;
    cout << "表面积 = " << p->area() << endl;

    column cobj(rcolumn, hcolumn);
    p = &cobj;

    cout << "圆柱体：" << endl;
    cout << "体积 = " << p->volume() << endl;
    cout << "表面积 = " << p->area() << endl;

    return 0;
}
输入
球体的半径，圆柱体的半径和高
输出
输出如下，注意圆周率统一取3.14，输出的小数位数不做设置

必须使用的关键字
class
样例输入 Copy
5 5 8
样例输出 Copy
球体:
体积 = 523.333
表面积 = 314
圆柱体：
体积 = 628
表面积 = 408.2*/

#include <iostream>
using namespace std;
const double PI = 3.14;
class circle
{
protected:
    double radius;

public:
    virtual double area() = 0;
    virtual double volume() = 0;
    circle(double r)
    {
        radius = r;
    }
};
class sphere : public circle
{
public:
    sphere(double r) : circle(r) {}
    virtual double area()
    {
        return 4 * PI * radius * radius;
    }
    virtual double volume()
    {
        return 4.0 / 3 * PI * radius * radius * radius;
    }
};
class column : public circle
{
private:
    double height;

public:
    column(double r, double h) : circle(r) { height = h; }
    virtual double area()
    {
        return 2 * PI * radius * radius + 2 * PI * radius * height;
    }
    virtual double volume()
    {
        return PI * radius * radius * height;
    }
};
int main()
{
    circle *p;
    double rsphere;
    double rcolumn, hcolumn;
    cin >> rsphere >> rcolumn >> hcolumn;
    sphere sobj(rsphere);
    p = &sobj;

    cout << "球体:" << endl;
    cout << "体积 = " << p->volume() << endl;
    cout << "表面积 = " << p->area() << endl;

    column cobj(rcolumn, hcolumn);
    p = &cobj;

    cout << "圆柱体：" << endl;
    cout << "体积 = " << p->volume() << endl;
    cout << "表面积 = " << p->area() << endl;

    return 0;
}