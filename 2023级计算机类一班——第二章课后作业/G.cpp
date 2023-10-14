/*题目描述
求 100~999之间的水仙花数。所谓水仙花数，是指一个三位数，它的每位数字的立方之和等于该数。例如，因为153=13+53+33，所以153为水仙花数。
输入
无
输出
所有的水仙花数，如
153
370
......*/

#include<iostream>
using namespace std;
int main() {
    for (int num = 100; num < 1000; num++) {
        if (num == (num / 100)*(num / 100)*(num / 100) + (num / 10 % 10)*(num / 10 % 10)*(num / 10 % 10) + (num % 10)*(num % 10)*(num % 10)) {
            cout<<num<<endl;
        }
    }
system("pause");
    return 0;
}
