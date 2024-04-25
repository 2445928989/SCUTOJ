/*题目描述
为Complex类重载 == 、 != 、一元减(-)、>>操作符，复数的判等操作定义为：复数z1=a+bi等于z2=c+di，当且仅当a等于c且b等于d。复数求负的操作定义为：如果z=a+bi是一个复数, -z为-a-bi。为Complex类重载右移操作符>>以输出数据。
class Complex
{ public:
    // TODO: 重载 ==
    // TODO: 重载 !=
    // TODO: 重载 -
    // TODO: 重载 >>

  private:
      double  Real, Image ;
};

测试函数：
int main()
{
    double r, i;
    cin >> r >> i;
    Complex c1(r, i);
    Complex c;
    c = -c1;
    cout >> c << endl;
    cout << (c1 != c) << endl;
    cout << (c1 == c) << endl;
}

输入
复数的实部和虚部
输出
详见测试函数
必须使用的关键字
class operator
样例输入 Copy
2.1 3.4
样例输出 Copy
(-2.1 + -3.4i)
1
0
提示
不需要循环输入*/
#include <iostream>
#include <string>
using namespace std;
class Complex
{
public:
    // TODO: 重载 ==
    // TODO: 重载 !=
    // TODO: 重载 -
    // TODO: 重载 >>
    Complex() {}
    Complex(double a, double b)
    {
        Real = a;
        Image = b;
    }
    bool operator==(Complex other)
    {
        return (Real == other.Real && Image == other.Image);
    }
    bool operator!=(Complex other)
    {
        return !(*this == other);
    }
    friend ostream &operator>>(ostream &cout, Complex A)
    {
        cout << "(" << A.Real << " + " << A.Image << "i)";
        return cout;
    }
    Complex operator-()
    {
        Complex t(-Real, -Image);
        return t;
    }

private:
    double Real, Image;
};

int main()
{
    double r, i;
    cin >> r >> i;
    Complex c1(r, i);
    Complex c;
    c = -c1;
    cout >> c << endl;
    cout << (c1 != c) << endl;
    cout << (c1 == c) << endl;
    system("pause");
}
