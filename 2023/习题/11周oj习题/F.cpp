/*题目描述
我们给出一种最简单的加密方法，给定一个字符串，把其中从a-y，A-Y的每个字符用其ASCII码反转得到的一个新的整数作为密文。为确保密文满足整数的常见形式（即：除0外，最高位数字不应该为0.），并能正确解密，如果字符的ASCII码反转得到的新的整数最高位为0，则密文为原始ASCII码。
例如：
字符A的ASCII码为97，密文为79；
字符N的ASCII码为110，密文为110；
输入
多组输入。每次输入一行，包含一个字符串，长度小于80个字符。
输出
对应多组输出。每次输出一行字符串加密后的密文，整数方式输出，每个密文间用单个空格分隔。
样例输入 Copy
AbCdEf
Fnx
样例输出 Copy
56 89 76 100 96 201
70 110 120
提示
多组测试用例，每组输出完成后注意换行*/

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
string str;
int a[100];
int main()
{
    while (cin >> str) {
        for (int i = 0; i < str.length(); i++) {
            a[i] = (int)str[i];
            if (a[i] % 10 != 0) {
                if (a[i] < 100)a[i] = (a[i] % 10) * 10 + (a[i] / 10);
                else a[i] = (a[i] % 10) * 100 + (a[i] / 100) + (a[i] / 10 % 10) * 10;
            }
            cout << a[i] << " ";
        }
        cout << endl;
 
 
    }
}
