/*题目描述
将一个三位数x交换个位和百位后得到新数y，设y-x=K,问当给定一个K值时，有多少满足这个条件的三位数，将它们全部输出，如果没有，输出None,以空格隔开，每组数据换行。
输入
K值，一个非负数
输出
所有符合条件的三位数。
样例输入 Copy
100
594
样例输出 Copy
None
107 117 127 137 147 157 167 177 187 197 208 218 228  238 248 258 268 278 288 298 309 319 329 339 349 359 369 379 389 399*/

#include<iostream>
using namespace std;
int main() {
    int K;
    while (cin >> K) {
        bool x = 0;
        for (int i = 100; i < 1000; i++) {
            int a = i / 100 % 10, b = i / 10 % 10, c = i % 10;
            if (a + b * 10 + c * 100 - i == K) {
                cout << i << " ";
                x = 1;
            }
        }
        if (x == 0)cout << "None";
        cout << endl;
    }
    system("pause");
}