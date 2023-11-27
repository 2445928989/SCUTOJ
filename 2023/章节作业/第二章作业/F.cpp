/*题目描述
已知x=0°,10°,20，……,180°，求sinx、cosx和tanx的值（圆周率取3.14.15926）
输入
无
输出
题目中x所有取值对应的sinx，cosx，tanx 每一行为对应x的sinx，cons，tanx，用空格隔开,如：
0 1 0
0.173648 0.984808 0.176327
…….
5.35898e-08 -1 -5.35898e-08*/

#include<iostream>
#include<math.h>
using namespace std;
int main() {
    double pi = 3.1415926;
    for (double a = 0; a <= 1.01; a=a+double(1)/18) {
        cout << sin(a * pi) <<" " << cos(a * pi) << " " << tan(a * pi) << endl;
    }
    system("pause");
    return 0;
}
