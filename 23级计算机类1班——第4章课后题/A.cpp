/*己知计算成绩的平均值和均方差公式分别为：，式中，n为学生人数，Si为第i个学生的成绩。求某班学生的平均成绩和均方差。
输入
学生人数n，n个学生的成绩（double类型）
输出
平均成绩和均方差（中间间隔一个空格）
样例输入 Copy
5
1 2 3 4 5
10
1 1 1 1 1 1 1 1 1 1
10
99 98 95 96 95 94 91 89 85 99
样例输出 Copy
3 1.41421
1 0
94.1 4.32319*/

//图又没了。

#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;
double n;
double a[1000000];
int main()
{
    while (cin >> n) {
        double ave = 0,dev=0;
        for (int i = 0; i < n; i++)cin >> a[i];
        for (int i = 0; i < n; i++)ave += a[i];
        ave /= n;
        for (int i = 0; i < n; i++)dev += pow(a[i] - ave, 2) / n;
        cout<< ave << " " << sqrt(dev)<<endl;
    }
}
