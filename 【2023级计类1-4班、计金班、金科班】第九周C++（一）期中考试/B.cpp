/*题目描述
给你一个正整数x，请你将它按照位分割成两个非负整数 x1和 x2，满足：x1和x2的和最小，上述得到的整数没有前导 0。10 ≤ x  ≤  1 000 000 000，超出范围的输出 -1。
输入
正整数 x
4325 
输出
最小分割和
68
解释： 43+25 = 68
样例输入 Copy
4325
10234
1000000001
样例输出 Copy
68
136
-1
提示
循环输入 while(cin >> x) {}
x,x1,x2 没有前导0。例如： 00123=123。*/

#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
    int a, arr[10] = { 0 }, b, c;
    while (cin >> a) {
        int min = 99999999999999;
        if (a > 1000000000 || a < 10) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i <= 9; i++) {
            b = pow(10, 9-i);
            arr[i] = a / b%10;
        }
        for (int i = 0; i < 9; i++) {
            int num1=0, num2=0;
            for (int j = 9; j > i; j--) {
                num2 += arr[j] * pow(10, 9 - j);
            }
            for (int k = i; k >= 0; k--) {
                num1 += arr[k] * pow(10, i - k);
            }
            if (min > num1 + num2)min = num1 + num2;
        }
        cout << min << endl;
    }
    system("pause");
    return 0;
}