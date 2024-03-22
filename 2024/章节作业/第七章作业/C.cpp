/*题目描述
假设有向量 X = ( x1, x2,…, xn)和 Y = ( y1, y2,…, yn )，它们之间的加、减和乘法分别定义为：

X + Y = ( x1 + y1, x2 + y2,…, xn + yn )

X - Y = ( x1 - y1, x2 - y2,…, xn - yn )

X * Y = x1 * y1 + x2 * y2 +…+ xn * yn

编写程序定义向量类 Vector，重载运算符+、-、*和=，实现向量之间的加、减、乘、赋值运算；重载 运算符>>、<<实现向量的输入、输出功能。注意检测运算的合法性。

输入
分别输入向量X、Y的长度，以及X、Y的各个数据元素。

输出
输出X和Y的向量形式、X+Y、X-Y、X*Y的结果。

必须使用的关键字
class
样例输入 Copy
4
1 1 1 1
4
2 2 2 2
3
2 1 0
2
1 1
样例输出 Copy
X=(1,1,1,1)
Y=(2,2,2,2)
X+Y=(3,3,3,3)
X-Y=(-1,-1,-1,-1)
X*Y=8
error
提示
 多组测试数据*/

#include <iostream>
using namespace std;

class Vector
{
public:
    Vector(int l) : len(l)
    {
        v = new double[len];
        for (int i = 0; i < len; i++)
        {
            v[i] = 0;
        }
    }
    ~Vector()
    {
        delete[] v;
        len = 0;
    }
    friend Vector operator+(const Vector &A, const Vector &B);
    friend Vector operator-(const Vector &A, const Vector &B);
    friend double operator*(const Vector &A, const Vector &B);
    // Vector& operator=(const Vector& A);
    friend bool same_len(const Vector &A, const Vector &B);
    friend ostream &operator<<(ostream &output, const Vector &A);
    friend istream &operator>>(istream &input, Vector &A);

private:
    double *v;
    int len;
};

Vector operator+(const Vector &A, const Vector &B)
{
    Vector Res(A.len);
    for (int i = 0; i < A.len; i++)
    {
        Res.v[i] = A.v[i] + B.v[i];
    }
    return Res;
}
Vector operator-(const Vector &A, const Vector &B)
{
    Vector Res(A.len);
    for (int i = 0; i < A.len; i++)
    {
        Res.v[i] = A.v[i] - B.v[i];
    }
    return Res;
}
double operator*(const Vector &A, const Vector &B)
{
    double res = 0;
    for (int i = 0; i < A.len; i++)
    {
        res += A.v[i] * B.v[i];
    }
    return res;
}
bool same_len(const Vector &A, const Vector &B)
{
    if (A.len == B.len)
        return 1;
    return 0;
}
istream &operator>>(istream &input, Vector &A)
{
    for (int i = 0; i < A.len; i++)
        input >> A.v[i];
    return input;
}

ostream &operator<<(ostream &output, const Vector &A)
{
    output << '(';
    for (int i = 0; i < A.len - 1; i++)
        output << A.v[i] << ',';
    output << A.v[A.len - 1] << ')' << endl;
    return output;
}

int main()
{
    int lenx, leny;
    while (cin >> lenx)
    {
        Vector X(lenx);
        cin >> X;
        cin >> leny;
        Vector Y(leny);
        cin >> Y;
        if (!same_len(X, Y))
        {
            cout << "error" << endl;
        }
        else
        {
            cout << "X=" << X;
            cout << "Y=" << Y;
            cout << "X+Y=" << (X + Y);
            cout << "X-Y=" << (X - Y);
            cout << "X*Y=" << (X * Y) << endl;
        }
    }
    return 0;
}