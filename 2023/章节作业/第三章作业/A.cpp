/*题目描述
已知
y=(sh(1+shx))/(sh(2x)+sh(3x))
。sh(t)为双曲正弦函数，即
sh(t)=  (e^t- e^(-t))/2
。编写一个程序，输入x的值，求y的值。
输入
x的值
输出
y的值
样例输入 Copy
0.001
1
样例输出 Copy
235.349
0.318451*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double x, y;
    while (cin >> x) {
        y = sinh(1 + sinh(x)) / (sinh(2 * x) + sinh(3 * x));
        cout << y << endl;
    }
    return 0;
}
