/*题目描述
从键盘输入一个正整数，判别它是否为回文数。所谓回文数，是指正读和反读都一样的数。例如，123321 是回文数。
输入
一个正整数
输出
“是回文数”或者“不是回文数”
样例输入 Copy
56
565
5664
456654
样例输出 Copy
不是回文数
是回文数
不是回文数
是回文数*/

#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;
int n;
int main()
{
    while (cin>>n) {
        int a = n,x=0;
        while (n != 0) {
            n /= 10;
            x++;
        }
        int flag = 1;
        for (int i = 0; i < x/2; i++) {
            int p = pow(10, x-i-1);
            int q = pow(10, i);
            if (a / p % 10 != a / q % 10) {
                flag = 0;
                break;
            }
        }
        if (flag == 0)cout << "不是回文数" << endl;
        else cout << "是回文数" << endl;
    }
}//我觉得用字符串做会更快？
