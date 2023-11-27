/*题目描述
输入一个表示星期几的数，然后输出相应的英文单词。要求：使用指针数组实现
输入
一个整数，表示星期几
输出
输入对应的英文单词
样例输入 Copy
1
3
样例输出 Copy
monday
wednesday*/

#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
string str[7] = { "monday","tuesday","wednesday", "thursday", "friday", "saturday", "sunday" };
string* strp[7];
int main() {
    for (int i = 0; i < 7; i++)strp[i] = &str[i];
    while (cin >> n) {
        n--;
        cout << *strp[n] << endl;
    }
}
