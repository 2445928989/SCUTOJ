/*题目描述
给你一个正整数 n，找出满足下述条件的中枢整数x：
1和x之间的所有元素之和等于x和n之间所有元素之和。如果存在返回中枢整数x，不存在返回-1。1≤ n≤ 100000



例如
输入 8
1+2+3+4+5+6=6+7+8=21
输出 6


输入
输入正整数 n
输出
输出中枢整数 x，如果不存在输出-1。
样例输入 Copy
8
7
49
6
样例输出 Copy
6
-1
35
-1*/

#include<iostream>
using namespace std;
int main()
{
    int x;
    while (cin >> x) {
        bool a = 0;
        for (int i = 1; i <= x;i++) {
            int sum1 = (1 + i) * i / 2;
            int sum2 = (i + x) * (x - i+1) / 2;
            if (sum1 == sum2) {
                cout << i << endl;
                a = 1;
            }
        }
        if (a == 0) {
            cout << -1<<endl;
        }
    }
    system("pause");
    return 0;
}
