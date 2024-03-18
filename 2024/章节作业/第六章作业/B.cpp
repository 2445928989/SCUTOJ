/*题目描述
定义一个Box（盒子）类，在该类定义中包括以下数据成员和成员函数。
数据成员：length（长)、width（宽）和height （高）。
成员函数：构造函数 Box，设置盒子的长、宽和高三个初始数据；成员函数setBox 对数据成员置值；成员函数 volume 计算盒子的体积。
在main函数中，要求创建 Box对象，输入长、宽、高，输出盒子的体积。
输入
盒子的长宽高
输出
盒子的体积，具体格式样例如下

样例输入 Copy
1 5 3
4 5 5
3 4 2
样例输出 Copy
15
100
24*/

#include <iostream>
#include <string>
using namespace std;
class Box
{
private:
    double length;
    double width;
    double height;

public:
    Box(double a, double b, double c)
    {
        length = a;
        width = b;
        height = c;
    }
    void setBox(double a, double b, double c)
    {
        length = a;
        width = b;
        height = c;
    }
    double volume()
    {
        return length * width * height;
    }
};
double a, b, c;
int main()
{
    Box b1(0, 0, 0);
    while (cin >> a >> b >> c)
    {
        b1.setBox(a, b, c);
        cout << b1.volume() << endl;
    }
    system("pause");
}