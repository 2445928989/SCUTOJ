/*题目描述
定义人民币类 RMB，包含：
私有数据成员：
int yuan（元）、int jiao（角）、int fen（分）、bool mark（标志，表示正、负数）
成员函数：
用（元，角，分，标志）构造 RMB 对象
用 double 数据构造 RMB 对象
类型转换，把 RMB 对象转换为 double 值
友元函数：
重载<<，以“元角分”形式输出 RMB 对象值
重载>>，以“元角分”形式输入 RMB 对象值
以下是main 函数(仅提供参考)的测试和运行显示。请补充 RMB 类的定义。
int main(){
       RMB a, b;
       double c;
       while(cin >> a){
            //cout <<"b:\n";
            cin >> b;
            //cout <<"c:\n";
            cin >> c;
            cout << "a = "<< a << "b = " << b << "c = " << RMB(c);
            cout << "a + c = " << RMB(a + c);
            cout << "a - b = " << RMB(a - b);
            cout << "b * 2 = " << RMB(b * 2);
            cout << "a * 0.5 = " << RMB(a * 0.5) ;
     }
     return 0;
}
输入
人民币类的对象a,b的元、角、分；以及c(是一个double类型数据)。

输出
根据题目中的main函数，输出相应的计算结果(提示：当mark为负数时，输出形式为-x元x角x分)。

必须使用的关键字
class
样例输入 Copy
2 2 2
1 1 1
2.5
样例输出 Copy
a = 2Y2J2F
b = 1Y1J1F
c = 2Y5J0F
a + c = 4Y7J2F
a - b = 1Y1J1F
b * 2 = 2Y2J2F
a * 0.5 = 1Y1J1F*/

#include <iostream>
using namespace std;
class RMB
{
    int yuan, jiao, fen;
    bool mark;

public:
    RMB() {}
    RMB(int a, int b, int c, bool d)
    {
        yuan = a;
        jiao = b;
        fen = c;
        mark = d;
    }
    RMB(double B)
    {
        if (B < 0)
            mark = 1;
        else
            mark = 0;
        B = abs(B);
        B *= 100;
        yuan = B / 100;
        B -= 100 * yuan;
        jiao = B / 10;
        B -= 10 * jiao;
        fen = B;
    }
    operator double()
    {
        double t = yuan + 0.1 * jiao + 0.01 * fen;
        if (mark)
            t = -t;
        return t;
    }
    friend istream &operator>>(istream &cin, RMB &A);
    friend ostream &operator<<(ostream &cout, const RMB A);
};
istream &operator>>(istream &cin, RMB &A)
{
    cin >> A.yuan >> A.jiao >> A.fen;
    A.mark = 0;
    return cin;
}
ostream &operator<<(ostream &cout, const RMB A)
{
    if (A.mark)
        cout << '-';
    cout << A.yuan << "Y" << A.jiao << "J" << A.fen << "F" << endl;
    return cout;
}
int main()
{
    RMB a, b;
    double c;
    while (cin >> a)
    {
        // cout <<"b:\n";
        cin >> b;
        // cout <<"c:\n";
        cin >> c;
        cout << "a = " << a << "b = " << b << "c = " << RMB(c);
        cout << "a + c = " << RMB(a + c);
        cout << "a - b = " << RMB(a - b);
        cout << "b * 2 = " << RMB(b * 2);
        cout << "a * 0.5 = " << RMB(a * 0.5);
    }
    return 0;
}