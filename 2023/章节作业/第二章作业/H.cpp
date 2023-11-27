/*题目描述
求 1000以内的所有完数。所谓完数，是指一个数恰好等于它的所有因子之和。例如因为 6=1+2+3。所以6为完数
输入
无
输出
所有的完数，如：
6
28
……*/

#include<iostream>
using namespace std;
int main() {
    int num=2,x=0;
    while (num<1000) {
        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                x += i;
            }
        }
        if (num == x) {
            cout << x << endl;
        }
        x = 0;
        num++;
    }
    system("pause");
    return 0;
}
