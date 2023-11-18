/*题目描述
整数左移一位相当于将该数乘以 2。编写一个函数:
unsigned power2( unsigned number, unsigned pow );
使用移位运算计算 numberX2pow，并以整数形式输出计算结果。注意考虑数据的溢出。
输入
一个整数（空格间隔）一个代表左移几位的整数
输出
移位之后的运算结果
样例输入 Copy
2 5
2 1
65 2
样例输出 Copy
64
4
260
提示
注意使用无符号整数*/

#include<iostream>
#include<bitset>
using namespace std;
unsigned power2(unsigned number, unsigned pow) {
    number <<= pow;
    return number;
}
int main() {
    unsigned num,pow;
    while (cin >> num>>pow) {
        cout << power2(num, pow)<<endl;
    }
}
