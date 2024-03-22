/*题目描述
定义一个整数计算类 Integer，实现短整数+、-、*、/基本算术运算。要求：进行数据范围检查（-32768～32767），数据溢出时显示错误信息(Data Overflow!)。

输入
两个短整型数和对应选择的操作符(+, -, *, /)。
输出
相应的计算结果

必须使用的关键字
class
样例输入 Copy
30 90 +
12626 595 *
样例输出 Copy
120
Data Overflow!
提示
 多组测试数据*/

#include <iostream>
using namespace std;
class Integer
{
    int A;

public:
    Integer(int a, int b, char c)
    {
        if (c == '+')
            A = a + b;
        if (c == '-')
            A = a - b;
        if (c == '*')
            A = a * b;
        if (c == '/')
            A = a / b;
    }
    void display()
    {
        if (A > 32767 || A < -32768)
            cout << "Data Overflow!\n";
        else
            cout << A << endl;
    }
};
int main()
{
    int a, b;
    char c;
    while (cin >> a >> b >> c)
    {
        Integer A(a, b, c);
        A.display();
    }
}