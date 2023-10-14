/*题目描述
编写一个程序，它能够读入一个正方形的边长(1~20)，然后打印一个由星号和空格组成的空心正方形。例如，程序读入边长是 5，则输出的空心正方形为:

输入
边长n
输出
对应的空心正方形
样例输入 Copy
3
样例输出 Copy
* * * 
*   *
* * * */

#include<iostream>
using namespace std;
int main() {
    int x;
    while (cin >> x) {
        for (int i = x; i > 0; i--) {
            cout << "* ";
        }
        cout << endl;
        for (int i = x - 2; i > 0; i--) {
            cout << "* ";
            for (int j = x - 2; j > 0; j--) {
                cout << "  ";
            }
            cout << "*" << endl;
        }
        for (int i = x; i > 0; i--) {
            cout << "* ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
