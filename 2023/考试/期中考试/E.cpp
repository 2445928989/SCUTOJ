/*题目描述
素数是指大于1且除了1和它本身以外不再有其他因数的自然数。回文数是指正读和反读一样的自然数。例如，121，1221，1223221等都是回文数。输入任意两个整数m和n, 输出m和n之间的素回文数，如果没有，则输出“无”。
输入
两个整数m和n
输出
m和n之间存在的素回文数，从小到大输出。
没有的话输出“无”

样例输入 Copy
5 500
9 10
样例输出 Copy
5
7
11
101
131
151
181
191
313
353
373
383
无*/

#include<iostream>
#include<math.h>
using namespace std;
int huiwenshu(int a) {
    int weishu=0,b,c;
    for (int i = 0;; i++) {
        if (a / (int)pow(10, i) == 0) {
            weishu = i-1;
            break;
        }
    }
    for (int i = 0; i <= weishu / 2; i++) {
        b = pow(10, i);
        c = pow(10, weishu - i);
        if (a / b % 10 != a / c % 10) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int m, n;
    while (cin >> m >> n) {
        int b = 0;
        for (int i = m; i <= n; i++) {
            int a = 1;
            if (huiwenshu(i) == 1) {
                for (int j = 2; j < i; j++) {
                    if (i % j == 0) { 
                        a = 0;
                        break;
                    }
                }
                if (a == 1) { 
                    cout << i << endl; 
                    b = 1;
                }
            }   
        }
        if (b == 0)cout << "无" << endl;
    }
    system("pause");
    return 0;
}