/*题目描述
使用迭代公式xn+1=(xn+a/xn)/2 (n=0,1,2,…,x0=a/2)编程求某个正整数a的平方根，要求前后两次求出的x差的绝对值小于10-8


输入
一个正整数
输出
该正整数的平方根
样例输入 Copy
16
2
样例输出 Copy
4
1.41421*/

#include<iostream>
using namespace std;
int main() {
    double a,x,y;
    while (cin >> a) {
        x = a / 2;
        while (true) {
            y = (x + a / x)/2;
            if (abs(y - x) > 10e-8) {
                x = y;
            }
            else {
                cout << y << endl;
                break;
            }
        }
 
    }
}
