/*题目描述
将一组 C++关键字存放到一个 string 数组中，并找出这些关键字中的最小者。
输入
一个整数（代表即将输入的关键字个数），以及关键字
输出
最小的关键字
样例输入 Copy
5
while
int
double
if
for
3
int
char
if
样例输出 Copy
double
char*/

#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
string str[1000000];
int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }
        sort(str, str + n);
        cout << str[0] << endl;
    }
}
/*关于字符串的大小比较：
字符串比较大小时，会逐位比较ascii码的大小，比如说char和double
char的第一位是c，比double第一位的d小，所以char<double
如果相同则看下一位，比如说ab和ac
a和a一样，b比c小
所以ab<ac*/
