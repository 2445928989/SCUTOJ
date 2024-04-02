/*题目描述
使用 Integer类，定义派生类 Vector 类:
class Integer
{//…
protected
int n;
};
class Vector:public Integer{//…
protected :
int *v:
};
其中，数据成员v用于建立向量，n为向量长度。要求:类的成员函数可以实现向量的基本运算。
给出main函数如下：
int main() {
    int length;
    cin >> length;
    Vector v1(length);
    Vector v2(length);
    cout << v1 << endl;
    cout << v2 << endl;

    Vector v = v1 + v2;
    cout << "sum:" << endl;
    cout << v << endl;

    v = v1 - v2;
    cout << "differenct:" << endl;
    cout << v << endl;

    v = v1 * v2;
    cout << "product:" << endl;
    cout << v << endl;

    v = v1 / v2;
    cout << "quotient:" << endl;
    cout << v << endl;

    return 0;
}
输入
向量的长度
输出
计算后的值


样例输入 Copy
2
样例输出 Copy
1 1
1 1
sum:
2 2
differenct:
0 0
product:
1 1
quotient:
1 1*/
#include <iostream>
using namespace std;
class Vector
{
    int *a;
    int len;

public:
    Vector(int x)
    {
        this->len = x;
        a = new int[x];
        for (int i = 0; i < x; i++)
        {
            a[i] = 1;
        }
    }
    friend ostream &operator<<(ostream &cout, Vector T)
    {
        for (int i = 0; i < T.len; i++)
        {
            cout << T.a[i] << " ";
        }
        return cout;
    }
    friend Vector operator+(Vector A, Vector B)
    {
        Vector T(A.len);
        for (int i = 0; i < T.len; i++)
        {
            T.a[i] = A.a[i] + B.a[i];
        }
        return T;
    }
    friend Vector operator-(Vector A, Vector B)
    {
        Vector T(A.len);
        for (int i = 0; i < T.len; i++)
        {
            T.a[i] = A.a[i] - B.a[i];
        }
        return T;
    }
    friend Vector operator*(Vector A, Vector B)
    {
        Vector T(A.len);
        for (int i = 0; i < T.len; i++)
        {
            T.a[i] = A.a[i] * B.a[i];
        }
        return T;
    }
    friend Vector operator/(Vector A, Vector B)
    {
        Vector T(A.len);
        for (int i = 0; i < T.len; i++)
        {
            T.a[i] = A.a[i] / B.a[i];
        }
        return T;
    }
};
int main()
{
    int length;
    cin >> length;
    Vector v1(length);
    Vector v2(length);
    cout << v1 << endl;
    cout << v2 << endl;

    Vector v = v1 + v2;
    cout << "sum:" << endl;
    cout << v << endl;

    v = v1 - v2;
    cout << "differenct:" << endl;
    cout << v << endl;

    v = v1 * v2;
    cout << "product:" << endl;
    cout << v << endl;

    v = v1 / v2;
    cout << "quotient:" << endl;
    cout << v << endl;

    return 0;
}