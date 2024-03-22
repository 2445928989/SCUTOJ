/*题目描述
定义一个类 nauticalmile_kilometer，它包含两个数据成员 kilometer（千米）和 meter（米）；还包含 一个构造函数对数据成员进行初始化；成员函数 print，用于输出数据成员 kilometer 和 meter 的值；类型转换函数operator double，实现把千米和米转换为海里（1 海里=1.852 千米）的功能。编写 main 函数，测试类 nauticalmile_kilometer。

输入
输入kilometer和meter。

输出
输出对应的海里(结果保留4位小数)。

必须使用的关键字
class
样例输入 Copy
100 50
样例输出 Copy
54.0227
提示
多组输入*/

#include <iostream>
#include <iomanip>

using namespace std;

class nauticalmile_kilometer
{
public:
    nauticalmile_kilometer(double k = 0, double m = 0)
        : kilometer(k), meter(m) {}
    void print()
    {
        cout << kilometer << ends << meter << endl;
    }
    operator double()
    {
        double t = double((kilometer * 1000 + meter)) / 1852;
        return t;
    }

private:
    double kilometer, meter;
};

int main()
{
    double a, b;
    while (cin >> a >> b)
    {
        nauticalmile_kilometer A(a, b);
        cout << fixed << setprecision(4) << double(A) << endl;
    }
    return 0;
}