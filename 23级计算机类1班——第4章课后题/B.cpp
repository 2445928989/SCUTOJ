/*题目描述
输入产生 10 个互不相同的两位整数存放到一维数组中，并输出其中的素数。
输入
10个不同的两位整数
输出
其中存在的素数
样例输入 Copy
11 14 78 65 24 16 35 28 64 88
15 65 32 17 28 16 33 31 13 71
样例输出 Copy
11
17 31 13 71*/

#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;
int a[10];
int main()
{
    while (true) {
        for (int i = 0; i < 10; i++)cin >> a[i];
        for (int i = 0; i < 10; i++) {
            bool flag = 0;
            for (int j = 2; j * j <= a[i]; j++) {
                if (a[i] % j == 0) {
                    flag = 1;
                }
            }
            if (flag == 0)cout << a[i] << " ";
        }
        cout << endl;
    }
}
