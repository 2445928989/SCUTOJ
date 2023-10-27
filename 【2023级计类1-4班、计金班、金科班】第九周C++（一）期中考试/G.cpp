/*题目描述
找出从4到N（N>=4），每隔2递减数列中所有素数（N,N-2,N-4……),素数从小到大排列。
输入
输入一个正整数N
输出
输出4～N的所有隔项素数，用空格隔开，如果没有，则输出None,每组数据分行输出。
样例输入 Copy
4
8
15
样例输出 Copy
None
None
5 7 11 13*/

#include<iostream>
using namespace std;
int main() {
    int N, N0;
    while (cin >> N) {
        int b = 0;
        if (N % 2 == 0) {
            N0 = 4;
        }
        else {
            N0 = 5;
        }
        for (int i = N0; i <= N; i += 2) {
            int a = 1;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    a = 0;
                    break;
                }
            }
            if (a == 1) {
                cout << i << " ";
                b = 1;
            }
        }
        if (b == 0)cout << "None";
        cout << endl;
    }
    system("pause");
}