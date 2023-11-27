/*题目描述
集合中的元素通常是字符。设计程序，用无符号整数表示 ASCII码表中的字符集合，用位运算实现各种基本集合运算（并集、交集、差集（第一个集合相对于第二个集合））。
输入
首先输入两个集合的长度，再输入两个集合的字符（在ASCII码表中的字符）
输出
两个集合运算的结果，包含3种运算。（首先是交集、然后是并集、最后是差集，每一行代表一个运算结果，数据间隔一个空格，具体样式详见示例）
样例输入 Copy
5 2
1 2 3 4 5
2 6
3 6
5 + -
* / 8 5 - &
样例输出 Copy
1 2 3 4 5 6
2
1 3 4 5
& * + - / 5 8
- 5
+*/

#include <iostream>
using namespace std;
int n, m;
char a;
void put(unsigned a, unsigned A[10]) {
    int i = 0;
    while (a >= 32) {
        a -= 32;
        i++;
    }
    unsigned bit = 1 << a;
    A[i] |= bit;
}
void show(unsigned A[10]) {
    for (int i = 0;i<10 ; i++) {
        unsigned bit = 1;
        for (int j = 0; j < 32; j++) {
            if (A[i] & bit) {
                cout << (char)(32 * i + j) << " ";
            }
            bit <<= 1;
        }
    }
    cout << endl;
}
unsigned A[10], B[10],C[10],D[10],E[10];
int main()
{
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> a;
            put((unsigned)a, A);
        }
        for (int i = 0; i < m; i++) {
            cin >> a;
            put((unsigned)a, B);
        }
        for (int i = 0; i < 10; i++) {
            C[i] = A[i] & B[i];
        }
        for (int i = 0; i < 10; i++) {
            D[i] = A[i] | B[i];
        }
        for (int i = 0; i < 10; i++) {
            E[i] = A[i] - C[i];
        }
        show(D);
        show(C);
        show(E);
        for (int i = 0; i < 5; i++) {
            A[i] = 0;
            B[i] = 0;
        }
    }
    system("pause");
}
