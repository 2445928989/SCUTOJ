/*题目描述
输入平面上某点横坐标x和纵坐标y，若该点在如图所示的方块区域内(中心点在坐标原点，边长为4)，则输出true；否则，输出false。


输入
两个浮点数：平面上点的坐标x，y
输出
true或者false
样例输入 Copy
0.1 2.0
-1.5 1.0
4.78 -2.3
样例输出 Copy
true
true
false*/

#include <iostream>
using namespace std;
int main()
{
    float x, y;
    while (cin >> x >> y) {
        x <= 2.0 && y <= 2.0 && x >= -2.0 && y >= -2.0 ? cout << "true\n" : cout << "false\n";
    }
    system("pause");
    return 0;
}
