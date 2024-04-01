/*题目描述
为第7章综合练习的程序设计第1题和第2题中的 Integer 类和 Real 类定义一个派生类IntReal。
class IntReal : public Integer, public Real;
使其可以进行+、-、*、/、=的左、右操作数类型不同的相容运算，并符合原有运算类型转换的语义规则。
给出main函数如下：
int main() {
    int m, n;
    double x, y;
    cin >> m >> n >> x >> y;
    IntReal a(m, x);
    IntReal b(n, y);

    IntReal sum = a + b;
    IntReal difference = a - b;
    IntReal product = a * b;
    IntReal quotient = a / b;

    cout << "Sum:" << int(sum) << " (Integer), " << double(sum) << " (Real)" << endl;
    cout << "Difference:" << int(difference) << " (Integer), " << double(difference) << " (Real)" << endl;
    cout << "Product:" << int(product) << " (Integer), " << double(product) << " (Real)" << endl;
    cout << "Quotient:" << int(quotient) << " (Integer), " << double(quotient) << " (Real)" << endl;

    return 0;
}
输入
四个数字，分别是两个整数，两个实数
输出
两个整数的和、差、积、商，两个实数的和、差、积、商。
示例如下：


注意之间的空格间隔

样例输入 Copy
5 4 4.5 5.6
样例输出 Copy
Sum:9 (Integer), 10.1 (Real)
Difference:1 (Integer), -1.1 (Real)
Product:20 (Integer), 25.2 (Real)
Quotient:1 (Integer), 0.803571 (Real)*/
#include <iostream>
using namespace std;
class Integer{
    protected:
        int a;
        public:
        Integer(int a){
            this->a = a;
        }
};
class Real{
    protected:
        double b;

    public:
        Real(double a)
        {
            this->b = a;
        }
};
class IntReal : public Integer, public Real
{
    public:
    operator int(){
        return a;
    }
    operator double()
    {
        return b;
    }
    IntReal(int a,double b) : Integer(a), Real(b){}
    IntReal friend operator+(IntReal A,IntReal B){
        IntReal t(A.a + B.a, A.b + B.b);
        return t;
    }
    IntReal friend operator-(IntReal A, IntReal B)
    {
        IntReal t(A.a - B.a, A.b - B.b);
        return t;
    }
    IntReal friend operator*(IntReal A, IntReal B)
    {
        IntReal t(A.a * B.a, A.b * B.b);
        return t;
    }
    IntReal friend operator/(IntReal A, IntReal B)
    {
        IntReal t(A.a / B.a, A.b / B.b);
        return t;
    }
};
int main()
{
    int m, n;
    double x, y;
    cin >> m >> n >> x >> y;
    IntReal a(m, x);
    IntReal b(n, y);

    IntReal sum = a + b;
    IntReal difference = a - b;
    IntReal product = a * b;
    IntReal quotient = a / b;

    cout << "Sum:" << int(sum) << " (Integer), " << double(sum) << " (Real)" << endl;
    cout << "Difference:" << int(difference) << " (Integer), " << double(difference) << " (Real)" << endl;
    cout << "Product:" << int(product) << " (Integer), " << double(product) << " (Real)" << endl;
    cout << "Quotient:" << int(quotient) << " (Integer), " << double(quotient) << " (Real)" << endl;

    return 0;
}