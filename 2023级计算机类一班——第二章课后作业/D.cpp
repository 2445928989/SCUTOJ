/*题目描述
输入一个整数，输出该整数的所有素数因子。例如，输入 120，输出为 2 2 2 3 5，以空格间隔
输入
一个整数
输出
该整数的所有素数因子，以空格间隔
样例输入 Copy
120
样例输出 Copy
2 2 2 3 5*/

#include<iostream>
using namespace std;
int main() {
     
 
    int num;
    while (cin >> num) {
        for (int i = 2; i <= num; ) {
            if (num % i == 0) {
                num = num / i;
                cout << i << " ";
            }
            else i++;
        }
        cout << endl;
    }
}
