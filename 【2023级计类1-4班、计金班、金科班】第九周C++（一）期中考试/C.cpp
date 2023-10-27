/*题目描述
一辆长度为L米的火车匀速(v=10m/s)通过长度为D米的隧道时，当火车进入隧道的时间为t秒时,火车在隧道内的长度M是多少米

输入
输入火车长度L米，隧道长度D米，进入隧道的时间为t秒

0 < L <= 500
0 < D <= 1000
0 <= t <= 200

输出
输出火车在隧道内的长度M米

样例输入 Copy
100.0 200.0 2.0
100.0 200.0 15.0
100.0 200.0 30.0
200.0 90.5 12.0
200.0 100.0 21.2
样例输出 Copy
20
100
0
90.5
88*/

#include<iostream>
using namespace std;
int main() {
    double L, D, t;
    while (cin >> L >> D >> t) {
        if (L > D) {
            if (t >= (L + D) / 10)cout << 0 << endl;
            if (t >= D / 10 && t <= L / 10)cout << D << endl;
            if (t <= D / 10)cout << 10 * t << endl;
            if (t >= L / 10 && t <= (L + D) / 10)cout << D - 10 * t + L << endl;
        }
        if (L <= D) {
            if (t >= (L + D) / 10) cout << 0 << endl;
            if (t <= L / 10)cout << 10 * t << endl;
            if (t > L / 10 && t < (L + D) / 10)cout << L << endl;
        }
    }
    system("pause");
}