/*题目描述
一个正整数，如果它能被7整除，或者它的十进制表示法中某一位上的数字为7，则称其为与7相关的数，否则称其为与7无关的数。现给一个正整数n（n <=100），如果n是与7无关的数，则输出n的平方，否则，输出n。
输入
多组输入。每组一行，每行输入一个整数n（n <= 100）。
输出
每组一个整数作为输出。
样例输入 Copy
28
22
17
33
78
样例输出 Copy
28
484
17
1089
78*/

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int k;
    while (cin >> k) {
        bool flag = 0;
        if (k % 7 == 0) {
            flag = 1;
        }
        int n = k;
        while (k != 0) {
            if (k % 10 == 7) {
                flag = 1;
                break;
            }
            k /= 10;
        }
        if (flag == 1)cout << n << endl;
        else cout << n * n << endl;
    }
    return 0;
}
