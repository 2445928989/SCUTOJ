/*题目描述
关于自然常数e有许多有趣的结果，例如e等于表达式(1+1/n)^n在n趋于无穷时的极限，又例如e等于表达式1+1/1!+1/2!+…+1/n!在n趋于无穷时的极限（n!为n的阶乘，即n*(n-1)*(n-2)…*3*2*1），请根据输入的正整数n，计算上述两种表达式的比值，即((1+1/n)^n)/( 1+1/1!+1/2!+…+1/n!)，比值精确到4位小数。
输入
多组输入，每行一个正整数n
输出
按行输出上述比值，精确到4位小数
样例输入 Copy
1
4
5
8
9
19
99
999
999999
样例输出 Copy
1.0000
0.9014
0.9159
0.9439
0.9496
0.9749
0.9950
0.9995
1.0000*/

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int n;
int main() {
    while (cin >>n) {
        double sum1 = 0, sum2 = 1,temp=1;
        sum1 = pow((1 + 1.0 / n), n);
        for (int i = 1; i <= n; i++) {
            temp = temp / i;
            sum2 += temp;
        }
        cout << fixed << setprecision(4) << sum1 / sum2 << endl;
    }
    system("pause");
}
