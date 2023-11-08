/*题目描述
写一个合并函数，把两个升序排列的数组合井为一个升序数组。生成两个不等长有序数组测试合并函数。请分别用数组或vector类实现。
输入
两个数组的个数以及数组元素
输出
合并的升序数组元素（一个空格间隔）
样例输入 Copy
5 6
1 2 3 4 5 1 2 3 4 5 6
4 6
12 15 16 19 23 26 59 100 120 150
样例输出 Copy
1 1 2 2 3 3 4 4 5 5 6
12 15 16 19 23 26 59 100 120 150*/

#include<iostream>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
int m, n;
int a[1000000];
int main()
{
    while (cin >> m >> n) {
        for (int i = 0; i < m + n; i++)cin >> a[i];
        sort(a, a + m + n);
        for (int i = 0; i < m + n; i++)cout << a[i]<<" ";
        cout << endl;
    }
}//歪解。
