/*题目描述
假设将从小到大排列的一组数据存放在一个数组中，在主函数中从键盘输入一个在该数组的最小值和最大值之间的数，并调用一个函数把输入的数插入原有的数组中，保持从小到大的顺序，并把最大值挤出。然后在主函数中输出改变后的数组。
注意，题目中数组的定义是：int a[] = { 10, 12, 23, 25, 48, 48, 53, 58, 60, 78 };

输入
一个整数（在最小值最大值之间）
输出
改变后的数组
样例输入 Copy
11
77
样例输出 Copy
10 11 12 23 25 48 48 53 58 60
10 12 23 25 48 48 53 58 60 77*/

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
    while (cin >> n) {
        int a[11] = { 10, 12, 23, 25, 48, 48, 53, 58, 60, 78,0 };
        a[10] = n;
        sort(a, a + 11);
        for (int i = 0; i < 10; i++)cout << a[i] << " ";
        cout << "\n";
    }
}
